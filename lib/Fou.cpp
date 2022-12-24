#include <Fou.h>
#include <cmath>
#include <iostream>
using namespace std;

Fou::Fou(modele::Couleur c): Piece(modele::FOU, c){}

bool Fou::mouvementLegal(const modele::Echequier* echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    if(echequier->mouvementDiagonale(coordoneeInit, coordoneeFinale))
    {

        return true;
    }
        if(echequier->caseLibre(coordoneeInit, coordoneeFinale))
        {
                return true;
        }
    return false;
}
