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

void reduce(int* array, int size);

int main(int argc, char const** argv) {
  int array[] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
  int size = sizeof(array)/sizeof(int);

  std::cout << "\nBefore reduction: ";
  for (int i = 0; i < size; i++)
    std::cout << array[i] << " ";

  reduce(array, size);

  size = sizeof(array)/sizeof(int);
  std::cout << "\nAfter reduction: ";
  for (int i = 0; i < size; i++)
    std::cout << array[i] << " ";
  std::cout << "\n";

  return 0;
}

void reduce(int* array, int size) {
  int min = 0;
  int mid = 0;
  int max = 0;

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

  printf("\nMin: %d\tMid: %d\tMax: %d\n", min, mid, max);
  array = std::remove(array, array + sizeof(array)/sizeof(int), min);
  array = std::remove(array, array + sizeof(array)/sizeof(int), mid);
  array = std::remove(array, array + sizeof(array)/sizeof(int), max);
}
