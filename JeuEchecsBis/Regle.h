#ifndef REGLE_H
#define REGLE_H

#endif // REGLE_H
#include <QObject>
#include <cmath>
#include <iostream>
#include <utility>


using namespace std;

namespace modele
{
class Echequier;
class Regle
{

 public:
    virtual void mouvementLegal(Echequier& echiquier) = 0;
    virtual ~Regle() = default;
};
}


