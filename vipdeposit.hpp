#ifndef VIPDEPOSIT_H
#define VIPDEPOSIT_H
#include "cumulativedeposit.hpp"

class VIPDeposit:public CumulativeDeposit
{
public:
    VIPDeposit(double money,double coef, unsigned int maxMonth,double addToCoef,const string& cliantName):
        CumulativeDeposit{money,coef,maxMonth,cliantName},m_addToCoef{addToCoef} { }
    string getType( ) const override{ return "VIP"; }
    double findFullIncome() const override;
    Deposit& nextMonth() override;
private:
    double m_addToCoef;
};

#endif // VIPDEPOSIT_H
