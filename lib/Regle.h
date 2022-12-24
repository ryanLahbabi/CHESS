#ifndef REGLE_H
#define REGLE_H

#include <QDebug>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QImage>
#include <QBrush>
#include <string>

namespace modele
{
class Regle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Regle(int x, int y);
    void appuiBouton(QGraphicsSceneMouseEvent *e);
    void setNomPiece(QString );
    QString getNomPiece();
    void setPng(QString adresse);
    QString getPng();
    void clearPng();

private:
    QString nomPiece;
    QGraphicsPixmapItem piece;
    QString png;
    int x_;
    int y_;


signals:
    QString envoyerMessage(QString nomPiece);
};
}


#endif // REGLE_H


