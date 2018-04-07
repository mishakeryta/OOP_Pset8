#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;
#include <vector>
#include "deposit.hpp"
#include "cumulativedeposit.hpp"
#include "vipdeposit.hpp"
#include "termdeposit.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbtAdd_clicked();

    void on_pbtNextDay_clicked();

private:
    Ui::MainWindow *ui;
    vector<Deposit*> deposits;
};

#endif // MAINWINDOW_H
