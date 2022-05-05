#include "echequier.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Piece.h"
#include "pion.h"
#include <Roi.h>
#include "reine.h"
#include "Tour.h"
#include "Fou.h"
#include "cavalier.h"


using namespace std;

modele::Echequier::Echequier(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8 ; j++)
        {
           cases_.insert(pair<pair<int,int>,unique_ptr<Case>>(make_pair(i, j),make_unique<Case>()));
        }
    }

    //Pions
    setPiece(make_pair(6,0), make_unique<Pion>(true));
    setPiece(make_pair(6,1), make_unique<Pion>(true));
    setPiece(make_pair(6,2), make_unique<Pion>(true));
    setPiece(make_pair(6,3), make_unique<Pion>(true));
    setPiece(make_pair(6,4), make_unique<Pion>(true));
    setPiece(make_pair(6,5), make_unique<Pion>(true));
    setPiece(make_pair(6,6), make_unique<Pion>(true));
    setPiece(make_pair(6,7), make_unique<Pion>(true));

    setPiece(make_pair(1,0), make_unique<Pion>(false));
    setPiece(make_pair(1,1), make_unique<Pion>(false));
    setPiece(make_pair(1,2), make_unique<Pion>(false));
    setPiece(make_pair(1,3), make_unique<Pion>(false));
    setPiece(make_pair(1,4), make_unique<Pion>(false));
    setPiece(make_pair(1,5), make_unique<Pion>(false));
    setPiece(make_pair(1,6), make_unique<Pion>(false));
    setPiece(make_pair(1,7), make_unique<Pion>(false));

    //Cavalier
    setPiece(make_pair(7,1), make_unique<Cavalier>(true));
    setPiece(make_pair(7,6), make_unique<Cavalier>(true));

    setPiece(make_pair(0,1), make_unique<Cavalier>(false));
    setPiece(make_pair(7,6), make_unique<Cavalier>(false));

    //Reines
    setPiece(make_pair(7,3), make_unique<Reine>(true));

    setPiece(make_pair(0,3), make_unique<Reine>(false));

    //Roi
    setPiece(make_pair(7,4), make_unique<Roi>(true));

    setPiece(make_pair(0,4), make_unique<Roi>(false));

    //Fou
    setPiece(make_pair(7,2), make_unique<Fou>(true));
    setPiece(make_pair(7,5), make_unique<Fou>(true));

    setPiece(make_pair(0,2), make_unique<Fou>(false));
    setPiece(make_pair(0,5), make_unique<Fou>(false));


    //Tours
    setPiece(make_pair(7,0), make_unique<Tour>(true));
    setPiece(make_pair(7,7), make_unique<Tour>(true));

    setPiece(make_pair(0,0), make_unique<Tour>(false));
    setPiece(make_pair(0,0), make_unique<Tour>(false));

};


int modele::Echequier::distance(const pair<int,int> &coordoneeInit,const pair<int,int> &coordoneeFinale) const
{
    return abs(coordoneeInit.first - coordoneeFinale.first);
}

pair<int,int> modele::Echequier::getRoi(bool couleur) const
{
    for (auto const& cases: cases_)
    {
        Piece* p = cases.second->getPieces();
        if (p != nullptr && p->getCouleur() == couleur && p->getTypePiece() == ROI)
            return cases.first;


    }
    return make_pair(0,0);
}

vector<pair<int,int>> modele::Echequier::getCoordoneePiece(bool couleur) const
{
    vector<pair<int,int>> emplacement;
    emplacement.reserve(cases_.size());

    for (auto const& cases : cases_)
    {
        Piece* p = cases.second->getPieces();

        if (p != nullptr && p->getCouleur() == couleur)
        {
            emplacement.push_back(cases.first);
        }
    }
    return emplacement;
}

bool modele::Echequier::mouvementLegal(const pair<int,int> &coordoneeInit,const pair<int,int> &coordoneeFinale) const
{
    if (!dansJeu(coordoneeInit) || !dansJeu(coordoneeFinale))
    {
        return false;
    }

    // Check if to location is occupied by piece of same color
    if (couleurNonValide(coordoneeInit, coordoneeFinale))
    {

        return false;
    }

    // Check if this is a valid move for this piece
    const Piece *piece = getPiece(coordoneeInit);
    if (piece == nullptr)
    {

        return false;
    }
    if (!piece->mouvementLegal(this, coordoneeInit, coordoneeFinale))
    {
        return false;
    }

    return true;
}


bool modele::Echequier::mouvementPiece(const pair <int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale)
{
    if(mouvementLegal(coordoneeInit, coordoneeFinale))
    {
        if (cases_[coordoneeFinale]->getPieces() != nullptr)
        {
            size_t i = mouvement_.size();
            pieceCapturer_.insert(pair<int,unique_ptr<Piece>>(i, setPiece(coordoneeInit, nullptr)));
        }
        setPiece(coordoneeFinale, setPiece(coordoneeInit, nullptr));
        getPiece(coordoneeFinale)->incrementer();
        mouvement_.emplace_back(coordoneeInit, coordoneeFinale);
        return true;
    }
   return false;
}

bool modele::Echequier::dansJeu(const pair<int,int> &coordonee) const
{
    if (coordonee.first < 0 || coordonee.first > 7)
    {
        return false;
    }
    else if (coordonee.second < 0 || coordonee.second > 7)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool modele::Echequier::positionNonValide(const pair<int,int> &coordonee) const
{
    return getPiece(coordonee) != nullptr;
}

vector<pair<int,int>> modele::Echequier::getCoordonee() const
{
    vector<pair<int,int>> emplacement;
    emplacement.reserve(cases_.size());
    for (auto const& cases : cases_)
    {
        emplacement.push_back(cases.first);
    }
    return emplacement;
}

unique_ptr<modele::Piece> modele::Echequier::setPiece(const pair<int,int> &coordonee, unique_ptr<Piece> p)
{
    return cases_[coordonee]->setPiece(move(p));
}

modele::Piece* modele::Echequier::getPiece(const pair<int,int> &coordonee) const
{
    return cases_.find(coordonee)->second->getPieces();
}



void modele::Echequier::afficher() const
{
    int i = 1;
    for (auto const &[key, val] : cases_)
    {
        const Piece* p = cases_.find(key)->second->getPieces();
        if (p == nullptr)
        {
            cout << " -- ";
        }
        else
        {
            cout << "00";
        }

        if (i % 8 == 0)
        {
            cout << "\n";
        }
        i++;
    }
    cout << "\n" << "\n";
}

bool modele::Echequier::bougerPiece(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale)
{
    if (mouvementLegal(coordoneeInit, coordoneeFinale))
    {
        if (cases_[coordoneeFinale]->getPieces() != nullptr)
        {
            size_t index = mouvement_.size();
            pieceCapturer_.insert(pair<int, unique_ptr<Piece>>(index, setPiece(coordoneeFinale, nullptr)));
        }

        setPiece(coordoneeInit, setPiece(coordoneeInit, nullptr));
        getPiece(coordoneeInit)->incrementer();
        mouvement_.emplace_back(coordoneeInit, coordoneeFinale);

        return true;
    }

    return false;
}


void modele::Echequier::pieceForcer(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale)
{
    setPiece(coordoneeFinale, setPiece(coordoneeInit, nullptr));
}

bool modele::Echequier::couleurNonValide(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    const Piece *PieceInit = getPiece(coordoneeInit);
    bool couleurInit;
    if (PieceInit != nullptr)
    {
        couleurInit = PieceInit->getCouleur();
    }
    else
    {
        return false;
    }

    const Piece *PieceFinale = getPiece(coordoneeFinale);
    bool couleurFinale;
    if (PieceFinale != nullptr)
    {
        couleurFinale = PieceFinale->getCouleur();
    }
    else
    {
        return false;
    }

    return couleurInit == couleurFinale;
}


bool modele::Echequier::couleurDiffNonValide(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    const Piece *PieceInit = getPiece(coordoneeInit);
    bool couleurInit;
    if (PieceInit != nullptr)
    {
        couleurInit = PieceInit->getCouleur();
    }
    else
    {
        return false;
    }

    const Piece *PieceFinale = getPiece(coordoneeFinale);
    bool couleurFinale;
    if (PieceFinale != nullptr)
    {
        couleurFinale = PieceFinale->getCouleur();
    }
    else
    {
        return false;
    }

    return couleurInit != couleurFinale;

}

bool modele::Echequier::mouvementVerticale(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{

    return coordoneeInit.second == coordoneeFinale.second;

}

bool modele::Echequier::mouvementHorizontale(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    return coordoneeInit.first == coordoneeFinale.first;
}
bool modele::Echequier::mouvementDiagonale(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const
{
    int avancementHorizontal = coordoneeFinale.second - coordoneeInit.second;
    int avancementVertical = coordoneeFinale.first - coordoneeInit.first;
    return abs(avancementHorizontal) == abs(avancementVertical);
}
bool modele::Echequier::avancer(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale, const Piece* piece) const
{
    bool couleurPiece = piece->getCouleur();
    if(couleurPiece  == false && coordoneeInit.first < coordoneeFinale.first)
    {
        return true;
    }
    else if(couleurPiece  == true && coordoneeInit.first > coordoneeFinale.first)
    {
        return true;
    }
    return false;

}
bool modele::Echequier::cavalierBouger(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale) const
{
    int avancementHorizontal = abs(coordoneeFinale.second - coordoneeInit.second);
    int avancementVertical = abs(coordoneeFinale.first - coordoneeInit.first);
    if((avancementVertical ==2 && avancementHorizontal == 1) || (avancementVertical ==1 && avancementHorizontal == 2))
        return true;

    return false;

}
bool modele::Echequier::caseLibre(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale) const
{
    int longueurMouvement = distance(coordoneeInit, coordoneeFinale);
    bool mouvementVert = mouvementVerticale(coordoneeInit, coordoneeFinale);
    bool mouvementHoriz = mouvementHorizontale(coordoneeInit, coordoneeFinale);
    bool mouvementDiag = mouvementDiagonale(coordoneeInit, coordoneeFinale);
    bool changerCamp = coordoneeInit.first < coordoneeFinale.first;
    bool  changerCote = coordoneeInit.second < coordoneeFinale.second;

    if (longueurMouvement == 0 || longueurMouvement == 1)
    {
        return true;
    }

    pair<int,int> coordInit = coordoneeInit;
    pair<int,int> coordFinale = coordoneeFinale;
    if (mouvementVert)
    {
        if (!changerCamp)
        {
            swap(coordInit, coordFinale);
        }

        for (int i = coordInit.first + 1; i < coordFinale.first; i++)
        {
            if (positionNonValide(make_pair(i, coordFinale.second)))
            {
                return false;
            }
        }

        return true;
    }
    else if (mouvementHoriz)
    {
        if (!changerCote)
        {
            swap(coordInit, coordFinale);
        }

        for (int i = coordInit.second + 1; i < coordoneeFinale.second; i++)
        {
            if (positionNonValide(make_pair(coordInit.first, i)))
            {
                return false;
            }
        }
        return true;
    }
    else if (mouvementDiag)
    {
        if (changerCamp == changerCote)
        {

            if (!changerCamp && !changerCote)
            {
                swap(coordInit, coordFinale);
            }

            int col = coordInit.second + 1;
            for (int row = coordInit.first + 1; row < coordoneeFinale.first; row++)
            {
                if (positionNonValide(make_pair(row, col)))
                {
                    return false;
                }
                col++;
            }

            return true;

        }
        else if (changerCamp != changerCote)
        {
            if (changerCamp && !changerCote)
            {
                swap(coordInit, coordFinale);
            }

            int col = coordInit.second + 1;
            for (int row = coordInit.first - 1; row > coordoneeFinale.first; row--)
            {
                if (positionNonValide(make_pair(row, col)))
                {
                    return false;
                }
                col++;
            }


            return true;
        }
    }
    return false;
}
