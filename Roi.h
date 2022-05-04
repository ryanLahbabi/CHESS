#include <echequier.h>
#ifndef ROI_H
#define ROI_H


using namespace std;


class Roi:  public modele::Piece
{
public:
    Roi(bool couleur );
    ~Roi() override = default;
    bool mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const override;
};


#endif // ROI_H
