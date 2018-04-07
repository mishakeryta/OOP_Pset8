#ifndef NEWBANK_H
#define NEWBANK_H
#include "bank.h"

class NewBank : public Bank
{
public:
    NewBank();
    void Print()const override;
};

#endif // NEWBANK_H
