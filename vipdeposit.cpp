#include "vipdeposit.hpp"

double VIPDeposit::findFullIncome() const {
    double fullIncome = m_moneyAtBegining;
    for(int month = 0;month  < m_maxMonth;++month) {
        fullIncome+=fullIncome*(m_coef + m_currentMonth*m_addToCoef);
    }
}

Deposit&  VIPDeposit::nextMonth() {
    ++m_currentMonth;
    if(m_currentMonth > m_maxMonth) return *this;
    m_money += m_money*(m_coef + (m_currentMonth-1)*m_addToCoef);
    return *this;
}

