#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bank.h"
#include "newbank.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    PrintBank(Bank* bank)
    {
        bank->Print();
    }

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
