#ifndef FOU_H
#define FOU_H
#include <echequier.h>
#include "Piece.h"
#endif // FOU_H

class Fou: public modele::Piece
{
public:
    Fou(bool couleur);
    ~Fou() override = default;
    bool mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
};
