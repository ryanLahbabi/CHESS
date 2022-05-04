#include "reine.h"

using namespace std;
Reine::Reine(bool couleur): Piece(modele::REINE, couleur)
{}

bool Reine::mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->mouvementVerticale(coordoneeInit, coordoneeFinale)
            || echequier->mouvementHorizontale(coordoneeInit, coordoneeFinale))
    {
        if (echequier->caseLibre(coordoneeInit, coordoneeFinale))
        {
            return true;
        }
    }

    if(echequier->mouvementDiagonale(coordoneeInit, coordoneeFinale))
    {
        if (echequier->caseLibre(coordoneeInit, coordoneeFinale))
        {
            return true;
        }
    }

    return false;

}
