
//title: hw6_1.cpp
//Abstract: For this lab, we sort the array. But not ascending or descending, we shove the negatives to the front while the positives are in the back
//ID: 1507
//Name: Nicole Safty
//Date: 10/31/21
#include <iostream>
using namespace std;
 
int main()
{
    int size;
    int * ptr;

    cout << "Plese enter the size of your array: ";
    cin >> size; 

    // allocate a dynamic array with the user's input size.
    ptr = new int[size];
cout << "Enter "<<size<<" values for your array:"<<endl;
    int value;
    for (int i=0; i < size; i++)
    {
        
        cin >> value;
        ptr[i]=value;
    }
    int i=0;
    int j=size;
while(j>i){
    for(i=0;i<size;i++){
      for(j=size;j>i;j--){
          if(ptr[i]<0){
          break;}
     else if(ptr[i]>0 && ptr[j]<0){
          int temp=ptr[i];
          ptr[i]=ptr[j];
          ptr[j]=temp;
     }
    }
    }}


    cout<<"Result:"<<endl;
    for(int i=0;i<size;i++){
     cout<<" " <<ptr[i]<<" ";
    }

    // release the dynamic array
    delete [] ptr;
    ptr = nullptr;
cout<<endl;
    cout << "Bye" << endl;
    
    return 0;
}

