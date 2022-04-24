#include "mainwindow.h"
#include "ui_mainwindow.h"

vue::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

vue::MainWindow::~MainWindow()
{
    delete ui;
}

