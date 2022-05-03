#include "Piece.h"

bool modele::Piece::miseEnEchec()
{
    return true; //par defaut
}

bool modele::Piece::mouvementLegalverification()
{
    return false;
}

void modele::Piece::deplacement()
{
    //** code here **//
}

bool modele::Piece::Raii(shared_ptr<modele::Piece> piecePtr)
{
    if (modele::Piece::miseEnEchec())
    {
        //** limiter deplacement piece **//
        deplacement();
    }

    if (modele::Piece::mouvementLegalverification())
    {
        //Echequier::enleverPiece(piecePtr->getX(), piecePtr->getY());
        //Echequier::ajouterPieceTemp(piecePtr->getX(), piecePtr->getY());
    }
    else
    {
        throw("Vous risquez d'être mis en echec.");
    }


    return modele::Piece::miseEnEchec();
}


