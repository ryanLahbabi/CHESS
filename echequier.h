/*
Partie 1: Nos deux namespace différents sont namespace modele( On le retrouve dans Piece.h, Roi.h, Tour.h, echequier.h, Regle.h, jeu.h )
 et namespace vue(on le retrouvedans mainwindow.h).

Partie 2: Dans notre fichier Roi.h vous trouverez le compteur d'instances de roi et  l'excpetion lancée au cas où
 il y a plus de deux roi avec le message d'erreur. Nous voulions implémenter l'exception dans Roi.cpp mais cela nous donnait des erreurs de compilation

Partie 3: La classe d'implémentation du RAII est dans Piece.cpp, vous y trouverez les 3 étapes demandée soit ajouter une Piece temporairement,
vérifier la mise en échec, enlever la piece à l'aide du shared_ptr qui détruira automatiquement la piece grâce aux pointeurs intelligents
 et enfin le retour du test mise en échec. Malheureusement, nous avons dû commenter nos deux fonction ajouter et enlever piece car ces deux
fonctions proviennet de echequier.h et nous devons régler un problème de compilation à cause de l'inclusion de nos en-têtes

Les avertissements de builds sont juste dû au fait que nous n'utilisons pas encore nos attributs x et y,
nous les utiliserons par la suite que lorsque nous allons définir nos méthode pour chaucune des pièces de l'échiquier.
*/



#ifndef ECHEQUIER_H
#define ECHEQUIER_H

#endif // ECHEQUIER_H
#include <QObject>
#include <cmath>
#include <iostream>
#include <map>
#include <memory>

#include "case.h"

using namespace std;

namespace modele //Ajout de namespace modele
{

class Piece;

class Echequier
{
public:
    Echequier();
    ~Echequier();

    void board();
    void afficher() const;
    void bougerPiece(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale);


    Piece* getPiece(const pair<int,int> &coordonee) const;

    int distance(const pair<int,int> &coordoneeInit,const pair<int,int> &coordoneeFinale) const;


    bool mouvementValide(const pair<int,int> &coordonee,const pair<int,int> &coordoneeRoi) const;
    bool positionNonValide(const pair<int,int> &coordonee) const;
    bool dansJeu(const pair<int,int> &coordonee) const;
    bool couleurNonValide(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const;
    bool couleurDiffNonValide(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const;
    bool mouvementVerticale(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const;
    bool mouvementHorizontale(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const;
    bool mouvementDiagonale(const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const;
    bool avancer(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale, const Piece* piece) const;
    bool cavalierBouger(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale) const;
    bool caseLibre(const pair<int, int> &coordoneeInit, const pair<int, int> &coordoneeFinale) const;
    bool mouvementPiece(const pair <int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale);
    pair<int,int> getRoi(bool couleur) const;
    pair<int,int> getCoordoneeRoi(bool couleur) const;

    vector<pair<int,int>> getCoordoneePiece(bool couleur) const;
    vector<pair<int,int>> getCoordonee() const;
    vector<Piece*> getPieces(bool couleur) const;

    unique_ptr<Piece> setPiece(const pair<int,int> &coordonee, unique_ptr<Piece> p);


private:
    map<size_t, unique_ptr<Piece>> pieceCapturer_;
    map<std::pair<int, int>, std::unique_ptr<Case>> cases_;
    vector<pair<pair<int,int>, pair<int,int>>> mouvement_;

};


}
