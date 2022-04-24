#ifndef QT_H
#define QT_H

#include <QMainWindow>
#include <cmath>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class QT; }
QT_END_NAMESPACE

class QT : public QMainWindow
{
    Q_OBJECT

public:
    QT(QWidget *parent = nullptr);
    ~QT();

private:
    Ui::QT *ui;
};
#endif // QT_H

