#ifndef PION_H
#define PION_H

#include "echequier.h"


class Pion : public modele::Piece
{
public:
    Pion(modele::Couleur c);
 bool mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
 ~Pion() override = default;
};

#endif // PION_H
