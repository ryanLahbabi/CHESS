// Voici toutes nos classe pour l'instant il y a encore beaucoup d'erreurs de compilation que nous n'avons pas encore eu le te temps de régler
//aussi le code de notre interface est disponible dans qt.cpp et sera pret à etre exectuer une fois que l'on aura plus autant d'erreurs.
// Pour l'instant nous avons implémenté seulement 3 pieces comme demander Tour, fou et Roi, nous comptons faire les autres pieces ue fois que l'on aura corrigé les erreurs.


#ifndef PIECE_H
#define PIECE_H

#endif // PIECE_H
#include <QObject>
#include <cmath>
#include <iostream>
#include <Regle.h>

using namespace std;

namespace modele{

class Piece: public Regle
{
public:
    Piece() = default;
    Piece(int x, int y, bool couleur);//bool = true --> Blanc
    virtual ~Piece() = default;
    virtual void deplacement(Echequier& echiquier);


    int& getx(){return x_;}
    int& gety(){return y_;}
    bool& getcouleur() {return couleur_;}

protected:
    int x_ = 0;
    int y_ = 0;
    bool couleur_ = true;// Si cest faux(0) la piece noir, si c'est true(1) la piece blanche

};
}


//class Fou:public Piece
//{
//public:
//    Fou(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
//    {
//        couleur_ = couleur;
//    }
//     void mouvementLegal(int x, int y ) override;
//     int deltaX;
//     int deltay;
//protected:
//    const int MAXMOUVEMENTX = 7;
//    const int MAXMOUVEMENTY = 7;

//};
//class Tour:public Piece
//{
//public:
//    Tour(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
//    {
//        couleur_ = couleur;
//    }
//     void mouvementLegal(int x, int y) override;

//protected:
//    const int MAXMOUVEMENTX = 7;
//    const int MAXMOUVEMENTY = 7;
//};

////On garde en dernier (compliquer)
//class Reine: public Piece
//{
//public:
//    Reine();
//     void mouvementLegal(int x, int y) override;
//};


//class Pion:public Piece
//{
//public:
//    Pion(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
//    {
//        couleur_ = couleur;
//    }
//    void mouvementLegal(int x, int y ) override;
//private:
//    const int MAXMOUVEMENTX = 1;
//    const int MAXMOUVEMENTY = 1;
//};

//class Cavalier:public Piece
//{
//public:
//    Cavalier(int x, int y, bool couleur ): Piece::Piece(x,y,couleur)
//    {
//        couleur_ = couleur;
//    }
//    void mouvementLegal(int x, int y) override;
//private:
//    const int mouvement1 = 2;
//    const int mouvement2 = 1;  //permet le mouvement en L

//};
//}

