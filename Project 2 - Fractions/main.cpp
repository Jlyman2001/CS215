#include <iostream>
#include "fraction.h"
#include "Recipe.h"

using namespace std;

int main() {

    string recipeName = "Peanut Sauce";
    vector<string> names{"Sweet Chilli Sauce", "Peanut Butter", "Soy Sauce", "Hoisin Sauce"};
    vector<Fraction> quant{Fraction(3, 4), Fraction(4, 3), Fraction(1, 2), Fraction(1, 3)};

    Recipe r3(recipeName, names, quant);
    cout << "\nFollowing Recipe has " << r3.getItems() << " ingredients" << endl;
    cout << r3 << endl;
    

    r3.scaleRecipe(3);
    cout << "Scaled Recipe to " << r3.getServingSize() << " servings" << endl;
    cout << r3 << endl;

    r3.scaleRecipe(2);
    cout << "Scaled Recipe to " << r3.getServingSize() << " servings" << endl;
    cout << r3 << endl;
    
    Recipe r4("recipeDumplings.txt");
    cout << r4 << endl;

    cout << "Combining " << r3.getRecipeName() << " with " << r4.getRecipeName() << endl;
    Recipe r5 = r3.combineWith(r4);
    cout << r5;
    cout << "--- Combined recipe has " << r5.getItems() << " ingredients ---" << endl << endl;

    



    
    return 0;
}
