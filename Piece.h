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

#include <iostream>

#ifndef PIECE_H
#define PIECE_H



using namespace std;


namespace modele{


enum TypePiece
{
    ROI,
    REINE,
    CAVALIER,
    FOU,
    TOUR,
    PION
};


class Echequier;
class Piece
{
public:
    Piece(TypePiece, bool couleur);

    virtual ~Piece() = default;

    void setCouleur(bool couleur);
    void setType(TypePiece type);
    void incrementer();
    void decrementer();
    bool getCouleur() const;
    bool deplacement() const;
    TypePiece getTypePiece() const;

    virtual bool Raii(shared_ptr<Piece> piecePtr);


    virtual bool mouvementLegal(const Echequier* echequier,const pair<int,int> &coordoneeInit, const pair<int,int> &coordoneeFinale) const = 0;

protected:
    bool couleur_ = true;// Si cest faux(0) la piece noir, si c'est true(1) la piece blanche
    TypePiece type_;
    int mouvement_;


};
}

#endif // PIECE_H
