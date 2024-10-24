#include <iostream>
#include "dynamicarray.h"
using namespace std;


const int INITIAL_CAP = 10;


DynamicArray::DynamicArray()
{
	arr = new int[INITIAL_CAP];
	capacity = INITIAL_CAP;
	len = 0;
}

DynamicArray::~DynamicArray()
{
	delete[] arr;
}

int DynamicArray::at(int index)
{
	if (index < len && index >= 0)
	{
		return arr[index];
	}
	else
	{
		return -11111;
	}
}

void DynamicArray::append(int newVal)
{
	//if there is space for the newVal
	if (len < capacity)
	{
		//cout << "Had room to append" << endl;
		arr[len] = newVal;
		len++;
	}
	else
		//generate new array and append
	{
		//cout << "Resizing" << endl;

		resize(capacity * 2);

		//append new value
		arr[len] = newVal;

		//increase index
		len++;

	}
}






/**
 * Print all array elements
 * 
 * @post  Prints the contents of the DynamicArray instance
 **/
void DynamicArray::print() {
   for (int i = 0; i < len; i++) {
      cout << arr[i] << " ";
      if (i % 10 == 9) {
          cout << endl; // newline every 10 elements
      }
   }
   cout << endl;
}



int DynamicArray::sum()
{
	int sum = 0;
	for (int index = 0; index < len; index++)
	{
		sum += arr[index];
	}
	return sum;
}

bool DynamicArray::remove(int valToDelete)
{
	//find index of number to delete
	int indexOfValue = -1;
	for (int index = 0; index <= len; index++)
	{
		if (arr[index] == valToDelete)
		{
			indexOfValue = index;

		}
	}

	if (valToDelete == 208)
	{
		//debug breakpoint
		int foo = 0;
		foo++;
	}

	if (indexOfValue == -1)
	{
		//value not found
		return false;
	}
	else
	{
		//print();
		//cout << endl;
		//starting at that index, replace each element with the subsequent one
		for (int index = indexOfValue; index < len; index++)
		{
			arr[index] = arr[index + 1];
		}
		len--;
		
		//resize down if too small
		int halfCapacity = static_cast<int>(0.5 * capacity);
		int newCapacity = static_cast<int>(0.8 * capacity);
		if (len < halfCapacity /*|| len == 12*/)
		{
			resize(newCapacity);
		}

		//print();
		//cout << endl;
		return true;
	}

	//should never get here
	std::cout << "Error in remove()" << std::endl;
	return false;
}


void DynamicArray::resize(int newCapacity)
{
	if (newCapacity < INITIAL_CAP)
	{
		newCapacity = INITIAL_CAP;
	}
	//make new array
	int* temporaryArray = new int[newCapacity];



	//copy old array
	for (int index = 0; index <= len; index++)
	{
		temporaryArray[index] = arr[index];
	}

	//delete old array
	delete[] arr;

	//point old array to new one
	arr = temporaryArray;
	capacity = newCapacity;
}