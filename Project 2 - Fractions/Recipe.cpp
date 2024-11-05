#include "Recipe.h"

Recipe::Recipe()
{

}

Recipe::Recipe(std::string recipeNameInput, std::vector<std::string> ingredientListInput, std::vector<Fraction> ingredientQuantitiesInput)
{
	recipeName = recipeNameInput;
	ingredientList = ingredientListInput;
	ingredientQuantities = ingredientQuantitiesInput;
}

Recipe::Recipe(std::string filename)
{
	std::fstream fileStream;
	fileStream.open(filename);

	std::string line;
	std::stringstream lineISS;
	std::getline(fileStream, line);
	lineISS.str(line);

	std::string newRecipeName = "";

	//read recipe in word by word
	std::string word;
	while (lineISS >> word)
	{
		newRecipeName += word;
	}
	this->recipeName = newRecipeName;

	//while there is still file to read
	//read ingredient quantity and then name
	//push these values to vectors
	while (std::getline(fileStream,line))
	{
		//set stringstream to read line
		lineISS.clear();
		lineISS.str(line);

		//set up string and stream for reading quantity
		std::string quantity;
		lineISS >> quantity;
		Fraction ingredientQuantity;

		//parse for quantity
		int indexOfSlash = quantity.find('/');
		if (indexOfSlash == std::string::npos)
		{
			//quantity is whole
			std::stringstream wholeNumQuantitySS;
			wholeNumQuantitySS.str(quantity);
			int count;
			wholeNumQuantitySS >> count;
			ingredientQuantity = Fraction(count, 1);
		}
		else
		{
			//quantity is fraction
			std::stringstream fracSS;
			fracSS.str(quantity);
			int num, den;
			fracSS >> num;
			//ignore the slash
			fracSS.ignore(1);
			fracSS >> den;
			ingredientQuantity = Fraction(num, den);

		}

		//fraction is set up now
		//add it to the list
		ingredientQuantities.push_back(ingredientQuantity);

		//read ingredient name next
		std::string ingredientName;
		//read ingredient name to str
		std::getline(lineISS, ingredientName);
		//convert to stringstream to use extraction operator
		std::stringstream ingredientNameSS;
		ingredientNameSS.str(ingredientName);
		//reset name string to build onto
		ingredientName = "";
		while (ingredientNameSS >> word)
		{
			ingredientName = ingredientName + word + " ";
		}
		//remove last space from ingredient
		ingredientName = ingredientName.substr(0, ingredientName.length() - 1);
		//add ingredient to list
		ingredientList.push_back(ingredientName);
	}

}

int Recipe::getItems() const
{
	return ingredientList.size();
}

void Recipe::scaleRecipe(int newServingSize)
{
	for (Fraction& frac : ingredientQuantities)
	{
		//scale down to 1 serving
		frac = frac.dividedBy(numServings);
		//scale up to however many
		frac = frac.multipliedBy(newServingSize);
	}
	numServings = newServingSize;
}

Recipe Recipe::combineWith(const Recipe& other) const
{
	Recipe combined;
	std::string combinedName = this->getRecipeName() + " with " + other.getRecipeName();
	combined.recipeName = combinedName;

	combined.ingredientList = this->getIngredientNames();
	combined.ingredientQuantities = this->getIngredientQuantities();
	//adjust to make only one serving
	for (Fraction& frac : combined.ingredientQuantities)
	{
		frac = frac.dividedBy(this->numServings);
	}

	//read second recipe list
	//for each item in the second recipe, compare against all the ingredients in the first list
	for (int otherIndex = 0; otherIndex < other.getItems(); otherIndex++)
	{
		bool isInRecipe = false;
		int indexInCombinedRecipe = -1;
		for (int combinedIndex = 0; combinedIndex < combined.getItems(); combinedIndex++)
		{
			if (other.getIngredientNames().at(otherIndex) == combined.getIngredientNames().at(combinedIndex))
			{
				isInRecipe = true;
				indexInCombinedRecipe = combinedIndex;
			}
		}
		//if the item is already in the recipe
		if (isInRecipe)
		{
			Fraction baseQuantity1 = combined.ingredientQuantities.at(indexInCombinedRecipe);
			Fraction baseQuantity2 = other.ingredientQuantities.at(otherIndex);
			Fraction adjustedQuantity1 = baseQuantity1.dividedBy(combined.numServings);
			Fraction adjustedQuantity2 = baseQuantity1.dividedBy(other.numServings);
			//sum quantities from both
			Fraction combinedQuantity = adjustedQuantity1.addedTo(adjustedQuantity2);
			//set combined ingredient total to sum
			combined.ingredientQuantities.at(indexInCombinedRecipe) = combinedQuantity;
		}
		//otherwise add item as new
		else
		{
			combined.ingredientList.push_back(other.ingredientList.at(otherIndex));
			Fraction baseQuantity = other.ingredientQuantities.at(otherIndex);
			Fraction adjustedQuantity = baseQuantity.dividedBy(other.numServings);
			combined.ingredientQuantities.push_back(adjustedQuantity);
		}
	}
	return combined;
}

std::ostream& operator<<(std::ostream& out, const Recipe& recipe)
{
	//out << "Following Recipe has " << recipe.getItems() << " ingredients" << std::endl;
	out << "--- " << recipe.recipeName << " Recipe for " << recipe.getServingSize() << "--- " << std::endl;
	for (int index = 0; index < recipe.getItems(); index++)
	{
		out << recipe.ingredientList.at(index) << " (" << recipe.ingredientQuantities.at(index) << ")" << std::endl;
	}
	return out;
}


/*
Following Recipe has 4 ingredients
--- Peanut Sauce Recipe ---
Sweet Chilli Sauce (3/4)
Peanut Butter (1/3)
Soy Sauce (1/2)
Hoisin Sauce (1/2)







*/