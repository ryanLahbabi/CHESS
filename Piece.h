/*
Partie 1: Nos deux namespace différents sont namespace modele( On le retrouve dans Piece.h, Roi.h, Tour.h, echequier.h, Regle.h, jeu.h )
 et namespace vue(on le retrouvedans mainwindow.h).

Partie 2: Dans notre fichier Roi.h vous trouverez le compteur d'instances de roi et  l'excpetion lancée au cas où
 il y a plus de deux roi avec le message d'erreur. Nous voulions implémenter l'exception dans Roi.cpp mais cela nous donnait des erreurs de compilation

Partie 3: La classe d'implémentation du RAII est dans Piece.cpp, vous y trouverez les 3 étapes demandée soit ajouter une Piece temporairement,
vérifier la mise en échec, enlever la piece à l'aide du shared_ptr qui détruira automatiquement la piece grâce aux pointeurs intelligents
 et enfin le retour du test mise en échec. Malheureusement, nous avons dû commenter nos deux fonction ajouter et enlever piece car ces deux
fonctions proviennet de echequier.h et nous devons régler un problème de compilation à cause de l'inclusion de nos en-têtes
*/



#ifndef PIECE_H
#define PIECE_H

#endif // PIECE_H
#include <QObject>
#include <cmath>
#include <iostream>


using namespace std;

namespace modele{

class Piece
{
public:
    Piece() = default;
    Piece(int x, int y, bool couleur);//bool = true --> Blanc
    virtual ~Piece() = default;

    int& getX(){return x_;}
    int& getY(){return y_;}

    //template <typename T>
    virtual bool Raii(shared_ptr<Piece> piecePtr);
    bool& getCouleur() {return couleur_;}
    void deplacement();
    bool mouvementLegalverification();
    bool miseEnEchec();

protected:
    shared_ptr<Piece> piecePtr_ = nullptr;
    int x_ = 0;
    int y_ = 0;
    bool couleur_ = true;// Si cest faux(0) la piece noir, si c'est true(1) la piece blanche


};
}
