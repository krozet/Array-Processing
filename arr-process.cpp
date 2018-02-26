/*
Keawa Rozet
CSc 600-01 - Programming Languages
Homework #2
Integer Plot Function
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <vector>

int reduce(int* array, int size);

int main(int argc, char const** argv) {
  int array[] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
  int size = sizeof(array)/sizeof(int);

  //prints array before the reduce method
  std::cout << "Before reduction: ";
  for (int i = 0; i < size; i++)
    std::cout << array[i] << " ";

  //creates the new reduced array
  int newSize = reduce(array, size);
  int reducedArray[newSize];
  std::copy(array, array + newSize, reducedArray);

  //prints the new array after the reduce method
  std::cout << "\nAfter reduction: ";
  for (int i = 0; i < newSize; i++)
    std::cout << reducedArray[i] << " ";
  std::cout << "\n";

  return 0;
}

int reduce(int* array, int size) {
  int min = 0;
  int mid = 0;
  int max = 0;

  //finds min, mid, max
  for (int i = 0; i < size; i++) {
    if (array[i] > max) {
      min = mid;
      mid = max;
      max = array[i];
    }
    else if (array[i] > mid && array[i] < max) {
      min = mid;
      mid = array[i];
    }
    else if (array[i] > min && array[i] < mid) {
      min = array[i];
    }
  }

  //removes min, mid, and max
  for (int i = 0; i < size; i++) {
    if (array[i] == min || array[i] == mid || array[i] == max) {
      std::copy(array + i+1, array + size, array + i);
      size -= 1;
      i -= 1;
    }
  }
  
  //returns the new size of the array
  return size;
}
