#include <echequier.h>
#ifndef TOUR_H
#define TOUR_H
using namespace std;


class Tour:  public modele::Piece
{
public:
    Tour(bool couleur);
    bool mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
    ~Tour() override = default;

};
#endif // TOUR_H
