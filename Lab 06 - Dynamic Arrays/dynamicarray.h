#pragma once
#include <iostream>


class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();
	int at(int index);
	void append(int input);
	int cap();
	void print();
	int sum();
	bool remove(int numToRemove);
private:
	int maxSize;		//1 indexed
	int currentIndex;	//0 indexed
	int* internalData;
};