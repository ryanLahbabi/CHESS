#ifndef FOU_H
#define FOU_H
#include <Piece.h>
#include <echequier.h>
#endif // FOU_H


namespace modele{

class Fou:public Piece
{
public:
    Fou(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
    {
        couleur_ = couleur;
    }
     void mouvementLegal(Echequier& echequier) override;

protected:
    const int MAXMOUVEMENTX = 7;
    const int MAXMOUVEMENTY = 7;

private:
    int deltaX_;
    int deltaY_;


};
}
