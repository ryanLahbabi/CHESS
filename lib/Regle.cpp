//Cette classe permet de gérer les images .png dans le fichier de resources.

#include "Regle.h"

modele::Regle::Regle(int x, int y)
{
    x_ = x;
    y_ = y;

    piece.setParentItem(this);
}
//A chaque clique, le nom de la regle est emmené au signal de l'interface
void modele::Regle::appuiBouton(QGraphicsSceneMouseEvent *bouton){
    if(bouton->buttons() == Qt::LeftButton){
        qDebug() << "Bouton cliquer " << nomPiece;
    }
    emit envoyerMessage(nomPiece);
}

void modele::Regle::setNomPiece(QString nom){
    nomPiece = nom;
}

QString modele::Regle::getNomPiece(){
    return nomPiece;
}

void modele::Regle::setPng(QString adresse)
{
    png = adresse;
    piece.setPixmap(adresse);
    piece.setPos(x_, y_);
    piece.show();
}

QString modele::Regle::getPng()
{
    return png;

}
void modele::Regle::clearPng()
{
    piece.hide();
}
