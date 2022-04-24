#ifndef TOUR_H
#define TOUR_H
#endif // TOUR_H
#include <Piece.h>
#include <echequier.h>


namespace modele
{
class Tour:public Piece
{
public:
    Tour(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
    {
        couleur_ = couleur;
    }
    virtual void mouvementLegal(Echequier& echiquier ) override;
    virtual void deplacement(Echequier& echiquier ) override;

protected:
    const int MAXMOUVEMENTX = 7;
    const int MAXMOUVEMENTY = 7;
};
}
