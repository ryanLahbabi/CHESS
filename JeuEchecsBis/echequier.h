#ifndef ECHEQUIER_H
#define ECHEQUIER_H

#endif // ECHEQUIER_H
#include <QObject>
#include <cmath>
#include <iostream>
#include <PIECE.h>


using namespace std;

namespace modele //Ajout de namespace modele
{

class Echequier
{
public:
    Echequier();
    void enleverPiece(int x, int y);
    void board();
    unique_ptr<Piece>& getPiece(int x, int y) { return pieces_[x][y]; }
    bool& getechecNoir(){return echecNoir_; };
    bool& getechecBlanc(){return echecBlanc_; };
    bool& getechecMatBlanc(){return echecMatBlanc_; };
    bool& getechecMatNoir(){return echecMatNoir_; };
    unique_ptr<Piece>& getPieceAbstraite() { return pieceAbstraite_; }


private:
    unique_ptr<Piece> pieces_[8][8];
    unique_ptr<Piece> pieceAbstraite_; // piece que l'on peut pas supprimer lorsque le roi est en échec
    pair <int, int> positionRoi_;
    int nbPieceDebut_ = 32;
    int nbPieceRestante_;
    bool echecBlanc_ = false;
    bool echecNoir_ = false;
    bool echecMatBlanc_ = false;
    bool echecMatNoir_ = false;
};


}
