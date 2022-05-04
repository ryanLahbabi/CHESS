#include "cavalier.h"

using namespace std;
Cavalier::Cavalier(bool couleur): Piece(modele::CAVALIER, couleur)
{}

bool Cavalier::mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->cavalierBouger(coordoneeInit, coordoneeFinale))
    {
        return true;
    }
    return false;
}
