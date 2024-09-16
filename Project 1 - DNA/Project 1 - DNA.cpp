/*
* Project 1 - DNA.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


int main(int argc, const char* argv[]) {
    // ****** STOP: DO NOT CHANGE THIS FUNCTION FOR THIS CHECKPOINT *******
    string sequence, STR; //strings storing the DNA sequence and the Short Tandem Repeats(STR)
        //Read sequence and STR from standard input
    
    //hard code for testing
    //sequence = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    //STR = "AGAT";
    cin >> sequence;
    cin >> STR;

    //Determine the length of the longest consecutive sequence of STR in the DNA sequence
    int num = numOccurrences(STR, sequence);
    
    //Print out the length
    cout << num << endl;
    //cout << sequence << endl;

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

