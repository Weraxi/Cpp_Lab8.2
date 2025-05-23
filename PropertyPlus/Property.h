#pragma once
#include "Ijsonio.h"
#include "tax_rates.h"

class Property : public Ijsonio {
protected:
    unsigned int worth;

public:
    Property();

    Property(unsigned int worth);

    virtual double calculateTax() const = 0;

    double calculateIncomeTax() const;

    unsigned int getWorth() const;

    void setWorth(unsigned int worth);

    virtual ~Property();
};

