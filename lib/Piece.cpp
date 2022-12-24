#include <iostream>
#include "Piece.h"

modele::Piece::Piece(TypePiece t, Couleur c)
{
    mouvement_ = 0;
    type_ = t;
    couleur = c;
}

modele::Couleur modele::Piece::getCouleur() const
{
    return couleur;
}

void modele::Piece::setCouleur(Couleur couleur)
{
    Piece::couleur = couleur;
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



