#include "qt.h"
#include "qpainter.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>




using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Jeu_Echecs_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QT w;
    w.show();

    return a.exec();

   // Jeu jeu;
   // jeu.debutPartie = true;


}
