#include "pion.h"

Pion::Pion(bool couleur) : Piece::Piece(modele::PION, couleur){}


 bool Pion::mouvementLegal(const modele::Echequier *echequier, const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
 {
     int distance = echequier->distance(coordoneeInit, coordoneeFinale);

     if (!echequier->avancer(coordoneeInit, coordoneeFinale, this))
     {
             return false;
     }
     if (echequier->mouvementHorizontale(coordoneeInit, coordoneeFinale))
     {
             return false;
     }
     if (echequier->mouvementDiagonale(coordoneeInit, coordoneeFinale))
     {
        if (distance == 1)
        {
            if (echequier->couleurDiffNonValide(coordoneeInit, coordoneeFinale))
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
     if (echequier->mouvementVerticale(coordoneeInit, coordoneeFinale))
     {
        if (echequier->positionNonValide(coordoneeFinale))
        {
            return false;
        }
        if (distance == 2)
        {
            if (!deplacement() && echequier->caseLibre(coordoneeInit, coordoneeFinale))
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
