#pragma once
#include "Property.h"

class Car : public Property {
private:
    double horsepower;

public:
    Car();

    Car(unsigned int worth, double horsepower);

    void fromJson(const json& j) override;

    json toJson() const override;

    double calculateTax() const override;

    double getHorsepower() const;
};

