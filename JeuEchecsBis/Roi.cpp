#include "Roi.h"

using namespace std;


bool modele::Roi::miseEnEchec(Echequier& echiquier)
{
    for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (echiquier.getPiece(i, j)->getcouleur() != couleur_ && echiquier.getPiece(i, j) != nullptr &&
                        echiquier.getPiece(i, j) != echiquier.getPiece(x_, y_))
                {
                    if (dynamic_cast<Roi*>(echiquier.getPiece(i, j).get()))
                        if ((abs(i - x_) == 1 && abs(j - y_) == 0)	   //deplacer en horizontal
                            || (abs(i - x_) == 0 && abs(j - y_) == 1)  //deplacer en vertical
                            || (abs(i - x_) == 1 && abs(j - y_) == 1)) //deplacer en diagonal
                            return true;

                    }
                }
        }

}

// Reste à implémenter mouvement légal.

