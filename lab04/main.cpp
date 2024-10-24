#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Do Not Forget to follow style guidelines.
//This lab has points for documenting your code including functions


/**
* Function to print a report of the contents of a string
*
* @param int vowelCount				The number of vowels to be printed
* @param int consoCount			The number of consonants to be printed
* @param int digitCount				The number of digits to be printed
* @param int specialCount		The number of special characters to be printed
*/
void printReport(string line, int vowelCount, int consoCount, int digitCount, int specialCount)
{
	
	cout << setw(35) << left << line;
	cout << "V: " << setw(4) << left << vowelCount;
	cout << "C: " << setw(4) << left << consoCount;
	cout << "D: " << setw(4) << left << digitCount;
	cout << "S: " << setw(4) << left << specialCount  << endl << endl;
}

void writeReport(ofstream& ofs, string line, int vowelCount, int consoCount, int digitCount, int specialCount)
{

	ofs << setw(35) << left << line;
	ofs << "V: " << setw(4) << left << vowelCount;
	ofs << "C: " << setw(4) << left << consoCount;
	ofs << "D: " << setw(4) << left << digitCount;
	ofs << "S: " << setw(4) << left << specialCount << endl << endl;
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

/**
 * Sets the counts for different kinds of characters in a string
 *
 * @param  userText  the input line that is being analyzed
 * @param  vowelCount  the number of vowels in userText
 * @param  consoCount  the number of consonants in userText
 * @param  digitCount  the number of digits in userText
 * @param  specialCount  the number of special characters in userText
 * @pre     vowelCount, consoCount, digitCount and specialCount are zero
 * @post   vowelCount, consoCount, digitCount and specialCount are populated with the respective counts

 **/
void getCount(string userText, int& vowelCount, int& consoCount, int& digitCount, int& specialCount)
{
	//initialize variables to count number of characters in input string
	vowelCount = 0;
	consoCount = 0;
	digitCount = 0;
	specialCount = 0;

	//iterate over each character of input string
	for (int index = 0; index < userText.length(); index++)
	{
		//char variable to store current character for readability
		char currentChar = userText.at(index);

		//test if the character is a digit
		if (isdigit(currentChar))
		{
			//increment counter for digits
			digitCount = digitCount + 1;
		}
		//if it is not a digit, test if it is a letter
		else if (isalpha(currentChar))
		{
			//if the character is a letter, test if it is a vowel
			if (isVowel(currentChar))
			{
				//increment counter for vowels
				vowelCount = vowelCount + 1;
			}
			//if it is a letter and not a vowel, it is a consonant
			else
			{
				//increment counter for consonants
				consoCount = consoCount + 1;
			}
		}
		//if not a number or a letter, it is a special character
		else
		{
			//increment counter for special characters
			specialCount = specialCount + 1;
		}
	}
}

int main()
{
	//string for user input
	string fileName;

	cin >> fileName;

	ifstream inputFS(fileName);

	if (!inputFS.is_open())
	{
		cout << "Could not open file " << fileName << endl;
		return 1;
	}

	ofstream outputFS;
	outputFS.open("data_analysis.txt");


	cout << "Character analysis of each line from file " << fileName << endl << endl;

	cout << setw(35) << left << "Line" << setw(20) << "Character Count" << endl;
	cout << "----------------------------------------------------------------" << endl;


	int vowelCount, consoCount, digitCount, specialCount;
	string line;
	while (getline(inputFS, line))
	{
		getCount(line, vowelCount, consoCount, digitCount, specialCount);


		//print output report using function
		printReport(line, vowelCount, consoCount, digitCount, specialCount);
		writeReport(outputFS, line, vowelCount, consoCount, digitCount, specialCount);

	}

	inputFS.close();
	outputFS.close();
	return 0;
}
