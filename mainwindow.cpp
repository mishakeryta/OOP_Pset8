#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CumulativeDeposit comDeposit {10,21,12,""};
    qDebug()<<comDeposit.getCoef();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtAdd_clicked() {
    Deposit* newElement = nullptr;
    string clientName = ui->eClientName->text().toStdString();
    unsigned int countMonth = ui->eMaxMonth->text().toUInt();
    double moneyAtBegining = ui->eStartMoney->text().toDouble();
    double coef = ui->eCoefficient->text().toDouble();
    if(ui->rbTerm->isChecked()) {
        newElement = new TermDeposit{moneyAtBegining,coef,countMonth,clientName};
    }
    if(ui->rbVIP->isChecked()) {
        double addCoef = ui->eAddCoef->text().toDouble();
        newElement = new VIPDeposit{moneyAtBegining,coef,countMonth,addCoef,clientName};
    }
    if(ui->rbCumulative->isChecked()) {
        newElement = new CumulativeDeposit{moneyAtBegining,coef,countMonth,clientName};
    }
    deposits.push_back(newElement);
    ui->tableWidget->setRowCount(deposits.size());

    ui->tableWidget->setItem(deposits.size()-1,0,
            new QTableWidgetItem(QString::fromStdString(newElement->getClientName())));
    ui->tableWidget->setItem(deposits.size()-1,1,
            new QTableWidgetItem(QString::fromStdString(newElement->getType())));
    ui->tableWidget->setItem(deposits.size()-1,2,
            new QTableWidgetItem(QString::number(newElement->getCoef())));
    ui->tableWidget->setItem(deposits.size()-1,3,
            new QTableWidgetItem(QString::number(newElement->getMaxMonth())));
    ui->tableWidget->setItem(deposits.size()-1,4,
            new QTableWidgetItem(QString::number(newElement->getMoneyAtBegining())));
    ui->tableWidget->setItem(deposits.size()-1,5,
            new QTableWidgetItem(QString::number(newElement->getMoney())));
    ui->tableWidget->setItem(deposits.size()-1,6,
            new QTableWidgetItem(QString::number(newElement->getCurrentMonth())));
}

void MainWindow::on_pbtNextDay_clicked() {
    for(unsigned int i = 0; i < deposits.size();++i) {
        deposits.at(i)->nextMonth();
        ui->tableWidget->item(i,2)->setText(QString::number(deposits.at(i)->getCoef()));
        ui->tableWidget->item(i,5)->setText(QString::number(deposits.at(i)->getMoney()));
        ui->tableWidget->item(i,6)->setText(QString::number(deposits.at(i)->getCurrentMonth()));
    }
}
