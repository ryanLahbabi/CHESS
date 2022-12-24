#include <echequier.h>
#ifndef CAVALIER_H
#define CAVALIER_H

using namespace std;

class Cavalier:  public modele::Piece
{
public:
    Cavalier(modele::Couleur c );
    ~Cavalier() override = default;
    bool mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;

};

#endif // CAVALIER_H
