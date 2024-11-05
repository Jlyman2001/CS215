#include <vector>
#include "fraction.h"
#include <string>
#include <fstream>
#include <sstream>

class Recipe
{
public:
	Recipe();
	Recipe(std::string recipeNameInput, std::vector<std::string> ingredientListInput, std::vector<Fraction> ingredientQuantitiesInput);
	Recipe(std::string filename); //loads the name, ingredients, and quantity of each recipe from a file
	int getItems() const;
	friend std::ostream& operator<< (std::ostream& out, const Recipe& recipe);
	std::string getRecipeName() const { return recipeName; };
	std::vector<std::string> getIngredientNames() const { return ingredientList; };
	std::vector<Fraction> getIngredientQuantities() const { return ingredientQuantities; };
	int getServingSize() const { return numServings; };
	void scaleRecipe(int newServingSize);
	Recipe combineWith(const Recipe& other) const;

private:
	std::vector<Fraction> ingredientQuantities;
	std::string recipeName;
	std::vector<std::string> ingredientList;
	int numServings = 1;
};