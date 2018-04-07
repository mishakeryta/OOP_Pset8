#ifndef DEPOSIT_HPP
#define DEPOSIT_HPP
#include <string>
using namespace std;
class Deposit
{
public:
    Deposit(double money,double coef,unsigned int maxMonth,const string& clientName):
        m_money{money},
        m_moneyAtBegining{money},
        m_coef{coef},
        m_maxMonth{maxMonth},
        m_currentMonth{0}
    {
        m_clientName = clientName;
    }

    double getMoney() const {return m_money; }
    double getMaxMonth() const {return m_maxMonth; }
    double getCoef() const {return m_coef; }
    double getMoneyAtBegining() const {return m_moneyAtBegining; }
    double getCurrentMonth() const {return m_currentMonth; }
    const string& getClientName() const { return m_clientName; }
    virtual Deposit &nextMonth() = 0;
    virtual double findFullIncome()const = 0 ;
    virtual string getType() const = 0;

protected:

    double m_money;
    double m_moneyAtBegining;
    double m_coef;
    unsigned int m_maxMonth;
    unsigned int m_currentMonth;
    string m_clientName;
};

#endif // DEPOSIT_HPP
