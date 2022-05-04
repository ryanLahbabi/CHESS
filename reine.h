#ifndef REINE_H
#define REINE_H

#endif // REINE_H
#include "echequier.h"
#include "Piece.h"
using namespace std;

class Reine:  public modele::Piece
{
public:
    Reine(bool couleur );
    ~Reine() override = default;
    bool mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;

};
