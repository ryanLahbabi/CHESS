#ifndef PIECE_H
#define PIECE_H

#endif // PIECE_H
#include <QObject>
#include <cmath>
#include <iostream>


using namespace std;

namespace modele{

class Piece
{
public:
    Piece() = default;
    Piece(int x, int y, bool couleur);//bool = true --> Blanc
    virtual ~Piece() = default;

    int& getX(){return x_;}
    int& getY(){return y_;}

    //template <typename T>
    virtual bool Raii(shared_ptr<Piece> piecePtr);
    bool& getCouleur() {return couleur_;}
    void deplacement();
    bool mouvementLegalverification();
    bool miseEnEchec();

protected:
    shared_ptr<Piece> piecePtr_ = nullptr;
    int x_ = 0;
    int y_ = 0;
    bool couleur_ = true;// Si cest faux(0) la piece noir, si c'est true(1) la piece blanche


};
}
