#ifndef PIECE_H
#define PIECE_H

#endif // PIECE_H
#include <QObject>
#include <cmath>
#include <iostream>
#include <Regle.h>

using namespace std;

namespace modele{

class Piece: public Regle
{
public:
    Piece() = default;
    Piece(int x, int y, bool couleur);//bool = true --> Blanc
    virtual ~Piece() = default;
    virtual void deplacement(Echequier& echiquier);


    int& getx(){return x_;}
    int& gety(){return y_;}
    bool& getcouleur() {return couleur_;}

protected:
    int x_ = 0;
    int y_ = 0;
    bool couleur_ = true;// Si cest faux(0) la piece noir, si c'est true(1) la piece blanche

};
}
