#include "PropertySimpleFactory.h"
#include "Apartment.h"
#include "Car.h"
#include "CountryHouse.h"

Ijsonio* PropertySimpleFactory::getProperty(const string& key) {
    if (key == "Apartment")
        return new Apartment();

    if (key == "Car")
        return new Car();

    if (key == "CountryHouse")
        return new CountryHouse();

    return nullptr;
}
