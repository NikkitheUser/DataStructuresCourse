
//title: Lab7_1.cpp
//Abstract: We will search an array for an entered value by using a binary search function
//ID: 1507
//Name: Nicole Safty
//Date: 10/08/2021

// An exercise program to conduct the binary search.
#include <iostream>
using namespace std;

// Function prototype
int binarySearch(int data[], int size, int value);

// Array size
const int SIZE = 20;

int main()
{
   int numbers[SIZE] = {75, 82, 87, 98, 100, 207, 222,
                       234, 289, 296, 310, 319, 388, 394,
                       417, 429, 447, 521, 536, 600};
   int inputNum;
   int result;

   cout << "Enter a number to search: ";
   cin >> inputNum;
   
   // Search the array to find the location of the input number.
   result = binarySearch(numbers, SIZE, inputNum);
   
   if (result == -1)
   {
      cout << inputNum << " doesn't exist." << endl;
   }
   else
   {
      cout << inputNum << " is at the index " << result << endl;
   }
   
   return 0;
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. The array named data has a maximum of size    *
// elements and is searched for the number stored in value.     *
// If the number is found, its array subscript is returned.     *
// Otherwise, -1 is returned to indicate the value was not in   *
// the array.                                                   *
//***************************************************************

int binarySearch(int data[], int size, int value)
{
  int first=0;
  int middle=10;
  int last=20;

  if(value==data[middle]){//if the value is in the middle, return middle
    return middle;
  }
  if(value>data[middle]){//if value is bigger than middle, search from middle to SIZE
    for(int i=middle;i<=last;i++){
      if(value==data[i]){
        return i;
      }
    }
  }
  if(value<data[middle]){//if value is less than middle, search from 0 to middle
    for(int j=middle;j>=first;j--){
      if(value==data[j]){
        return j;
       
      }
    }
  }
return -1;
}

