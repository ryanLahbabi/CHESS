#ifndef FOU_H
#define FOU_H
#include <echequier.h>
#endif // FOU_H


namespace modele{

class Fou: public Piece
{
public:
    Fou(int x, int y, bool couleur )
    {
        couleur_ = couleur;
    }
    virtual ~Fou();
     void mouvementLegal(Echequier& echiquier, int x, int y ) ;
     shared_ptr<Fou> getFou() {return fouPtr_;}
protected:
     shared_ptr<Fou> fouPtr_ = nullptr; // nullptr == ptr.count() = 0;
    const int MAXMOUVEMENTX_ = 7;
    const int MAXMOUVEMENTY_ = 7;
    int deltaX_;
    int deltay_;


};
}
