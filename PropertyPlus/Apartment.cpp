#include "Apartment.h"

Apartment::Apartment() : Property(), square(0) {}

Apartment::Apartment(unsigned int worth, double square) : Property(worth), square(square) {}

void Apartment::fromJson(const json& j) {
    worth = j.at("worth").get<unsigned int>();
    square = j.at("square").get<double>();
}

json Apartment::toJson() const {
    json result;
    result["Apartment"]["tax"] = floor(calculateTax() * 100) / 100;
    return result;
}

double Apartment::calculateTax() const {
    return square <= TAX_RATES::LIMIT_APARTMENT_SQUARE ?
        worth * TAX_RATES::APARTMENT_TAX :
        worth * TAX_RATES::APARTMENT_LUXURY_TAX;
}

double Apartment::getSquare() const { return square; }