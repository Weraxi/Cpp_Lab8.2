#include "CountryHouse.h"

CountryHouse::CountryHouse() : Property(), distanceFromCity(0) {}

CountryHouse::CountryHouse(unsigned int worth, unsigned int distance) : Property(worth), distanceFromCity(distance) {}

void CountryHouse::fromJson(const json& j) {
    worth = j.at("worth").get<unsigned int>();
    distanceFromCity = j.at("distanceFromCity").get<unsigned int>();
}

json CountryHouse::toJson() const {
    json result;
    result["CountryHouse"]["tax"] = floor(calculateTax() * 100) / 100;
    return result;
}

double CountryHouse::calculateTax() const {
    return distanceFromCity <= TAX_RATES::LIMIT_DISTANCE_FROM_CITY ?
        worth * TAX_RATES::APARTMENT_TAX :
        worth * TAX_RATES::COUNTRY_HOUSE_TAX;
}

unsigned int CountryHouse::getDistanceFromCity() const { return distanceFromCity; }