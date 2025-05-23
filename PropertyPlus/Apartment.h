#pragma once
#include "Property.h"

class Apartment : public Property {
private:
    double square;

public:
    Apartment();

    Apartment(unsigned int worth, double square);

    void fromJson(const json& j) override;

    json toJson() const override;

    double calculateTax() const override;

    double getSquare() const;
};

