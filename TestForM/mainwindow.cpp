#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NewBank newBank;
    PrintBank(&newBank);

}

MainWindow::~MainWindow()
{
    delete ui;
}