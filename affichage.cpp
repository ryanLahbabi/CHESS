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
    bool couleur = false; // a revoir
    for(int i=0; i<64; i++)
    {
        QString nomCase = numeroCase[i];
        Regle* r = new Regle(j,k);
        r->setRect(j,k,50,50); //x loc, y loc, width, height


        if (i % 8 == 0)
        {
            couleur = !couleur;  // a revoir
        }

         if (couleur)
        {
            r->setBrush(Qt::lightGray);
        }
        couleur = !couleur;

         r->setNomPiece(nomCase);
         ListeDePiece.append(r);
         afficherJeu->addItem(r);
        // Connect Space signal with Game slot
        QObject::connect(r, SIGNAL(sendSignal(QString)), &jeu, SLOT(getInput(QString)));

        j += 50;
        if (j == 400)
        {
            j = 0;
            k += 50;
        }
    }

    QGraphicsTextItem * partie = new QGraphicsTextItem();
    partie->setPos(425, 0);
    afficherJeu->addItem(partie);

//    tour des blanc
      tourJoueur = new QGraphicsTextItem();
      tourJoueur->setPos(425, 100);
      afficherJeu->addItem(tourJoueur);


      verification = new QGraphicsTextItem();
      verification->setPos(425, 200);
      afficherJeu->addItem(verification);
}

void modele::Affichage::piecesPlacer()
{
    ListeDePiece[0]->setPng(":/pieces/tourNoir.png");
    ListeDePiece[1]->setPng(":/pieces/cavalierNoir.png");
    ListeDePiece[2]->setPng(":/pieces/fouNoir.png");
    ListeDePiece[3]->setPng(":/pieces/reineNoir.png");
    ListeDePiece[4]->setPng(":/pieces/roiNoir.png");
    ListeDePiece[5]->setPng(":/pieces/fouNoir.png");
    ListeDePiece[6]->setPng(":/pieces/cavalierNoir.png");
    ListeDePiece[7]->setPng(":/pieces/tourNoir.png");
    ListeDePiece[8]->setPng(":/pieces/pionNoir.png");
    ListeDePiece[9]->setPng(":/pieces/pionNoir.png");
    ListeDePiece[10]->setPng(":/pieces/pionNoir.png");
    ListeDePiece[11]->setPng(":/pieces/pionNoir.png");
    ListeDePiece[12]->setPng(":/pieces/pionNoir.png");
    ListeDePiece[13]->setPng(":/pieces/pionNoir.png");
    ListeDePiece[14]->setPng(":/pieces/pionNoir.png");
    ListeDePiece[15]->setPng(":/pieces/pionNoir.png");

    ListeDePiece[48]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[49]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[50]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[51]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[52]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[53]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[54]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[55]->setPng(":/pieces/pionBlanc.png");
    ListeDePiece[56]->setPng(":/pieces/tourBlanche.png");
    ListeDePiece[57]->setPng(":/pieces/cavalierBlanc.png");
    ListeDePiece[58]->setPng(":/pieces/fouBlanc.png");
    ListeDePiece[59]->setPng(":/pieces/reineBlanche.png");
    ListeDePiece[60]->setPng(":/pieces/roiBlanc.png");
    ListeDePiece[61]->setPng(":/pieces/fouBlanc.png");
    ListeDePiece[62]->setPng(":/pieces/cavalierBlanc.png");
    ListeDePiece[63]->setPng(":/pieces/tourBlanche.png");
}


QGraphicsScene* modele::Affichage::getGraphique()
{
     return afficherJeu;
}


//Avoir une reponse du jeu et changer l image de la piece sur
//la case de l'Ã©chiquier


//void modele::Affichage::getSignal(QString signal)
//{
//    string responseString = response.toStdString();

//    if (responseString.compare("Check") == 0)
//    {
//        qDebug() << "Check";
//        check->setPlainText("Check!");
//    }
//    else
//    {
//        check->setPlainText("");
//    }

//    // If response was "Invalid Move", ignore it
//    if (responseString.compare("Invalid Move") == 0)
//    {
//        qDebug() << "Invalid Move";
//        return;
//    }
//    else if (responseString.compare("Checkmate") == 0)
//    {
//        qDebug() << "Checkmate!";
//        check->setPlainText("Checkmate!");
//        return;
//    }
//    else if (responseString.compare("Stalemate") == 0)
//    {
//        qDebug() << "Stalemate!";
//        check->setPlainText("Stalemate!");
//        return;
//    }
//    // Otherwise, use the response from Game to move the correct pieces
//    else
//    {
//        qDebug() << "Display got permission from Game to move icons.";
////        qDebug() << "The response Game sent back was " << response;
//        if (response == "Castle White Kingside")
//        {
//            qDebug() << "Display needs to castle white kingside.";
//            QString tempKing = spaceList[60]->getImage();
//            spaceList[60]->clearImage();
//            QString tempRook = spaceList[63]->getImage();
//            spaceList[63]->clearImage();

//            spaceList[62]->setImage(tempKing);
//            spaceList[61]->setImage(tempRook);
//        } else if (response == "Castle White Queenside")
//        {
//            qDebug() << "Display needs to castle white queenside.";
//            QString tempKing = spaceList[60]->getImage();
//            spaceList[60]->clearImage();
//            QString tempRook = spaceList[56]->getImage();
//            spaceList[56]->clearImage();

//            spaceList[58]->setImage(tempKing);
//            spaceList[59]->setImage(tempRook);
//        } else if (response == "Castle Black Kingside")
//        {
//            qDebug() << "Display needs to castle black kingside.";
//            QString tempKing = spaceList[4]->getImage();
//            spaceList[4]->clearImage();
//            QString tempRook = spaceList[7]->getImage();
//            spaceList[7]->clearImage();

//            spaceList[6]->setImage(tempKing);
//            spaceList[5]->setImage(tempRook);
//        } else if (response == "Castle Black Queenside")
//        {
//            qDebug() << "Display needs to castle black queenside.";
//            QString tempKing = spaceList[4]->getImage();
//            spaceList[4]->clearImage();
//            QString tempRook = spaceList[0]->getImage();
//            spaceList[0]->clearImage();

//            spaceList[2]->setImage(tempKing);
//            spaceList[3]->setImage(tempRook);
//        }
//        else
//        {
//            QString firstSpace = "";
//            QString secondSpace = "";
//            firstSpace += response[0];
//            firstSpace += response[1];
//            secondSpace += response[2];
//            secondSpace += response[3];

//            QString temp;
//            for (int i=0; i<spaceList.length(); i++ )
//            {
//                if (spaceList[i]->getName() == firstSpace)
//                {
//                    temp = spaceList[i]->getImage();
//                    spaceList[i]->clearImage();
//                }
//            }
//            for (int i=0; i<spaceList.length(); i++ )
//            {
//                if (spaceList[i]->getName() == secondSpace)
//                {
//                    spaceList[i]->setImage(temp);
//                }
//            }
//        }

//        if (turnColor == WHITE)
//        {
//            turnColor = BLACK;
//            turn->setPlainText("Black's Turn");
//        }
//        else
//        {
//            turnColor = WHITE;
//            turn->setPlainText("White's Turn");
//        }
//    }

//}
