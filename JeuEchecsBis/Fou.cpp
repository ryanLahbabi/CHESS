#include <Fou.h>
#include <cmath>

using namespace std;



void modele::Fou::mouvementLegal(Echequier& echequier)
{
    deltaX_ = 0;
    deltaY_ = 0;

    for (int i = 0 ; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if ( (i != x_ && j != y_) && std::abs(i - x_) == std::abs(j - y_) )
            {
                if (i - x_ < 0)
                    deltaX_ = -1;
                else
                    deltaX_ = 1;
                if (j - y_ < 0)
                    deltaY_ = -1;
                else
                    deltaY_ = 1;

                for (int k = 1; k <= std::abs(x_ - i); k++)
                {
                    if (echequier.getPiece(x_ + deltaX_ * k, y_ + deltaY_ * k) != nullptr)
                    {
                    }
                }
            }
        }
    }
}
