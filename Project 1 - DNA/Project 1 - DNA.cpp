// Project 1 - DNA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
* function to find the longest consecutive sequence of Short Tandem Repeats (STR)
in a DNA sequence
*
* @param STR the string storing the Short Tandem Repeat
* @param sequence the string storing the DNA sequence
* @returns the length of the longest consecutive sequence of STR in the DNA
sequence
**/

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

*/

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

int main(int argc, const char* argv[]) {
    // ****** STOP: DO NOT CHANGE THIS FUNCTION FOR THIS CHECKPOINT *******
    string sequence, STR; //strings storing the DNA sequence and the Short Tandem Repeats(STR)
        //Read sequence and STR from standard input
    cin >> sequence;
    cin >> STR;

    //Determine the length of the longest consecutive sequence of STR in the DNA sequence
    int num = numOccurrences(STR, sequence);
    
    //Print out the length
    cout << num << endl;
}


/*
TODO: 
    File Operations:
        Read CSV file into program
        Parse imported CSV for relevant data
    String Manipulation:
        Count longest set of repeating sequences
            Find first occurence of first sequence, iterate through string until it stops finding matches. Count number
            Remove string up until that point
                or
            Find next occurence after index of first one + the length of the sequence
            Iterate through until the string is done
    Compare string match counts against values stored from the file


*/



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

