//title: lab9_2.cpp
//Abstract: This Lab introduces the idea of a bubble sort function. The function will swap the biggest number with the smallest
//ID: 1507
//Name: Nicole Safty
//Date: 10/29/21

// Original source: Gaddis Book: Chapter 7: Programming Challenge #7
// Updated by Dr. Byun for CST238.

#include <iostream>
#include <fstream>
using namespace std;

// Global constant for the array size.
const int ARRAY_SIZE = 10;

// Function prototypes
void readNumbers(ifstream &inFile, int numbers[], int size);
void bubble_sort (int values[], int size);

int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the numbers
    int numbers[ARRAY_SIZE];

    // Open the input file.
    inFile.open("ten_numbers.txt");

    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }

    // Read the numbers into the array.
    readNumbers(inFile, numbers, ARRAY_SIZE);
    
    // Close the file.
    inFile.close();

    cout << "\n=== Input Numbers ===\n";
    for (int i=0; i < ARRAY_SIZE; i++)
        cout << numbers[i] << " ";
    cout << endl;


    // Conduct the bubble sorting
    bubble_sort(numbers, ARRAY_SIZE);
    
    cout << "\n=== Sorted Result ===\n";
    for (int i=0; i < ARRAY_SIZE; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    return 0;
}

// ********************************************************
// The readNumbers function reads numbers from inFile and *
// stores them in the numbers array.                      *
// ********************************************************
void readNumbers(ifstream &inFile, int numbers[], int size)
{
   for (int i = 0; i < size; i++)
      inFile >> numbers[i];
}



// Sort an array of integer values in ascending order.
void bubble_sort (int values[], int size) 
{

   for(int i=0;i<size;i++){
      for(int j=1+i;j<size;j++){
        if(values[i]>values[j]){
          int temp=values[i];
          values[i]=values[j];
          values[j]=temp;
        }
      }
    }

}