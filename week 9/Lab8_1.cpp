//title: lab8_1.cpp
//Abstract: This is a dynamic array, the size of the array changes within the program. We now have to sort numbers that the array is given. 
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
    double * ptr;

    cout << "Enter the number of values: ";
    cin >> size; 

    // allocate a dynamic array with the user's input size.
    ptr = new double[size];
cout << "Enter "<<size<<" values"<<endl;
    double sum = 0;
    double score;
    for (int i=0; i < size; i++)
    {
        
        cin >> score;
        ptr[i]=score;
    }

    for(int i=0;i<size;i++){
      for(int j=1+i;j<size;j++){
        if(ptr[i]>ptr[j]){
          double temp=ptr[j];
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

