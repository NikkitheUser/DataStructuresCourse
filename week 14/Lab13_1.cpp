//title: lab13_1.cpp
//Abstract: This program is used to showcase how templates, we used a template to make the display function work
//ID: 1507
//Name: Nicole Safty
//Date: 12/04/2021
// A sample program to demonstrate the class template in C++.
#include <iostream>
using namespace std;

// Class template declaration for a pair of values of type T:
template<typename T>
class Pair
{
public:
    Pair( );
    Pair(T firstValue, T secondValue);
    void setFirst(T newValue);
    void setSecond(T newValue);
    T getFirst( ) const;
    T getSecond( ) const;
    void display();

private:
    T first;
    T second;
};
//display function here
template<typename T>
void Pair<T>::display(){
cout<<first<<" "<< second<<endl;
}


// Class template member function definitions
// Constructor
template<typename T>
Pair<T>::Pair()
{
    // Intentionally empty
}


// Constructor
template<typename T>
Pair<T>::Pair(T firstValue, T secondValue)
:first(firstValue), second(secondValue)
{
    // Intentionally empty
}


// Accessors and mutators
template<typename T>
void Pair<T>::setFirst(T newValue)
{
    first = newValue;
}


template<typename T>
void Pair<T>::setSecond(T newValue)
{
    second = newValue;
}


template<typename T>
T Pair<T>::getFirst( ) const
{
    return first;
}


template<typename T>
T Pair<T>::getSecond( ) const
{
    return second;
}


int main( )
{
     Pair<char> pc('A', 'B');
    pc.display();    // Should display ‘A’ and ‘B’.
    Pair<int> pi(100, 200);
    pi.display();     // Should display 100 and 200.
    return 0;
}
