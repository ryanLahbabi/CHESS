#ifndef CASE_H
#define CASE_H

#include "Piece.h"
#include <memory>
using namespace std;

class Case
{
public:

    modele::Piece* getPieces() const;
    unique_ptr<modele::Piece> setPiece(unique_ptr<modele::Piece> piece);
private:
    unique_ptr<modele::Piece> piece_;
};

#endif // CASE_H
