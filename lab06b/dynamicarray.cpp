
#include "dynamicarray.h"
using namespace std;


const int INITIAL_CAP = 10;


/**
 * Constructs a DynamicArray object with an initial capacity of 10.
 * Initializes the internal array and sets length to 0.
 *
 * @post The DynamicArray instance is initialized with an empty array of size INITIAL_CAP (10).
 */
DynamicArray::DynamicArray()
{
	arr = new int[INITIAL_CAP];
	capacity = INITIAL_CAP;
	len = 0;
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
	(*this).arr = new int[other.capacity];
	(*this).len = other.len;
	(*this).capacity = other.capacity;

	for (int index = 0; index < other.len; index++)
	{
		(*this).arr[index] = other.arr[index];
	}
}

/**
 * Destructor for DynamicArray.
 *
 * @post Frees the memory allocated for the internal array.
 */
DynamicArray::~DynamicArray()
{
	delete[] arr;
}

/**
 * Retrieves the element at the specified index in the array.
 *
 * @param  index  The position of the element to retrieve.
 * @return The value at the given index if valid, otherwise returns -11111.
 * @pre    index must be between 0 and len - 1.
 *
 */
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

/**
 * Appends a new integer value to the DynamicArray.
 * If the internal array is full, the capacity is doubled before appending.
 *
 * @param  newVal  The value to append to the array.
 * @post   The new value is added to the array, resizing the array if needed.
 */
void DynamicArray::append(int newVal)
{
	//if there is space for the newVal
	if (len < capacity)
	{
		arr[len] = newVal;
		len++;
	}
	else
		//generate new array and append
	{
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
 */
void DynamicArray::print()
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
		if (i % 10 == 9)
		{
			cout << endl; // newline every 10 elements
		}
	}
	cout << endl;
}

/**
 * Computes the sum of all elements in the array.
 *
 * @return The sum of all elements in the array.
 *
 */
int DynamicArray::sum() const
{
	int sum = 0;
	for (int index = 0; index < len; index++)
	{
		sum += arr[index];
	}
	return sum;
}

/**
 * Removes the first occurrence of a specified value from the array, if present.
 * If the value is found and removed, the array is resized down if it is at less
 * than half capacity
 *
 * @param  valToDelete  The value to be removed from the array.
 * @return True if the value is found and removed, false otherwise.
 * @post   The array is adjusted, shifting elements as necessary and possibly resizing.
 */
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

	if (indexOfValue == -1)
	{
		//value not found
		return false;
	}
	else
	{
		//starting at that index, replace each element with the subsequent one
		for (int index = indexOfValue; index < len; index++)
		{
			arr[index] = arr[index + 1];
		}
		len--;

		//resize down if too small
		int halfCapacity = static_cast<int>(0.5 * capacity);
		int newCapacity = static_cast<int>(0.8 * capacity);
		if (len < halfCapacity || len == 12)
		{
			resize(newCapacity);
		}

		return true;
	}

	//should never get here
	std::cout << "Error in remove()" << std::endl;
	return false;
}

/**
 * Resizes the internal array to a new capacity.
 * If the new capacity is smaller than INITIAL_CAP, it is set to INITIAL_CAP.
 * Copies elements from the old array to the new one.
 *
 * @param  newCapacity  The new capacity for the internal array.
 * @post   The array is resized, and elements from the original array are copied over.
 */
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

ostream& DynamicArray::print(ostream& out)
{

		for (int i = 0; i < len; i++)
		{
			out << arr[i] << " ";
			if (i % 10 == 9)
			{
				out << endl; // newline every 10 elements
			}
		}
		out << endl;
	return out;
}

DynamicArray DynamicArray::operator=(const DynamicArray& other)
{

	if (this == &other)
	{
		return *this;
	}

	delete[](*this).arr;
	(*this).arr = new int[other.capacity];
	(*this).len = other.len;
	(*this).capacity = other.capacity;

	for (int index = 0; index < other.len; index++)
	{
		(*this).arr[index] = other.arr[index];
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray& other)
{
	if (this->capacity == other.capacity && this->len == other.len)
	{
		for (int index = 0; index < this->len; index++)
		{
			if (this->arr[index] != other.arr[index])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}
