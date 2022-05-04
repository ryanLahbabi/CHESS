#ifndef TOUR_H
#define TOUR_H
#endif // TOUR_H
#include <echequier.h>
#include "Piece.h"
using namespace std;


class Tour:  public modele::Piece
{
public:
    Tour(bool couleur);
    bool mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
    ~Tour() override = default;

};

