#ifndef TOUR_H
#define TOUR_H
#endif // TOUR_H
#include <echequier.h>

namespace modele
{
class Tour: virtual public Piece
{
public:
    Tour(int x, int y, bool couleur )
    {
        couleur_ = couleur;
    }
      void mouvementLegal(Echequier& echiquier, int x, int y) ;
      ~Tour();
      void Raii(Tour& tour);
      shared_ptr<Tour> getTour() {return tourPtr_;}

private:
      shared_ptr<Tour> tourPtr_ = nullptr; // nullptr == ptr.count() = 0;
    const int MAXMOUVEMENTX = 7;
    const int MAXMOUVEMENTY = 7;
};
}
