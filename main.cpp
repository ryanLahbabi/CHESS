#include "mainwindow.h"
#include "Regle.h"
#include "affichage.h"
#include "echequier.h"
#include "jeu.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    modele::Affichage A;
    QGraphicsView* vue = new QGraphicsView(A.getGraphique());
    vue->show();
    return a.exec();
}
