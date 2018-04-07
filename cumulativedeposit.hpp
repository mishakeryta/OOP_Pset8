#ifndef COMULATIVEDEPOSIT_H
#define COMULATIVEDEPOSIT_H
#include "deposit.hpp"

class CumulativeDeposit:public Deposit
{
public:

    CumulativeDeposit(double money,double coef,unsigned int maxMonth,const string& cliantName);
    Deposit& nextMonth() override;
    virtual string getType()const override;
    double findFullIncome() const override;


};

#endif // COMULATIVEDEPOSIT_H
