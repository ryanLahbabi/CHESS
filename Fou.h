#include <echequier.h>

#ifndef FOU_H
#define FOU_H

class Fou: public modele::Piece
{
public:
    Fou(bool couleur);
    ~Fou() override = default;
    bool mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
};

#endif // FOU_H
