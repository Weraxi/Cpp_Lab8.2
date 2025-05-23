#pragma once
#include "Ijsonio.h"

class PropertySimpleFactory {
public:
    static Ijsonio* getProperty(const string& key);
};

