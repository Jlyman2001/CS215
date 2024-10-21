/*
* Project 1 - DNA.cpp : This file contains the 'main' function. Program execution begins and ends there.
* 
* Version 3.0:
*   Added support for input files
*   Formatted functions to allow for file input
*   Meets requirements for checkpoint C / Final
* 
* Version 2.1:
*   Added more comments for checkpoint B.
*   Handled edge case in compareSTRcounts function that was never tested for
*   Removed vestigal code and comments
* Version 2.0:
*   Initial commit for complete submission for checkpoint B.
*   Still needs to have debug code removed and comments added/fixed
* 
* Version 1.1:
*   Updated code after first working run to improve comments and code readability.
* Version 1.0:
*   Code fully functional, works when submitted on ZyBooks
*   Completely reworked function to use erase() instead of weird indexing
* Versions earlier than this did not get version numbers when worked on, more complete version history 
* is available on github at https://github.com/Jlyman2001/CS215/tree/main
* 
* 
* */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//Function Declarations so they can be defined in any order

int numOccurrences(string& STR, string sequence);
bool readData(string filename, vector<string>& nameSTRs, vector<string>& nameIndividuals, vector<vector<int>>& STRcounts);
vector<int> getSTRcounts(string& sequence, vector<string>& nameSTRs);
bool compareSTRcounts(vector<int>& countQuery, vector<int>& countDB);
bool getSequenceFromFile(string filename, string& sequence);

/**
 * Reads from a specified file a list of Short Tandem Repeat (STRs)
 * and their known counts for several individuals
 *
 * @param  filename         the name of the file containing the database of matches
 * @param  nameSTRs         the STRs (eg. AGAT, AATG, TATC)
 * @param  nameIndividuals  the names of individuals (eg. Alice, Bob, Charlie)
 * @param  STRcounts        the count of the longest consecutive occurrences of each STR in the DNA sequence for each individual
 * @pre    nameSTRs, nameIndividuals, and nameSTRs are empty
 * @post   nameSTRs, nameIndividuals and STRcounts are populated with data read from stdin
 * @returns true if the file successfully was read

 **/
bool readData(string filename, vector<string>& nameSTRs, vector<string>& nameIndividuals, vector<vector<int>>& STRcounts)
{
    //string for storing working values
    string word;

    //open file
    ifstream database(filename);

    //if file is not open, return false as an error
    if (!database.is_open())
    {
        return false;
    }

    //string for storing lines of input file
    string line;

    //take first line of input file
    getline(database, line);

    //convert to stringstream
    stringstream lineStream(line);
    
    //read first word from first line ("name")
    getline(lineStream, word, ',');

    //for each remaining word in line, it is a STR 
    while (getline(lineStream, word, ','))
    {
        //add STR to list of them
        nameSTRs.push_back(word);
    }

    //reset position in linestream to allow reuse
    lineStream.clear();

    //all lines after the first share the same format, can be iterated over
    while (getline(database, line))
    {
        //convert each line to stringstream
        stringstream lineStream(line);

        //read name from line
        getline(lineStream, word, ',');

        //push name to list of names
        nameIndividuals.push_back(word);

        //vector to store each individual's STR hits
        vector<int> individualSTRCounts;

        //the rest of the input is the STR count values
        while (getline(lineStream, word, ','))
        {
            //convert string containing number to int
            int STRvalue = stoi(word);

            //append this value to the individual's STR list
            individualSTRCounts.push_back(STRvalue);
        }

        //push vector of ints to STRcounts
        STRcounts.push_back(individualSTRCounts);

        //reset position in linestream to allow reuse
        lineStream.clear();
    }

    //if code reaches this point, it has completed sucessfully
    return true;







    ////variable for the amount of STRs
    //int numSTRs;
    //cin >> numSTRs;



    ////iterate through first line of input, reading STRs
    //for (int index = 0; index < numSTRs; index++)
    //{
    //    //intermediate string for processing
    //    string temp;

    //    //read value into temporary string
    //    cin >> temp;

    //    //add the read STR value to the vector
    //    nameSTRs.push_back(temp);
    //}

    ////string to hold the data for each individual person
    //string individualData;

    ////stringstream variable to manipulate data easier
    //istringstream individualDataStream;

    ////clear \n character
    //cin.ignore(1);
    //
    ////read first line of input
    //getline(cin, individualData);
    //

    //string readName;

    ////as long as the string is not empty, indicating the end of data entry, loop
    //while (individualData != "")
    //{
    //    //convert line into stream for easier use
    //    individualDataStream.str(individualData);

  

    //    //read name until whitespace intermediate variable
    //    individualDataStream >> readName;

    //    //push this name to the vector of names
    //    nameIndividuals.push_back(readName);

    //    //create an integer vector to append to STRcounts
    //    vector<int> personalSTRcounts(numSTRs);

    //    //the number of values to read is the number of STRs entered;
    //    //iterate that many times
    //    for (int index = 0; index < numSTRs; index++)
    //    {
    //        int temp;
    //        //read integer input to vector
    //        individualDataStream >> temp;
    //        personalSTRcounts.at(index) = temp;
    //    }

    //    //push the created vector to the output
    //    STRcounts.push_back(personalSTRcounts);



    //    //read next line of input
    //    getline(cin, individualData);


    //    //clear stringstream for reuse
    //    individualDataStream.clear();

    //}
}

/**
 * Prints a list of Short Tandem Repeat (STRs) and their
 * known counts for several individuals
 *
 * @param   nameSTRs         the STRs (eg. AGAT, AATG, TATC)
 * @param   nameIndividuals  the names of individuals (eg. Alice, Bob, Charlie)
 * @param   STRcounts        the STR counts
 * @pre   nameSTRs, nameIndividuals, and STRcounts hold the data intended to be printed
 * @post the name of individuals and their STR counts in a column-major format are printed to stdout
 **/
void printData(vector<string>& nameSTRs, vector<string>& nameIndividuals, vector<vector<int>>& STRcounts)
{

    //formatting command for print statements
    cout << setw(10) << left;

    //Print the top corner of name table
    cout << "name";

    //iterate through the list of names and print them
    for (int index = 0; index < nameIndividuals.size(); index++)
    {
        cout << setw(10) << nameIndividuals.at(index);
    }
    
    //print line to separate the table
    cout << endl << "----------------------------------------" << endl;


    //iterate through each STR count
    for (int STRnum = 0; STRnum < nameSTRs.size(); STRnum++)
    {
        //print the name of the STR
        cout << setw(10) << nameSTRs.at(STRnum);

        //iterate through each person in the list
        for (int nameNum = 0; nameNum < nameIndividuals.size(); nameNum++)
        {
            //print that person's count for the current STR
            cout << setw(10) << (STRcounts.at(nameNum)).at(STRnum);
        }
        //print a new line to spkit table into different lines
        cout << endl;
    }

    //reset formatting flag
    cout << setw(0);

    return;
}

/**
 * Computes the longest consecutive occurrences of several STRs in a DNA sequence
 *
 * @param   sequence   a DNA sequence of an individual
 * @param   nameSTRs   the STRs (eg. AGAT, AATG, TATC)
 * @returns the count of the longest consecutive occurrences of each STR in nameSTRs

 **/
vector<int> getSTRcounts(string& sequence, vector<string>& nameSTRs)
{
    //vector to store number of matches
    vector<int> matches;

    //python style for loop
    for (string STR : nameSTRs)
    {
        //add the number of occurrences to the return vector
        matches.push_back(numOccurrences(STR, sequence));
    }

    return matches;
}

/**
 * Compares if two vectors of STR counts are identical or not
 *
 * @param   countQuery   STR counts that is being queried (such as that computed from an input DNA sequence)
 * @param   countDB   STR counts that are known for an individual (such as that stored in a database)
 * @returns  a boolean indicating whether they are the same or not

 **/
bool compareSTRcounts(vector<int>& countQuery, vector<int>& countDB)
{
    //flag to store equality value
    bool areEqual = true;

    //make sure they're the same size to prevnt index out of bounds
    if (countQuery.size() == countDB.size())
    {
        //iterate through the entire vector
        for (int index = 0; index < countQuery.size(); index++)
        {
            //if the two values are not equal at any given point, they 
            //aren't identical
            if (countQuery.at(index) != countDB.at(index))
                areEqual = false;
        }
    }
    else
    {
        //if they are different sizes, they are not equal
        areEqual = false;
    }

    return areEqual;
}

/**
* function to find the longest consecutive sequence of Short Tandem Repeats (STR)
in a DNA sequence
*
* @param STR the string storing the Short Tandem Repeat
* @param sequence the string storing the DNA sequence
* @returns the length of the longest consecutive sequence of STR in the DNA
sequence
**/
int numOccurrences(string& STR, string sequence /* NOTE: Passed by copy!*/)
{
    //variable to count the longest repeated sequence of STRs
    int longestSeq = 0;

    //variable to count the length of current STR sequence in loop
    int lengthOfCurrentSeq = 0;

    //unused debug counting variable, used to trace loop execution
    //int debugCount = 0;

    //The loop iterates over the string, removing characters from the string until it is empty
    while (sequence.length() > 0)
    {
        //debug tracing output code
        //cout << "in while loop, step " << debugCount << endl;

        //find the next hit for STR
        int indexOfNextHit = sequence.find(STR,0);

        //debug code for checking indexOfNextHit
        //cout << indexOfNextHit << endl;
        
        //if there is no next hit for STR
        if (indexOfNextHit == string::npos)
        {
            //The program would initially break here, this print was to detect when this branch executed
            //cout << "NPOS" << endl;
            
            //if it doesn't repeat again, we can end execution here
            return longestSeq;
        }

        //if the next STR is not at the start of the string
        else if (indexOfNextHit != 0)
        {
            //Erase all characters up until the STR
            sequence.erase(0, indexOfNextHit);
            lengthOfCurrentSeq = 0;
        }

        //otherwise, the STR begins at the start of the string
        else
        {
            //remove the first N characters of string, to remove next hit of STR
            sequence.erase(0, STR.length());

            //increment length of current sequence
            lengthOfCurrentSeq = lengthOfCurrentSeq + 1;

            //if this is now the longest sequence,
            if (lengthOfCurrentSeq > longestSeq)
            {
                //update the longest sequence count to match
                longestSeq = lengthOfCurrentSeq;
            }
        }
        
        //counter variable for debugging
        //debugCount++;
    }

    //at this point, the string is empty, should only happen if string ends exactly on STR
    //in case this happens, return the sequence number
    return longestSeq;

}


/**
* function to read a sequence as a string from an external file
* 
* @param filename the name of the file to be opened
* @param sequence the string the sequence is stored in
* 
* @returns true if the file opened sucessfully, false otherwise
* @post the sequence parameter contains the content of the file
*/
bool getSequenceFromFile(string filename, string& sequence)
{

    ifstream sequenceFile(filename);

    if (!sequenceFile.is_open())
    {
        return false;
    }

    sequenceFile >> sequence;


    return true;
}

//Old version
//Remnant code preserved for archival purposes
/*
* 
/*
* Tasks:
*   loop through string
*   Find first hit of STR after current position
*   See how many times that sequence of STR repeats
*   if that amount is higher than the previous longest sequence, update that value
*       Because of the nature of the problem, we can just keep going through the string because 
*       reading the same string again will always be shorter than the full repeated STRs
* 
* Pseudocode:


* 
int numOccurrences(string& STR, string& sequence)
{
    
    //variable for final return value
    int longestChainOfOccurrences = 0;

    //ensure length fits to prevent index out of bounds
    if (STR.length() < sequence.length())
    {
        //loop over entire string
        for (int index = 0; index < sequence.length(); index++)
        {
            //find the next hit for STR
            int indexOfNextHit = sequence.find(STR);

            //local variable within the loop to count the current number of occurrences 
            int currentNumOccurrences = 0;

            //boolean flag to escape out of while loop. When the sequence stops being a repeat
            //of the STR it will become false and break out of the loop
            bool isRepeating = true;

            //variable to store the number of characters accounted for by the already counted STRs
            int lengthOfSTRRepeats = 0;

            //see how many times that sequence of STRs repeats
            while (isRepeating)
            {
                //if the length of the STR is longer than what is left in the sequence, it cannot repeat again
                if (STR.length() < (sequence.length() - lengthOfSTRRepeats))
                {

                    //generates a substring at the outer loop index, offset by the amount of previously 
                    //counted characters. This string is the length of the STR so it is robust for
                    //all lengths of STR
                    string nextSTRCheck = sequence.substr((index + lengthOfSTRRepeats), STR.length());

                    //if this new string is a repeat of the STR
                    if (nextSTRCheck == STR)
                    {

                    }



                }

                //if STR is longer than is left, the loop has to stop so isRepeating becomes false
                else
                {
                    isRepeating = false;
                }
            }





        }
    }
    return longestChainOfOccurrences;
}
*/
int main(int argc, const char* argv[]) 
{
    //declare variable to store sequence filename
    string sequenceFilename;
    //read file name from user
    cin >> sequenceFilename;

    //declare variable to store DB filename
    string databaseFilename;
    //read file name from user
    cin >> databaseFilename;

    //string to hold sequence being tested
    string sequence;

    vector<string> nameSTRs; //variable storing the names of the STRs 
    vector<string> nameIndividuals; //variable storing the names of the Individuals 
    vector<vector<int>> STRcountsDB; //variable storing all the known STR counts

    //read sequence from file and test if it was sucessful
    //if the function returns false, the file open failed
    if (!getSequenceFromFile(sequenceFilename, sequence))
    {
        //print error message saying the file failed to read
        cout << "Error in reading DNA sequence from the file: " << sequenceFilename;
        return 1;
    }


    //read DB from file and test if it was sucessful
    //if the function returns false, the file open failed
    if (!readData(databaseFilename, nameSTRs, nameIndividuals, STRcountsDB))
    {
        //print error message saying the file failed to read
        cout << "Error in reading DB file: " << databaseFilename;
        return 1;
    }

    //input to decide if verbose mode is enabled
    int verboseMode;
    cin >> verboseMode;

    //if the user inputs a nonzero value, 
    if (verboseMode)
    {
        //display the match data for all people 
        printData(nameSTRs, nameIndividuals, STRcountsDB);
    }

    cout << endl;

    //regardless of verbose mode, print the rest as normal

    //vector for storing amounts of each str
    vector<int> testSTRs;
    testSTRs = getSTRcounts(sequence, nameSTRs);

    cout << "Counts of the STRs in the DNA sequence is: ";
    for (int index = 0; index < testSTRs.size(); index++)
    {
        cout << testSTRs.at(index) << " ";
    }

    cout << endl;

    //flag variable to store if a match is found
    bool matchFound = false;

    //iterate through all people
    for (int nameIndex = 0; nameIndex < nameIndividuals.size(); nameIndex++)
    {
        //for each person check if they match the given STR counts
        if (compareSTRcounts(testSTRs, STRcountsDB.at(nameIndex)))
        {
            //if they match, print a message saying as much
            cout << "Found Match: " << nameIndividuals.at(nameIndex) << endl;
            matchFound = true;
        }
    }

    //if no match was found, print a message saying as much
    if (!matchFound)
    {
        cout << "No Match Found!" << endl;
    }


}
