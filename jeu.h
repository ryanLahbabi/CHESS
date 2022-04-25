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



#ifndef JEU_H
#define JEU_H

#endif // JEU_H
#include <echequier.h>
#include <cmath>
#include <iostream>

namespace modele
{

class Jeu
{

public:
    Jeu();
    ~Jeu();
    Echequier& getEchequier(){return echiquier_;};
    void voirCoordonnees(int x, int y);
    void deplacerPiece();
    bool& debutPartie(){return debutPartie_;};
    bool& finPartie(){return finPartie_;};
    bool& miseEnEchec(){return miseEnEchec_;};
    bool& tourJoueur(){return tourJoueur_;};
    bool& gagnant(){return gagnant_;};
    bool& coteReine(){return coteReine_;};
    bool& cliqueSurPiece(){return cliqueSurPiece_;};

private:
    int*   tableau_[8][8];  // tableau de l'échiquier
    Echequier echiquier_;
    bool debutPartie_ = false;
    bool miseEnEchec_ = false; // true
    bool finPartie_ = false; // true le jeu est finit
    bool tourJoueur_ = false; //true = blanc
    bool gagnant_ = false;    //true = blanc
    bool coteReine_ = true; //cote_Reine = true
    bool cliqueSurPiece_ = false;


};
}
