#include "Car.h"

Car::Car() : Property(), horsepower(0) {}

Car::Car(unsigned int worth, double horsepower) : Property(worth), horsepower(horsepower) {}

void Car::fromJson(const json& j) {
    worth = j.at("worth").get<unsigned int>();
    horsepower = j.at("horsepower").get<double>();
}

json Car::toJson() const {
    double tax = getWorth() * TAX_RATES::CAR_TAX;
    json result;
    result["Car"]["tax"] = floor(calculateTax() * 100) / 100;
    return result;
}

double Car::calculateTax() const {
    if (horsepower < TAX_RATES::LOW_HORSEPOWER)
        return worth * TAX_RATES::CAR_TAX;

    else if (horsepower > TAX_RATES::HIGH_HORSEPOWER)
        return worth * TAX_RATES::CAR_LUXURY_TAX;

    else return worth * TAX_RATES::CAR_TRUCK_TAX;
}

double Car::getHorsepower() const { return horsepower; }