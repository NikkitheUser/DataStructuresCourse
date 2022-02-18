//title: lab13_2.cpp
//Abstract: This program is used to showcase how templates work, we used a template to make a sort function
//ID: 1507
//Name: Nicole Safty
//Date: 12/04/2021
// A sample program to demonstrate the function template in C++.
#include <iostream>
using namespace std;


template <typename T>
void mySort (T first[], int second);

int main( )
{
      int i;
    
    int a[10] = {9, 8, 7, 6, 5, 1, 2, 3, 0, 4};
    cout << "Unsorted integers:\n";
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    mySort(a, 10);
    
    cout << "In sorted order the integers are:\n";
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;
    
    double b[5] = {5.5, 4.4, 1.1, 3.3, 2.2};
    cout << "Unsorted doubles:\n";
    for (i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    
    mySort(b, 5);
    
    cout << "In sorted order the doubles are:\n";
    for (i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl << endl;
    return 0;
}

template <typename T>
void mySort (T first[], int second) 
{ 
 int i,j,tmp;
 int iMin;

    for( i = 0; i < second-1; i++ ) 
	{
        // find the index of the minimum value
        // in x[i], x[i+1], … x[n-1];
        iMin = i;
        for( j = i+1; j < second; j++ )
		{
            if( first[j] < first[iMin])
			{
                iMin = j;
			}
		}
        // swap values[i] and values[iMin]
		 tmp = first[iMin];
		first[iMin] = first[i];
		first[i] = tmp;
    }

	return;
}
