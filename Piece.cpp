#include <iostream>
#include "Piece.h"

modele::Piece::Piece(TypePiece t, bool c)
{
    type_ = t;
    couleur_ = c;
    mouvement_ = 0;
}
std::ostream &operator<<(std::ostream &out, const modele::Piece &piece)
{
    // This has to use a getter because this is a friend function
    out << " " << piece.colorToChar(piece.getCouleur()) << piece.typeToChar(piece.getTypePiece()) << " ";
    return out;
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



char modele::Piece::typeToChar(TypePiece type) const
{
    switch(type)
    {
        case PION: return 'P';
        case CAVALIER: return 'N';
        case FOU: return 'B';
        case TOUR: return 'R';
        case REINE: return 'Q';
        case ROI: return 'K';
        default: return ' ';
    }
}

char modele::Piece::colorToChar(bool color) const
{
    if(color)
    {
      return 'W';
    }
    return 'B';
}
