#include <Fou.h>
#include <cmath>
#include <iostream>
using namespace std;

 void modele::Fou::mouvementLegal(Echequier& echiquier, int x, int y )
 {
     int deltaX = 0;
     int deltaY = 0;
     for(int i=0;i<8;i++)
     {
         for(int j=0;j<8;j++)
         {
             if(abs(x-i) ==abs(y-j) && i != x && j!=y)
             {
                 if(i-x <0)
                     deltaX = -1;
                 else if(i-x >0)
                     deltaX = 1;
                 if(j-y <0)
                     deltaY = -1;
                 else if(j-y >0)
                     deltaY = 1;


         }
         int k = 1;
         for (int k=1; k <= abs(x - i);)
         {
         //    if(echiquier.getPiece(x + deltaX * k, y + deltaY * k)!= nullptr)
           //  {
                k++;
             //   break;
             }
             k++;
         }


     }
 }

 namespace modele
 {
 void Raii(Fou& fou)
 {
     if (fou.getFou().use_count() == 0)
     {
             fou.~Fou();
     }
 }
 }
