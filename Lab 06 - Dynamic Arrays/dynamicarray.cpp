#include "dynamicarray.h"

DynamicArray::DynamicArray()
{
	internalData = new int[10];
	maxSize = 1;
	currentIndex = 0;
}

DynamicArray::~DynamicArray()
{
	delete[] internalData;
}

int DynamicArray::at(int index)
{
	if (index < maxSize)
	{
		return internalData[index];
	}
	else
	{
		return 0;
	}
}

void DynamicArray::append(int input)
{
	//if there is space for the input
	if (currentIndex < maxSize - 1)
	{
		internalData[currentIndex] = input;
		currentIndex++;
	}
	else
	//generate new array and append
	{
		//make new array
		int* temporaryArray = new int[maxSize * 2];

		//increase capacity
		maxSize *= 2;
		
		//copy old array
		for (int index = 0; index <= currentIndex; index++)
		{
			temporaryArray[index] = internalData[index];
		}

		//delete old array
		delete[] internalData;

		//point old array to new one
		internalData = temporaryArray;

		//append new value
		internalData[currentIndex] = input;

		//increase index
		currentIndex++;

	}
}

int DynamicArray::cap()
{
	return maxSize;
}

void DynamicArray::print()
{
	for (int index = 0; index < currentIndex; index++)
	{
		std::cout << internalData[index] << " ";
	}
	std::cout << std::endl;
}

int DynamicArray::sum()
{
	int sum = 0;
	for (int index = 0; index < currentIndex; index++)
	{
		sum += internalData[index];
	}
	return sum;
}

bool DynamicArray::remove(int numToRemove)
{
	int indexOfValue = -1;
	for (int index = 0; index < currentIndex; index++)
	{
		if (internalData[index] == numToRemove)
		{
			indexOfValue = index;
		}
	}

	if (indexOfValue == -1)
	{
		//value not found
		return false;
	}
	else
	{
		for (int index = indexOfValue; index < currentIndex - 1; index++)
		{
			internalData[index] = internalData[index + 1];
		}
		currentIndex--;
		return true;
	}

	//should never get here
	std::cout << "Error in remove()" << std::endl;
	return false;
}
