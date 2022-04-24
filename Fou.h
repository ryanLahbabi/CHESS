#ifndef FOU_H
#define FOU_H
#include <PIECE.h>
#endif // FOU_H


namespace modele{

class Fou:public Piece
{
public:
    Fou(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
    {
        couleur_ = couleur;
    }
     void mouvementLegal(int x, int y ) override;
     int deltaX;
     int deltay;
protected:
    const int MAXMOUVEMENTX = 7;
    const int MAXMOUVEMENTY = 7;


};
}
