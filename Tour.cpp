#include "Tour.h"

using namespace std;
Tour::Tour(bool couleur): Piece(modele::TOUR, couleur)
{}

bool Tour::mouvementLegal(const Echequier *echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->isVerticalMove(coordoneeInit, coordoneeFinale)
      || echequier->isHorizontalMove(coordoneeInit, coordoneeFinale))
    {
        if (echequier->isPathClear(coordoneeInit, coordoneeFinale))
        {
            return true;
        }
    }

    // If we've gotten this far, not a valid move
    return false;

}
