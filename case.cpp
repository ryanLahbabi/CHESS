#include "case.h"
#include <memory>

modele::Piece* Case::getPieces() const {return piece_.get();}

unique_ptr<modele::Piece> Case::setPiece(unique_ptr<modele::Piece> piece)
{
    unique_ptr<modele::Piece> ancient = move(this->piece_);
    this->piece_ = move(piece);
    return ancient;
}

