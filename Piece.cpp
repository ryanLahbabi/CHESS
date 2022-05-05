#include <iostream>
#include "Piece.h"

modele::Piece::Piece(TypePiece t, bool c)
{
    type_ = t;
    couleur_ = c;
    mouvement_ = 0;
}

bool modele::Piece::getCouleur() const
{
    return couleur_;
}

void modele::Piece::setCouleur(bool couleur)
{
    couleur_ = couleur;
}

modele::TypePiece modele::Piece::getTypePiece() const
{
    return type_;
}

void modele::Piece::setType(modele::TypePiece type)
{
    type_ = type;
}

bool modele::Piece::deplacement() const
{
    return mouvement_ > 0;
}

void modele::Piece::incrementer()
{
    ++mouvement_;
}

void modele::Piece::decrementer()
{
    --mouvement_;
}
