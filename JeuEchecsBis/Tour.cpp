#include "Tour.h"

using namespace std;


void modele::Tour::mouvementLegal(Echequier& echiquier)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int deltaX = 0;
            int deltaY = 0;
            if (i - x_ != 0 || j - y_ != 0)
            {
                if (x_ != i)
                {
                    if (i - x_ < 0)
                        deltaX = - 1;
                    else
                        deltaY = 1;

                    for (int k = 1; k <= abs(i - x_);)
                    {
                        if (echiquier.getPiece(x_ + deltaX * k, y_ + deltaY * k) != nullptr)
                        {
                            k++;
                            break;
                        }
                        k++;
                    }
                    int k = 1;
                    if (x_ + deltaX * (k - 1) == i && y_ + deltaY * (k - 1) == j)
                    {
                        if (echiquier.getPiece(i, j) == nullptr)
                            mouvementLegal.push_back({i, j});
                        else if (couleur_ != echiquier.getPiece(i, j)->couleur_)
                            mouvementLegal.push_back({i, j});
                    }
                }
                else if (y_ != j)
                {
                    if (j - y_ < 0)
                        deltaY = - 1;
                    else
                        deltaY = 1;
                    int k = 1;
                    for (; k <= abs(j - y_);)
                    {
                        if (echiquier.getPiece(x_ + deltaX * k, y_ + deltaY * k) != nullptr)
                        {
                            k++;
                            break;
                        }
                        k++;

                    }
                    if (x_ + deltaX * (k - 1) == i && y_ + deltaY * (k - 1) == j)
                    {
                        if (echiquier.getPiece(i, j) == nullptr)
                            mouvementLegal.push_back({i, j});
                        else if
                        {
                            (couleur_ != echiquier.getPiece(i, j)->couleur_
                            mouvementLegal.push_back({i, j});

                        }
                    }
    }
}

}
}
}
}



