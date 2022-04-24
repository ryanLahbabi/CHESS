#ifndef TOUR_H
#define TOUR_H
#endif // TOUR_H
#include <PIECE.h>

namespace modele
{
class Tour:public Piece
{
public:
    Tour(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
    {
        couleur_ = couleur;
    }
     void mouvementLegal(int x, int y) override;

protected:
    const int MAXMOUVEMENTX = 7;
    const int MAXMOUVEMENTY = 7;
};
}
