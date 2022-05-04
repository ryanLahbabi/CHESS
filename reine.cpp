#include "reine.h"

using namespace std;
Reine::Reine(bool couleur): Piece(modele::REINE, couleur)
{}

bool Reine::mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->isVerticalMove(coordoneeInit, coordoneeFinale) || echequier->isHorizontalMove(coordoneeInit, coordoneeFinale))
    {
        if (echequier->isPathClear(coordoneeInit, coordoneeFinale))
        {
            return true;
        }
    }

    if(echequier->isDiagonalMove(coordoneeInit, coordoneeFinale))
    {
        if (echequier->isPathClear(coordoneeInit, coordoneeFinale))
        {
            return true;
        }
    }

    return false;

}
