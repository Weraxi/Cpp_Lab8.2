#pragma once
#include "Ijsonio.h"
#include "Property.h"
#include "PropertySimpleFactory.h"

class Owner : public Ijsonio {
private:
    string fullname;
    string inn;
    vector<Property*> properties;

public:
    Owner();

    Owner(const string& fullname, const string& inn);

    void fromJson(const json& j) override;

    json toJson() const override;

    void addProperty(Property* property);

    double calculateTotalPropertyTax() const;

    const string& getFullname() const;

    const string& getInn() const;

    const vector<Property*>& getProperties() const;

    ~Owner();
};

