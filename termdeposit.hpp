#ifndef TERMDEPOSIT_H
#define TERMDEPOSIT_H
#include "deposit.hpp"

class TermDeposit:public Deposit
{
public:
    TermDeposit(double money,double coef,unsigned int maxMonth,const string& clientName):
        Deposit(money,coef,maxMonth,clientName) { }
    double findFullIncome() const override;
    string getType() const { return "Term";}
    Deposit& nextMonth();
};
#endif // TERMDEPOSIT_H
