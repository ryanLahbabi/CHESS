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

bool modele::Echequier::mouvementValide(const pair<int,int> &coordonee,const pair<int,int> &coordoneeRoi) const
{
    return true;
}

bool modele::Echequier::mouvementPiece(const pair <int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale)
{
    if(mouvementValide(coordoneeInit, coordoneeFinale))
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


