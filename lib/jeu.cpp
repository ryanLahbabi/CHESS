#include <sstream>
#include "jeu.h"
#include <vector>
#include <string>
using namespace std;

void modele::Jeu::demarrer()
{
    string entree;
    int count = 1;
    Couleur couleur = getChangerCouleur(count);

    while (true)
    {
       afficherEchiquier();

       string str1;
       stringstream str2(entree);

       vector<string> vec1;

       while (str2 >> str1)
       {
           vec1.push_back(str1);
       }

       int colonne = vec1[0][0] - 'a';
       int ligne = 8 - (vec1[0][1] - '0');
       pair<int,int> init = make_pair(colonne, ligne);

       colonne = vec1[1][0] - 'a';
       ligne = 8  - (vec1[1][1] - '0');
       pair<int,int> finale = make_pair(colonne, ligne);

       if (echequier_.getPiece(init) == nullptr)
       {
           continue;
       }
       if (echequier_.getPiece(init)->getCouleur() != couleur)
       {
           continue;
       }

       if (echequier_.getPiece(init)->getTypePiece() == ROI && echequier_.distance(init, finale)> 1)
       {

               count++;
               couleur = getChangerCouleur(count);


           continue;
       }

       if (echequier_.mouvementLegal(init, finale))
       {
           if (estEnEchec(couleur))
           {
              continue;
           }
           else
           {
               count++;
               couleur = getChangerCouleur(count);
           }
       }
    }

}


string modele::Jeu::afficherCouleur(modele::Couleur couleur)
{
    if (couleur)
    {
        return "White";
    }
        return "Black";
}
bool modele::Jeu::estEnEchec(modele::Couleur couleur) const
{
    modele::Couleur couleurAdverse;
    if (couleur == BLANC)
        couleurAdverse = NOIR;
    else
        couleurAdverse = BLANC;


    pair<int,int> coordoneeRoi = echequier_.getCoordoneeRoi(couleur);
    vector<pair<int,int>> coordoneePiece = echequier_.getCoordoneePiece(couleurAdverse);

    for (auto adversite : coordoneePiece)
    {
        if (echequier_.mouvementLegal(adversite, coordoneeRoi))
        {
            return true;
        }
    }
    return false;
}
bool modele::Jeu::estEnEchecEtMat(modele::Couleur couleur)
{
    if (estEnEchec(couleur))
    {
        vector<pair<int,int>> coordoneePiece = echequier_.getCoordoneePiece(couleur);
        vector<pair<int,int>> coordonee = echequier_.getCoordonee();

        for (auto &cPiece : coordoneePiece)
        {
            for (auto &c : coordonee)
            {
                if (echequier_.mouvementLegal(cPiece, c))
                {
                    if (estEnEchec(couleur) == false)
                    {
                        return false;
                    }
                }
            }
        }

    }
    else
    {
        return false;
    }
    return true;
}
bool modele::Jeu::estMatchNul(modele::Couleur couleur){
    if (estEnEchec(couleur))
    {
        return false;
    }
    else
        {
            vector<pair<int,int>> coordoneePiece = echequier_.getCoordoneePiece(couleur);
            vector<pair<int,int>> coordonee = echequier_.getCoordonee();

            for (auto &cPiece : coordoneePiece)
            {
                for (auto &c : coordonee)
                {
                    if (echequier_.mouvementLegal(cPiece, c))
                    {

                        if (estEnEchec(couleur) == false)
                        {

                            return false;
                        }
                    }
                }
            }
        }
        return true;
}

modele::Couleur modele::Jeu::getChangerCouleur(int nombreMouvement) const
{
    if (nombreMouvement % 2 == 1)
    {
        return BLANC;
    }
    else
    {
        return NOIR;
    }
}
void modele::Jeu::refaireMouvement()
{
    mouvement1_ = "";
    mouvement2_ = "";
}
bool modele::Jeu::bouger(std::pair<int,int> coordoneeInit, std::pair<int,int> coordoneeFinale)
{
    return echequier_.mouvementLegal(coordoneeInit, coordoneeFinale);
}
void modele::Jeu::afficherEchiquier()
{
    echequier_.afficher();
}

void modele::Jeu::getEntree(QString entree)
{
    qDebug() << "Game saw that " << entree << "was clicked, and will now respond.";

    // If this is the first click, store it in move1
    if (mouvement1_ == "")
    {
        mouvement1_ = entree.toStdString();
    }
    // If this is the second click, store it in move2
    else
    {
        mouvement2_ = entree.toStdString();


        // We can now pass the move to the Game
        int colonne = mouvement1_[0] - 'a';
        int ligne = 8 - (mouvement1_[1] - '0');
        pair<int, int> init = make_pair(ligne,colonne);

        colonne = mouvement2_[0] - 'a';
        ligne = 8 - (mouvement2_[1] - '0');

        pair<int, int> finale = make_pair(ligne,colonne);		// convert substring to pair

        // Verify that a piece was selected
        if (echequier_.getPiece(init) == nullptr)
        {
            envoyerSignal("Invalid Move");
            refaireMouvement();
            return;
        }

        if (echequier_.getPiece(init)->getCouleur() != changerCouleur_)
        {
            std::cout << "Error: It's " << afficherCouleur(changerCouleur_) << "'s turn." << '\n';

            emit envoyerSignal("Invalid Move");
            refaireMouvement();

            return;
        }


        if (echequier_.bougerPiece(init, finale))
        {
            if (estEnEchec(changerCouleur_))
            {
                cout << "Error: This leaves " << afficherCouleur(changerCouleur_) << " in check.\n";
                //qDebug() << "Error: This leaves you in check.";
                echequier_.inverserMouvement();
                envoyerSignal("Invalid Move");
            }
            // If the move was valid, switch turns and send "Valid" response
            else
            {
                //changerCouleur();

                QString sendStr = "";
                QString part1 = QString::fromStdString(mouvement1_);
                QString part2 = QString::fromStdString(mouvement2_);
                sendStr += part1;
                sendStr += part2;
                envoyerSignal(sendStr);
            }
        }
        else
        {
            std::cout << "Error: Invalid move.\n";
           // qDebug() << "Error: Invalid move.";
            envoyerSignal("Invalid Move");
        }

        refaireMouvement();
    }

}

