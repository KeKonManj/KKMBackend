#pragma once

#include <string>

class Quantity
{
   public:
    Quantity() = default;
    explicit Quantity(std::string unit, float value)
        : m_unit(std::move(unit)), m_value(value){};

   private:
    std::string m_unit{"piece"};
    float m_value{0.0};
};
