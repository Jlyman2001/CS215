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

int numOccurrences(string& STR, string& sequence)
{
    //variable for final return value
    int occurrences = 0;

    //index for previous hit of sequence
    int indexOfLastSequence = 0;




    //ensure length fits to prevent index out of bounds
    if (STR.length() < sequence.length())
    {
        //loop over entire string
        while (/*Some Condition*/1)
        {

        }
    }
    return occurrences;
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

