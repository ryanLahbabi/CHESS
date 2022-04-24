#ifndef ROI_H
#define ROI_H
#include <echequier.h>
#endif // ROI_H
namespace modele
{

class Roi: public Piece
{
public:

     Roi(int x, int y, bool couleur )
     {
         couleur_ = couleur;
         count_++;

         if (count_ >= 3)
         {
             throw("Plus de deux Rois non permis!");
         }

     }

     ~Roi();
     virtual void mouvementLegal(Echequier& echiquier );
     virtual void deplacement(Echequier& echiquier );
     bool miseEnEchec(Echequier& echiquier);
     static int getCount();


     bool echec = false;

private:
     shared_ptr<Roi> roiPtr = nullptr; // nullptr == ptr.count() = 0;
    static int count_;
    const int MAXMOUVEMENTX_ = 1;
    const int MAXMOUVEMENTY_ = 1;

};

};
