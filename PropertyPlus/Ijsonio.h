#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

// Интерфейс для JSON сериализации
class Ijsonio {
public:
    virtual void fromJson(const json& j) = 0;

    virtual json toJson() const = 0;

    virtual ~Ijsonio();
};

