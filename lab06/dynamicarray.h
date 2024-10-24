#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H
#include <assert.h>

class DynamicArray {
   public:
      DynamicArray();

      ~DynamicArray();
      void append(int newVal);
      int at(int index);
      int sum();
      bool remove(int valToDelete); 
      void resize(int newCapacity);
      void print();
      int cap() { return capacity; }

   private:
      int* arr;      // The array
      int len;       // Number of elements actually populated 0 indexed
      int capacity;  // New variable - this is the current capacity of the array

};

#endif // _DYNAMIC_ARRAY_H