#include "echequier.h"
#ifndef REINE_H
#define REINE_H
using namespace std;

class Reine:  public modele::Piece
{
public:
    Reine(modele::Couleur c );
    ~Reine() override = default;
 bool mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
};
#endif // REINE_H
