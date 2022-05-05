#include "affichage.h"


modele::Affichage::Affichage()
{
    QObject::connect(&jeu, SIGNAL(envoyerMessage(QString)), this, SLOT(getSignal(QString)));
    afficherJeu = new QGraphicsScene();
    debut();
    piecesPlacer();
    couleur = true;
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
        QObject::connect(r, SIGNAL(sendSignal(QString)), &jeu, SLOT(getInput(QString)));
        j += 75;
        if (j == 600)
        {
            j = 0;
            k += 75;
        }
    }
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


//Avoir une reponse du jeu et changer l image de la piece sur
//la case de l'Ã©chiquier


void modele::Affichage::getSignal(QString signal)
{
    string responseString = signal.toStdString();

    if (responseString.compare("Check") == 0)
    {
        qDebug() << "Check";
        verification->setPlainText("Check!");
    }
    else
    {
        verification->setPlainText("");
    }

    // If response was "Invalid Move", ignore it
    if (responseString.compare("Invalid Move") == 0)
    {
        qDebug() << "Invalid Move";
        return;
    }
    else if (responseString.compare("Checkmate") == 0)
    {
        qDebug() << "Checkmate!";
        verification->setPlainText("Checkmate!");
        return;
    }
    else if (responseString.compare("Stalemate") == 0)
    {
        qDebug() << "Stalemate!";
        verification->setPlainText("Stalemate!");
        return;
    }
    // Otherwise, use the response from Game to move the correct pieces
    else
    {
        qDebug() << "Display got permission from Game to move icons.";
//        qDebug() << "The response Game sent back was " << response;
        if (signal == "Castle White Kingside")
        {
            qDebug() << "Display needs to castle white kingside.";
            QString tempKing = ListeDePiece[60]->getPng();
            ListeDePiece[60]->clearPng();
            QString tempRook = ListeDePiece[63]->getPng();
            ListeDePiece[63]->clearPng();

            ListeDePiece[62]->setPng(tempKing);
            ListeDePiece[61]->setPng(tempRook);
        } else if (signal == "Castle White Queenside")
        {
            qDebug() << "Display needs to castle white queenside.";
            QString tempKing = ListeDePiece[60]->getPng();
            ListeDePiece[60]->clearPng();
            QString tempRook = ListeDePiece[56]->getPng();
            ListeDePiece[56]->clearPng();

            ListeDePiece[58]->setPng(tempKing);
            ListeDePiece[59]->setPng(tempRook);
        } else if (signal == "Castle Black Kingside")
        {
            qDebug() << "Display needs to castle black kingside.";
            QString tempKing = ListeDePiece[4]->getPng();
            ListeDePiece[4]->clearPng();
            QString tempRook = ListeDePiece[7]->getPng();
            ListeDePiece[7]->clearPng();

            ListeDePiece[6]->setPng(tempKing);
            ListeDePiece[5]->setPng(tempRook);
        } else if (signal == "Castle Black Queenside")
        {
            qDebug() << "Display needs to castle black queenside.";
            QString tempKing = ListeDePiece[4]->getPng();
            ListeDePiece[4]->clearPng();
            QString tempRook = ListeDePiece[0]->getPng();
            ListeDePiece[0]->clearPng();

            ListeDePiece[2]->setPng(tempKing);
            ListeDePiece[3]->setPng(tempRook);
        }
        else
        {
            QString firstSpace = "";
            QString secondSpace = "";
            firstSpace += signal[0];
            firstSpace += signal[1];
            secondSpace += signal[2];
            secondSpace += signal[3];

            QString temp;
            for (int i=0; i<ListeDePiece.length(); i++ )
            {
                if (ListeDePiece[i]->getNomPiece() == firstSpace)
                {
                    temp = ListeDePiece[i]->getPng();
                    ListeDePiece[i]->clearPng();
                }
            }
            for (int i=0; i<ListeDePiece.length(); i++ )
            {
                if (ListeDePiece[i]->getNomPiece() == secondSpace)
                {
                    ListeDePiece[i]->setPng(temp);
                }
            }
        }

        if (couleur == true)
        {
            couleur = false;
            tourJoueur->setPlainText("Black's Turn");
        }
        else
        {
            couleur = true;
            tourJoueur->setPlainText("White's Turn");
        }
    }

}
