#pragma once

#include <Quantity.hpp>
#include <chrono>
#include <string>

class Ingredient
{
   public:
    Ingredient() = default;
    explicit Ingredient(std::string name)
        : m_name(std::move(name)){};  // std::move to steal resource

   private:
    std::string m_name{"New Ingredient"};
};

class RecipeIngredient : public Ingredient
{
   public:
    RecipeIngredient() = default;
    explicit RecipeIngredient(std::string name, Quantity quantity)
        : Ingredient(std::move(name)), m_quantity(std::move(quantity)){};

   private:
    Quantity m_quantity{};
};

class StockIngredient : public Ingredient
{
   public:
    StockIngredient() = default;
    explicit StockIngredient(std::string name, Quantity quantity,
                             const std::chrono::year_month_day expireDate)
        : Ingredient(std::move(name)), m_quantity(std::move(quantity)), m_expireDate(expireDate){};

   private:
    Quantity m_quantity{};
    std::chrono::year_month_day m_expireDate{std::chrono::year_month_day{
        std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())}};
};