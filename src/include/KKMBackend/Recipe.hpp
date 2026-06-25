#pragma once

#include <string>
#include <vector>

class Recipe
{
public:
    Recipe() = default;
    explicit Recipe(const std::string name) : m_name(std::move(name)){} // std::move to steal resource

    void addIngredient(const std::string& name, int quantity); // should take an unit, maybe a struct, maybe also an ingredient is a class with a given unit associated

    [[nodiscard]] const std::string& getName() const noexcept;

private:
    std::string m_name{"New Recipe"};
    std::vector<std::string> m_ingredients{{}}; // should be a vector if ingredient ? or of struc ingredient + quantity ?
};