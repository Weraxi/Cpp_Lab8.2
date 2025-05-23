#pragma once
#include "Property.h"

class CountryHouse : public Property {
private:
    unsigned int distanceFromCity;

public:
    CountryHouse();

    CountryHouse(unsigned int worth, unsigned int distance);

    void fromJson(const json& j) override;

    json toJson() const override;

    double calculateTax() const override;

    unsigned int getDistanceFromCity() const;
};

