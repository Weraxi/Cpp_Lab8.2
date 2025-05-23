#include "Property.h"

Property::Property() : worth(0) {}

Property::Property(unsigned int worth) : worth(worth) {}

double Property::calculateIncomeTax() const { return worth * 0.13; }

unsigned int Property::getWorth() const { return worth; }

void Property::setWorth(unsigned int worth) { this->worth = worth; }

Property::~Property() {};