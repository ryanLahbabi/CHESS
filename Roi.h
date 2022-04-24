#ifndef ROI_H
#define ROI_H
#include <echequier.h>
#endif // ROI_H
namespace modele
{

class Roi: virtual public Piece
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


     virtual void mouvementLegal(Echequier& echiquier );
     virtual void deplacement(Echequier& echiquier );
     bool miseEnEchec(Echequier& echiquier);
     static int getCount();

     shared_ptr<Roi>& getRoi() { return roiPtr_; }
     void Raii(Roi& roi);



     bool echec = false;

    ~Roi();
private:
    shared_ptr<Roi> roiPtr_ = nullptr; // nullptr == ptr.count() = 0;
    static int count_;
    const int MAXMOUVEMENTX_ = 1;
    const int MAXMOUVEMENTY_ = 1;

};

};
