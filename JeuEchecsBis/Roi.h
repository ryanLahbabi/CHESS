#ifndef ROI_H
#define ROI_H
#include <echequier.h>
#include <Piece.h>
#endif // ROI_H
namespace modele
{

class Roi: public Piece
{
public:
     Roi(int x, int y, bool couleur ):Piece::Piece(x, y, couleur)
     {
         couleur_ = couleur;

     }
     virtual void mouvementLegal(Echequier& echiquier ) override;
     virtual void deplacement(Echequier& echiquier ) override;
     bool miseEnEchec(Echequier& echiquier);

     bool echec = false;

private:
    const int MAXMOUVEMENTX = 1;
    const int MAXMOUVEMENTY = 1;

};

};
