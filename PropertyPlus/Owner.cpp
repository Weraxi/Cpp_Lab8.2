#include "Owner.h"

Owner::Owner() {};

Owner::Owner(const string& fullname, const string& inn) : fullname(fullname), inn(inn) {}

void Owner::fromJson(const json& j) {
    fullname = j.at("fullname").get<string>();
    inn = j.at("inn").get<string>();

    for (const auto& elem : j.at("properties")) {
        string key = elem.items().begin().key();
        Property* p = dynamic_cast<Property*>(PropertySimpleFactory::getProperty(key));
        if (p) {
            p->fromJson(elem.at(key));
            properties.push_back(p);
        }
    }
}

json Owner::toJson() const {
    json result;
    result["fullname"] = fullname;
    result["inn"] = inn;

    std::vector<double> taxes;
    for (const auto& property : properties) {
        taxes.push_back(property->calculateTax());
    }

    double totalTax = 0.0;
    for (double tax : taxes) {
        totalTax += tax;
    }
    result["sumtax"] = floor(totalTax * 100) / 100;

    json propertiesArray = json::array();
    for (const auto& property : properties) {
        propertiesArray.push_back(property->toJson());
    }
    result["properties"] = propertiesArray;

    return result;
}

void Owner::addProperty(Property* property) { properties.push_back(property); }

double Owner::calculateTotalPropertyTax() const {
    double total = 0;
    for (const auto& prop : properties) {
        total += prop->calculateTax();
    }
    return total;
}

const string& Owner::getFullname() const { return fullname; }

const string& Owner::getInn() const { return inn; }

const vector<Property*>& Owner::getProperties() const { return properties; }

Owner::~Owner() {
    for (auto prop : properties)
        delete prop;
}