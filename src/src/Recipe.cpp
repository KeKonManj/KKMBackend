#include "Recipe.hpp"

void Recipe::addIngredient(const std::string &name, int quantity)
{
    m_ingredients.push_back(name);
    // should be a class with name/quantity
}

[[nodiscard]] const std::string &Recipe::getName() const noexcept
{
    return m_name;
}
