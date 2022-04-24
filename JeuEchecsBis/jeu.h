#ifndef JEU_H
#define JEU_H

#endif // JEU_H
#include <echequier.h>
#include <cmath>
#include <iostream>

namespace modele
{

class Jeu:
{

public:
    Jeu();
    ~Jeu();
    Echequier& getEchequier(){return echiquier_;};
    void voirCoordonnees(int x, int y);
    void deplacerPiece();
    bool& debutPartie(){return debutPartie_;};
    bool& finPartie(){return finPartie_;};
    bool& miseEnEchec(){return miseEnEchec_;};
    bool& tourJoueur(){return tourJoueur_;};
    bool& gagnant(){return gagnant_;};
    bool& coteReine(){return coteReine_;};
    bool& cliqueSurPiece(){return cliqueSurPiece_;};
    int*   tableau[8][8];  // tableau de l'échiquier

private:
    Echequier echiquier_;
    bool debutPartie_ = false;
    bool miseEnEchec_ = false; // true
    bool finPartie_ = false; // true le jeu est finit
    bool tourJoueur_ = false; //true = blanc
    bool gagnant_ = false;    //true = blanc
    bool coteReine_ = true; //cote_Reine = true
    bool cliqueSurPiece_ = false;


};
}
