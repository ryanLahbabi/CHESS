#ifndef ROI_H
#define ROI_H
#include <echequier.h>
#include "Piece.h"
#endif // ROI_H

using namespace std;


class Roi:  public modele::Piece
{
public:
    Roi(bool couleur );
    ~Roi() override = default;
    bool mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
};
