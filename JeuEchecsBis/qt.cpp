#include "qt.h"
#include "ui_qt.h"
#include <QPaintEvent>
#include <QWidget>
#include <QMainWindow>
 #include "qpainter.h"

QT::QT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QT)
{
    ui->setupUi(this);
}

QT::~QT()
{
    delete ui;
}
