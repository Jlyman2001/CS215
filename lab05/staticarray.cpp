#include <iostream>
#include "staticarray.h"
using namespace std;

/**
 * Destructor (ignore for now)
 * 
 **/
StaticArray::~StaticArray() {

}

/**
* Constructor; initializes array to be empty
* 
*/
StaticArray::StaticArray()
{
    len = 0;
}

/**
* Appends the input value to the back of the StaticArray
* @param inputVal   The value to append
* @returns true if successful, false if not able to append
* @post     the array now contains the input value as the last element
*/
bool StaticArray::append(int inputVal)
{
    if (len + 1 > MAX)
    {
        return false;
    }
    else
    {
        arr[len] = inputVal;
        len++;
        return true;
    }
    
}


/**
* Returns the value at a given index of the StaticArray
* @param index  The index of the value to retrieve
* @returns      The value at index if valid or -11111 otherwise
*/
int StaticArray::at(int index)
{
    if (index < len)
    {
        return arr[index];
    }
    else
        return -11111;
}


/**
* Calculates the sum of all elements of the StaticArray
* @returns      The sum of all elements in the array
*/
int StaticArray::sum()
{
    int sum = 0;
    for (int index = 0; index < len; index++)
    {
        sum += arr[index];
    }
    return sum;
}



/**
 * Print all array elements
 * 
 * @post  Prints the contents of the StaticArray instance
 **/
void StaticArray::print() {
   for (int i = 0; i < len; i++) {
      cout << arr[i] << " ";
      if (i % 10 == 9) {
          cout << endl; // newline every 10 elements
      }
   }
}


/**
* Removes a value from the array
* @param value  The value to remove from the array
* @returns      True if the value was removed, false otherwise
* @post         len is decreased by one and values are shifted forwards to fill removed spot
*/
bool StaticArray::remove(int value)
{
    int indexOfFirstHit = -1;
    for (int index = 0; index < len; index++)
    {
        if (arr[index] == value && indexOfFirstHit == -1)
        {
            indexOfFirstHit = index;
        }
    }

    if (indexOfFirstHit == -1)
    {
        return false;
    }

    for (int index = indexOfFirstHit; index < len - 1; index++)
    {
        arr[index] = arr[index + 1];
    }
    len--;
    return true;
}
