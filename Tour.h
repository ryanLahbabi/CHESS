#ifndef TOUR_H
#define TOUR_H
#endif // TOUR_H
#include <echequier.h>

namespace modele
{
class Tour:  public Piece
{
public:
    Tour(int x, int y, bool couleur )
    {
        couleur_ = couleur;
    }
    virtual ~Tour();
      void mouvementLegal(Echequier& echiquier, int x, int y) ;
      shared_ptr<Tour> getTour() {return tourPtr_;}

private:
    shared_ptr<Tour> tourPtr_ = nullptr; // nullptr == ptr.count() = 0;
    const int MAXMOUVEMENTX_ = 7;
    const int MAXMOUVEMENTY_ = 7;
};
}
