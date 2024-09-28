#include <iostream>
#include <iomanip>               // For setprecision
#include <string>
#include <vector>
using namespace std;


/** 
* Function to determine the cost of driving a car
* 
* @param milesPerGallon		The fuel efficiency of the car in miles per gallon
* @param dollarsPerGallon	The cost of gasoline in dollars per gallon
* @param milesDriven		The total distance driven in miles
* 
* @returns totalCost		The calculated total cost of driving
*/
double DrivingCost(double milesPerGallon, double dollarsPerGallon, double milesDriven)
{
	//declare variables to store the return value and an intermediate value in calculations
	double totalCost, gallonsRequired;

	//the amount of fuel required is determined from the fuel efficiency and the distance
	gallonsRequired = (milesDriven / milesPerGallon);

	//the total cost is determined from the cost of the fuel and the amount used
	totalCost = gallonsRequired * dollarsPerGallon;

	return totalCost;
}

//Function to mimic the main() function in lab section 5.24and allow code to be in one source file
void Lab3_5_24(void)
{
	//declare variables to store user input
	double milesPerGallon, dollarsPerGallon;
	
	//read the input for each from the user
	cin >> milesPerGallon;
	cin >> dollarsPerGallon;

	//format output for printing
	cout << fixed << setprecision(2);

	//print the cost for 10 miles
	cout << DrivingCost(milesPerGallon, dollarsPerGallon, 10.0) << " ";

	//print the cost for 50 miles
	cout << DrivingCost(milesPerGallon, dollarsPerGallon, 50.0) << " ";

	//print the cost for 400 miles
	cout << DrivingCost(milesPerGallon, dollarsPerGallon, 400.0) << endl;
}

/**
* Function to remove all non-alphabetic characters from an input string and return the new string
* 
* @param userString			Input string to have non-alphabetic characters removed
* 
* @returns modifiedString	Original string with all non-alphabetic characters removed. Can be empty
*/
string RemoveNonAlpha(string userString)
{
	//declare string to hold input without non-alphabetic characters
	string modifiedString = "";

	//iterate through each character in the input string
	for (int index = 0; index < userString.length(); index++)
	{
		//if the current character is a letter,
		if (isalpha(userString.at(index)))
		{
			//add that character to the output string
			modifiedString.push_back(userString.at(index));
		}
		//otherwise do not add anything

	}

	return modifiedString;
}

//Function to mimic the main() function in lab section 5.29 and allow code to be in one source file
void Lab3_5_29(void)
{
	//declare variable to hold user input
	string inputString;

	//read user input using getline to allow for spaces
	getline(cin, inputString);

	//print output of function
	cout << RemoveNonAlpha(inputString) << endl;
}

/**
* Function to read two sentences into vectors of strings holding one word each
* 
* @param vector<string>& sentence1Words		Vector to store first sentence
* @param vector<string>& sentence2Words		Vector to store second sentence
* @param int wordCount						Integer to determine how many words to read per sentence
* 
* @pre The vectors are the same size as each other and no larger than 20 elements
* 
* @post The vectors of strings will be populated with words read from user input
*/
void ReadSentences(vector<string>& sentence1Words, vector<string>& sentence2Words, int wordCount)
{
	//string to hold user inputs
	string userInput;
	//loop for reading first sentence
	for (int index = 0; index < wordCount; index++)
	{
		//read word from user
		cin >> userInput;

		//store that word into the vector
		sentence1Words.at(index) = userInput;

	}

	//loop for reading second sentence
	for (int index = 0; index < wordCount; index++)
	{
		//read word from user
		cin >> userInput;

		//store that word into the vector
		sentence2Words.at(index) = userInput;

	}
}

//Function to mimic the main() function in lab section 5.41 and allow code to be in one source file
void Lab3_5_41(void)
{
	vector<string> firstSentence(20);
	vector<string> secondSentence(20);
	int wordCount;

	cin >> wordCount;
	// Call ReadSentences() to populate vectors
	ReadSentences(firstSentence, secondSentence, wordCount);
	
	// Display differing word pairs
	//loop through length of sentences
	for (int index = 0; index < wordCount; index++)
	{
		//if the words are not the same
		if (firstSentence.at(index) != secondSentence.at(index))
		{
			//print the two words side by side on the same line
			cout << firstSentence.at(index) << " " << secondSentence.at(index) << endl;
		}
	}


}








/**
* Function to print a report of the contents of a string
* 
* @param int numVowels				The number of vowels to be printed
* @param int numConsonants			The number of consonants to be printed
* @param int numDigits				The number of digits to be printed
* @param int numSpecialChars		The number of special characters to be printed
*/
void printReport(int numVowels, int numConsonants, int numDigits, int numSpecialChars)
{
	cout << "Vowels: " << numVowels << endl;
	cout << "Consonants: " << numConsonants << endl;
	cout << "Digits: " << numDigits << endl;
	cout << "Special characters: " << numSpecialChars << endl;
}

/**
* Function to read user input from cin and return it
* 
* @returns string userInput		The input from the user
*/
string getUserInput(void)
{
	//variable to store user input
	string userInput;

	//read input from user
	getline(cin, userInput);

	//return read input
	return userInput;
}


/**
* Function to determine if a character is a vowel
* 
* @param char inputChar		The character being tested
* 
* @returns bool isVowel		True if the character is a vowel and false otherwise
*/
bool isVowel(char inputChar)
{
	//convert input character to lowercase
	inputChar = tolower(inputChar);

	//test if character is a vowel
	return (inputChar == 'a' || inputChar == 'e' ||
			inputChar == 'i' || inputChar == 'o' ||
			inputChar == 'u');
}

//Function to mimic the main() function in lab section 5.42 and allow code to be in one source file
void Lab3_5_42(void) 
{
	//string for user input
	string userInput = getUserInput();



	//initialize variables to count number of characters in input string
	int numVowels = 0;
	int numConsonants = 0;
	int numDigits = 0;
	int numSpecialChars = 0;

	//iterate over each character of input string
	for (int index = 0; index < userInput.length(); index++)
	{
		//char variable to store current character for readability
		char currentChar = userInput.at(index);

		//test if the character is a digit
		if (isdigit(currentChar))
		{
			//increment counter for digits
			numDigits = numDigits + 1;
		}
		//if it is not a digit, test if it is a letter
		else if (isalpha(currentChar))
		{
			//if the character is a letter, test if it is a vowel
			if (isVowel(currentChar))
			{
				//increment counter for vowels
				numVowels = numVowels + 1;
			}
			//if it is a letter and not a vowel, it is a consonant
			else
			{
				//increment counter for consonants
				numConsonants = numConsonants + 1;
			}
		}
		//if not a number or a letter, it is a special character
		else
		{
			//increment counter for special characters
			numSpecialChars = numSpecialChars + 1;
		}
	}
	//print output report using function
	printReport(numVowels, numConsonants, numDigits, numSpecialChars);
}
int main() {
	//Lab3_5_24();
	//Lab3_5_29();
	//Lab3_5_41();
	//Lab3_5_42();
	return 0;
}
