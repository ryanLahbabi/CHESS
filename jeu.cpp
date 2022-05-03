#include <sstream>
#include "jeu.h"
#include <vector>
#include <string>
using namespace std;

void modele::Jeu::demarrer()
{
    string entree;
    int count = 1;
    bool couleur = getTour(count);

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
               couleur = getTour(count);


           continue;
       }

       if (echequier_.mouvementPiece(init, finale))
       {
           if (estEnEchec(couleur))
           {
              continue;
           }
           else
           {
               count++;
               couleur = getTour(count);
           }
       }
    }

}
bool modele::Jeu::estEnEchec(bool couleur) const
{
    bool couleurAdverse = true;
    if (couleur)
    {
        couleurAdverse = false;
    }

    pair<int,int> coordoneeRoi = echequier_.getRoi(couleur);
    vector<pair<int,int>> coordoneePiece = echequier_.getCoordoneePiece(couleurAdverse);

    for (auto adversite : coordoneePiece)
    {
        if (echequier_.mouvementValide(adversite, coordoneeRoi))
        {
            return true;
        }
    }
    return false;
}
bool modele::Jeu::estEnEchecEtMat(bool couleur)
{
    if (estEnEchec(couleur))
    {
        vector<pair<int,int>> coordoneePiece = echequier_.getCoordoneePiece(couleur);
        vector<pair<int,int>> coordonee = echequier_.getCoordonee();

        for (auto &cPiece : coordoneePiece)
        {
            for (auto &c : coordonee)
            {
                if (echequier_.mouvementPiece(cPiece, c))
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
bool modele::Jeu::estMatchNul(bool couleur){
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
                    if (echequier_.mouvementPiece(cPiece, c))
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
bool modele::Jeu::getTour(int i) const
{
    if (i % 2 == 1)
    {
        return true;
    }
    return false;
}
void modele::Jeu::switchGuiTurn()
{
   tour_ = !tour_;
}
void modele::Jeu::refaireMouvement()
{
    mouvement1_ = "";
    mouvement2_ = "";
}
bool modele::Jeu::bouger(std::pair<int,int> coordoneeInit, std::pair<int,int> coordoneeFinale)
{
    return echequier_.mouvementPiece(coordoneeInit, coordoneeFinale);
}
void modele::Jeu::afficherEchiquier()
{
    echequier_.afficher();
}


