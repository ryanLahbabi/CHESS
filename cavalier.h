#ifndef CAVALIER_H
#define CAVALIER_H

#endif // CAVALIER_H

#include <echequier.h>
#include "Piece.h"
using namespace std;

class Cavalier:  public modele::Piece
{
public:
    Cavalier(bool couleur );
    ~Cavalier() override = default;
    bool mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;

};
