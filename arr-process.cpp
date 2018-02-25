/*
Keawa Rozet
CSc 600-01 - Programming Languages
Homework #2
Integer Plot Function
*/

#include <iostream>
#include <stdio.h>
#include <cstring>

void reduce(int* array, int size);

int main(int argc, char const** argv) {
  int array[] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};

  reduce(array, sizeof(array)/sizeof(int));
  return 0;
}

void reduce(int* array, int size) {
  int min = 0;
  int mid = 0;
  int max = 0;
  int end;
  bool erase;

  for (int start = 0; start < size; start++) {
    end = size-(start+1);
    erase = (start >= end);

    printf("Start: %d\tEnd: %d\n", array[start], array[end]);

    if (array[start] > min) {
      if (array[start] > mid) {
        if (array[start] > max) {
          if (erase) {
            
          }
          //number is larger than max, so record the value
           else {
            min = mid;
            mid = max;
            max = array[start];
          }
        }
        if (erase) {

        }
        //number is larger than mid, so record the value
        else {
          min = mid;
          mid = array[start];
        }
      }
      if (erase) {

      }
      //number is larger than min, so record the value
      else {
        min = array[start];
      }
    }
    if (array[end] > min) {
      if (array[end] > mid) {
        if (array[end] > max) {
          // max
        }
      }
    }

  }
}
