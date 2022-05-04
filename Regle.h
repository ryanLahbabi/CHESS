#ifndef REGLE_H
#define REGLE_H

#endif // REGLE_H

#include <string>
#include <QDebug>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QImage>
#include <QGraphicsRectItem>
#include <QBrush>

namespace modele
{
class Regle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Regle(int x, int y);
    void setNomPiece(QString );
    void appuiBouton(QGraphicsSceneMouseEvent *e);
    void clearPng();
    QString getNomPiece();
    QString getPng();
    void setPng(QString adresse);

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

