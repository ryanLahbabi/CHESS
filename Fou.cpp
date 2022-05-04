#include <Fou.h>
#include <cmath>
#include <iostream>
using namespace std;

Fou::Fou(bool couleur): Piece(modele::FOU, couleur){}

bool Fou::mouvementLegal(const Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->isDiagonalMove(coordoneeInit, coordoneeFinale))
    {

        return true;
    }
        if(echequier->isPathClear(coordoneeInit, coordoneeFinale))
        {
                return true;
        }
    return false;
}
