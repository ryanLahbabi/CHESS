// Cette classe permet de configurer l'echiquier que vous voulons afficher, nous avons fais en sorte d'afficher les cases en vert et gris foncé.
//Aussi nous avons reglé la taille des cases et de l'échiquier à l'aide des outils QT.
// De plus nous avons pu afficher les images des pièces dans les ressources à des positions bien determiner sur l'échiquier afin que l'interface satisfait les règles du  jeu d'échec.
#include "affichage.h"


modele::Affichage::Affichage()
{
    QObject::connect(&jeu, SIGNAL(envoyerSignal(QString)), this, SLOT(getSignal(QString)));
    afficherJeu = new QGraphicsScene();
    debut();
    piecesPlacer();
    couleur = BLANC;
}

void modele::Affichage::debut()
{
    int j = 0;
    int k = 0;
    bool couleur = false;
    for(int i=0; i<64; i++)
    {
        QString nomCase = numeroCase[i];
        Regle* r = new Regle(j,k);
        r->setRect(j,k,75,75);
        if (i % 8 == 0)
        {
            couleur = !couleur;
        }
         if (couleur)
        {
            r->setBrush(Qt::darkGreen);
        }
         else
             r->setBrush(Qt::darkGray);
        couleur = !couleur;
         r->setNomPiece(nomCase);
         ListeDePiece.append(r);
         afficherJeu->addItem(r);
        QObject::connect(r, SIGNAL(envoyerMessage(QString)), &jeu, SLOT(getEntree(QString)));
        j += 75;
        if (j == 600)
        {
            j = 0;
            k += 75;
        }
    }



  QGraphicsTextItem * match = new QGraphicsTextItem();

  match->setPos(425, 0);
  afficherJeu->addItem(match);
  tourJoueur = new QGraphicsTextItem();
  tourJoueur->setPos(425, 100);
  afficherJeu->addItem(tourJoueur);
  verification = new QGraphicsTextItem();
  verification->setPos(425, 200);
  afficherJeu->addItem(verification);
}

void modele::Affichage::piecesPlacer()
{
    ListeDePiece[0]->setPng(":/piece/tourNoir.png");
    ListeDePiece[1]->setPng(":/piece/cavalierNoir.png");
    ListeDePiece[2]->setPng(":/piece/fouNoir.png");
    ListeDePiece[3]->setPng(":/piece/reineNoir.png");
    ListeDePiece[4]->setPng(":/piece/roiNoir.png");
    ListeDePiece[5]->setPng(":/piece/fouNoir.png");
    ListeDePiece[6]->setPng(":/piece/cavalierNoir.png");
    ListeDePiece[7]->setPng(":/piece/tourNoir.png");
    ListeDePiece[8]->setPng(":/piece/pionNoir.png");
    ListeDePiece[9]->setPng(":/piece/pionNoir.png");
    ListeDePiece[10]->setPng(":/piece/pionNoir.png");
    ListeDePiece[11]->setPng(":/piece/pionNoir.png");
    ListeDePiece[12]->setPng(":/piece/pionNoir.png");
    ListeDePiece[13]->setPng(":/piece/pionNoir.png");
    ListeDePiece[14]->setPng(":/piece/pionNoir.png");
    ListeDePiece[15]->setPng(":/piece/pionNoir.png");

    ListeDePiece[48]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[49]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[50]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[51]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[52]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[53]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[54]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[55]->setPng(":/piece/pionBlanc.png");
    ListeDePiece[56]->setPng(":/piece/tourBlanche.png");
    ListeDePiece[57]->setPng(":/piece/cavalierBlanc.png");
    ListeDePiece[58]->setPng(":/piece/fouBlanc.png");
    ListeDePiece[59]->setPng(":/piece/reineBlanche.png");
    ListeDePiece[60]->setPng(":/piece/roiBlanc.png");
    ListeDePiece[61]->setPng(":/piece/fouBlanc.png");
    ListeDePiece[62]->setPng(":/piece/cavalierBlanc.png");
    ListeDePiece[63]->setPng(":/piece/tourBlanche.png");
}


QGraphicsScene* modele::Affichage::getGraphique()
{
     return afficherJeu;
}


//Avoir une reponse du jeu et changer l image de la piece sur la case de l'echiquier


void modele::Affichage::getSignal(QString signal)
{
    string responseString = signal.toStdString();

    if (responseString.compare("Ecehc") == 0)
    {
        qDebug() << "Echec";
        verification->setPlainText("Echec!");
    }
    else
    {
        verification->setPlainText("Rien à signaler");
    }

    // Si la réponse est invalide il faut que le programme ignore la commande
    if (responseString.compare("Mouvement Interdit") == 0)
    {
        qDebug() << "Mouvement Interdit";
        return;
    }
    else if (responseString.compare("Echec et mat") == 0)
    {
        qDebug() << "Echec et mat";
        verification->setPlainText("Echec et mat");
        return;
    }
    else if (responseString.compare("Match nul") == 0)
    {
        qDebug() << "Match nul";
        verification->setPlainText("Match nul");
        return;
    }


        else
        {
            QString premierEspace = "";
            QString deuxiemeEspace = "";
            premierEspace += signal[0];
            premierEspace += signal[1];
            deuxiemeEspace += signal[2];
            deuxiemeEspace+= signal[3];

            QString temp;
            for (int i=0; i<ListeDePiece.length(); i++ )
            {
                if (ListeDePiece[i]->getNomPiece() == premierEspace)
                {
                    temp = ListeDePiece[i]->getPng();
                    ListeDePiece[i]->clearPng();
                }
            }
            for (int i=0; i<ListeDePiece.length(); i++ )
            {
                if (ListeDePiece[i]->getNomPiece() == deuxiemeEspace)
                {
                    ListeDePiece[i]->setPng(temp);
                }
            }
        }

        if (couleur == NOIR)
        {
            couleur = BLANC;
            tourJoueur->setPlainText("Tour des blancs");
        }
        else
        {
            couleur = NOIR;
            tourJoueur->setPlainText("Tour des Noirs");
        }
 }



