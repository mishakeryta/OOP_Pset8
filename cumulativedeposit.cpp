#include "cumulativedeposit.hpp"


CumulativeDeposit::CumulativeDeposit(double money, double coef, unsigned int maxMonth, const string &cliantName):
    Deposit(money,coef,maxMonth,cliantName) { }

Deposit& CumulativeDeposit::nextMonth() {
    ++m_currentMonth;
    if(m_currentMonth > m_maxMonth) return *this;
    m_money += m_money*m_coef;
    return *this;
}

string CumulativeDeposit::getType() const{ return "Cumulative"; }
double CumulativeDeposit::findFullIncome() const
{
    CumulativeDeposit tmp{m_money,m_coef,m_maxMonth,""};
    for(int i = 0;i < tmp.getMaxMonth()*30;tmp.nextMonth(),++i);
    return tmp.getMoney();

}

