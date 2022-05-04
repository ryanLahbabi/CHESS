#include "Roi.h"

using namespace std;
Roi::Roi(bool couleur): Piece(modele::ROI, couleur)
{}

bool Roi::mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->getMoveLength(coordoneeInit, coordoneeFinale)== 1)
    {
        return true;
    }
    return false;
}
