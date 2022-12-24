#include "cavalier.h"

using namespace std;
Cavalier::Cavalier(modele::Couleur c): Piece(modele::CAVALIER, c)
{}

bool Cavalier::mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->cavalierBouger(coordoneeInit, coordoneeFinale))
    {
        return true;
    }
    return false;
}
