#include "pion.h"

Pion::Pion(bool couleur) : Piece::Piece(modele::PION, couleur){}


 bool Pion::mouvementLegal(const Echequier *echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
 {
     int distance = echequier->distance(coordoneeInit, coordoneeFinale);

     if (!echequier->isForwardMove(coordoneeInit, coordoneeFinale, this))
     {
             return false;
     }
     if (echequier->isHorizontalMove(coordoneeInit, coordoneeFinale))
     {
             return false;
     }
     if (echequier->isDiagonalMove(coordoneeInit, coordoneeFinale))
     {
        if (distance == 1)
        {
            if (echequier->isOccupiedDifferentColor(coordoneeInit, coordoneeFinale))
            {
                 return true;
            }
            else
            {
                return false;
            }
         }
         else
         {
            return false;
         }
     }
     if (echequier->isVerticalMove(coordoneeInit, coordoneeFinale))
     {
        if (echequier->isOccupied(coordoneeFinale))
        {
            return false;
        }
        if (distance == 2)
        {
            if (!getMoved() && echequier->isPathClear(coordoneeInit, coordoneeFinale))
            {
                return true;
            }
        }
        else if (distance == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
     }
        return false;
 }
