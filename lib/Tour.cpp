#include "Tour.h"

using namespace std;
Tour::Tour(modele::Couleur c): Piece(modele::TOUR, c)
{}

bool Tour::mouvementLegal(const modele::Echequier *echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->mouvementVerticale(coordoneeInit, coordoneeFinale)
      || echequier->mouvementHorizontale(coordoneeInit, coordoneeFinale))
    {
        if (echequier->caseLibre(coordoneeInit, coordoneeFinale))
        {
            return true;
        }
    }
    return false;

}
