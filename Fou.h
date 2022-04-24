#ifndef FOU_H
#define FOU_H
#include <echequier.h>
#endif // FOU_H


namespace modele{

class Fou: virtual public Piece
{
public:
    Fou(int x, int y, bool couleur )
    {
        couleur_ = couleur;
    }
     void mouvementLegal(Echequier& echiquier, int x, int y ) ;
     int deltaX;
     int deltay;
     void Raii(Fou& fou);
     shared_ptr<Fou> getFou() {return fouPtr_;}
     ~Fou();
protected:
     shared_ptr<Fou> fouPtr_ = nullptr; // nullptr == ptr.count() = 0;
    const int MAXMOUVEMENTX = 7;
    const int MAXMOUVEMENTY = 7;


};
}
