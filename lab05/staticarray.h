#ifndef _STATIC_ARRAY_H
#define _STATIC_ARRAY_H

// array size limit
const int MAX = 10;

/**
 * Manages an array data structure with a size limit
 * 
 **/
class StaticArray {

   public:
       StaticArray();
      ~StaticArray();
      bool append(int inputVal);
      int at(int index);
      int sum();
      void print();
      bool remove(int value);


   private:
      int arr[MAX]; // array with capacity of MAX elements
      int len;      // current number of elements in the array
};


#endif // _STATIC_ARRAY_H