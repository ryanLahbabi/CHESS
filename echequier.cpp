#include "echequier.h"
#include <cmath>
#include <iostream>
using namespace std;

modele::Echequier::Echequier(){
    modele::Piece piece;
};


int modele::Echequier::distance(const pair<int,int> &coordoneeInit,const pair<int,int> &coordoneeFinale) const
{
    return abs(coordoneeInit.first - coordoneeFinale.first);
}

bool modele::Echequier::mouvementPiece(const pair <int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale)
{
    return true;
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
