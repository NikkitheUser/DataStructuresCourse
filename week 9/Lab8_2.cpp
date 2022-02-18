//title: lab8_2.cpp
//Abstract: This is a dynamic array, the size of the array changes within the program. We now allow the array to take Chars
// the program now takes in chars and sorts them 
//ID: 1507
//Name: Nicole Safty
//Date: 10/22/21
/*
 * A sample solution to calculate the average of several 
 * students using a dynamically allocated array. 
 */
#include <iostream>
using namespace std;
 
int main()
{
    int size;
    char * ptr;

    cout << "Enter the number of chars: ";
    cin >> size; 

    // allocate a dynamic array with the user's input size.
    ptr = new char[size];
cout << "Enter Characters: ";
    char letter;
    for (int i=0; i < size; i++)
    {
        cin >> letter;
        ptr[i]=letter;
    }

    for(int i=0;i<size;i++){
      for(int j=1+i;j<size;j++){
        if(ptr[i]>ptr[j]){
          char temp=ptr[j];
          ptr[j]=ptr[i];
          ptr[i]=temp;
        }
      }
      
    }
    cout<<"Result:"<<endl;
    for(int i=0;i<size;i++){
     cout<<" " <<ptr[i]<<" ";
    }

    // release the dynamic array
    delete [] ptr;
    ptr = nullptr;

    cout << "Bye" << endl;
    
    return 0;
}


