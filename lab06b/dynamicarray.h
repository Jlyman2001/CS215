#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H
#include <assert.h>
#include <sstream>
#include <iostream>

using namespace std;

class DynamicArray {
   public:
      DynamicArray();
      DynamicArray(const DynamicArray& other);
      ~DynamicArray();
      void append(int newVal);
      int at(int index);
      int sum() const;
      bool remove(int valToDelete); 
      void resize(int newCapacity);
      void print();
      ostream& print(ostream& out);
      int cap() const { return capacity; }
      DynamicArray operator= (const DynamicArray& other);
      bool operator== (const DynamicArray& other);

   private:
      int* arr;      // The array
      int len;       // Number of elements actually populated 0 indexed
      int capacity;  // New variable - this is the current capacity of the array

};

#endif // _DYNAMIC_ARRAY_H