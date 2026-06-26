#include <Ingredient.hpp>
#include <Recipe.hpp>
#include <iostream>

int main(int, char **)
{
    std::cout << "Hello, from KKMBackend!\n";
    Recipe new_recipe_1;
    Recipe new_recipe_2("ma nouvelle recette de merde");
    std::cout << "new recipe 1 name : " << new_recipe_1.getName() << std::endl;
    std::cout << "new recipe 2 name : " << new_recipe_2.getName() << std::endl;
}
