#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "jeu.h"
#include "Regle.h"

#include <QGraphicsScene>
#include <QObject>

namespace modele {


class Affichage: public QObject
{
    Q_OBJECT

public:
    Affichage();
    QGraphicsScene* getGraphique();
//public slots:
//   void getSignal(QString signal);
private:
    QGraphicsScene * afficherJeu;
    Jeu jeu;
    QList<Regle*> ListeDePiece;
    QString mouvement;
    void debut();
    void piecesPlacer();
    bool couleur = true; //true = blanc
    QGraphicsTextItem * verification;
    QGraphicsTextItem * tourJoueur;

    const QString numeroCase[64] =
    {
        "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8",
        "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7",
        "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6",
        "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5",
        "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4",
        "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3",
        "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2",
        "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"
    };



};

}


#endif // AFFICHAGE_H
