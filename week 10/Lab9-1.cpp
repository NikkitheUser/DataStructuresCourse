//title: lab9_1.cpp
//Abstract: This is a lab to introduce the concept of the Big 3; Destructor, Copy Constructor and Assignment Operator
//ID: 1507
//Name: Nicole Safty
//Date: 10/29/21

/* -----------------------------------------------------------------
  A sample list with a dynamic array
  Original source: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap06/Figure6.1/
  Updated by Dr. Byun for CST238.

  Basic operations are:
    Constructor
    empty:    Check if list is empty
    insert:   Insert a value into the list at a given position.
    erase:    Remove a value from the list at a given position.
    display:  Output the list
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

class List
{
public:
    List();    // Constructor. Default 50
    List(int capacityValue);
       int getCapacity( ) const { return myCapacity; }
    int getNumberUsed( ) const { return mySize; }
     ~List( );              // Destructor
     List(const List& org); // Copy constructor
     List& operator =(const List& rightSide);  // Assignment operator
    bool empty() const; 
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
private:
   int mySize;     // current size of list
   int myCapacity; // capacity of array
   int * myArray;  // pointer to dynamic array
}; 


//--- Definition of class constructor
List::List()     
: mySize(0), myCapacity(50)
{
    myArray = new int[myCapacity];
}

//Destructor
List::~List( )
{
    delete [] myArray;
}

// Copy constructor
List::List(const List& org)
  :myCapacity(org.getCapacity( )), mySize(org.getNumberUsed( ))
{
    myArray = new int[myCapacity];
    for (int i = 0; i < mySize; i++)
    {
        myArray[i] = org.myArray[i];
    }
}

// Assignment operator
List& List::operator =(const List& rightSide)
{
    // Check for self-assignment
    if (this != &rightSide)
    {
        if (myCapacity != rightSide.myCapacity)
        {
            delete [] myArray;
            myArray = new int[rightSide.myCapacity];
        }
    
        myCapacity = rightSide.myCapacity;
        mySize = rightSide.mySize;
        for (int i = 0; i < mySize; i++)
        {
            myArray[i] = rightSide.myArray[i];
        }
    }
    
    return *this;
}

List::List(int capacityValue)     
: mySize(0), myCapacity(capacityValue)
{
    myArray = new int[myCapacity];
}


//--- Definition of empty()
bool List::empty() const
{
    return mySize == 0;
}


//--- Definition of display()
void List::display() const
{
    for (int i = 0; i < mySize; i++)
    {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of insert()
void List::insert(int item, int pos)
{
    if (mySize == myCapacity)
    {
        cout << "*** No more space for a list element -- increase capacity ***\n";
        return;
    }
    if (pos < 0 || pos > mySize)
    {
        cout << "*** Illegal location to insert -- " << pos 
            << ".  List unchanged. ***\n";
        return;
    }

    // First shift array elements right to make room for item
    for(int i = mySize; i > pos; i--)
    {
        myArray[i] = myArray[i - 1];
    }

    // Now insert item at position pos and increase list size  
    myArray[pos] = item;
    mySize++;
}


//--- Definition of erase()
void List::erase(int pos)
{
    if (mySize == 0)
    {
        cout << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize)
    {
        cout << "Illegal location to delete -- " << pos
            << ".  List unchanged. ***\n";
        return;
    }

    // Shift array elements left to close the gap
    for(int i = pos; i < mySize; i++)
    {
        myArray[i] = myArray[i + 1];
    }

    // Decrease list size
    mySize--;
}


//--- Client program to test the List class which uses the dynamic memory.
int main()
{
    List orgList(10);
    
    for (int i = 0; i < 5; i++)
    {
        orgList.insert(i, i);
    }
    cout << "========== Original orgList ==========\n   ";
    orgList.display();
    
    List copyList(orgList);  // Copy constructor
    copyList.insert(400, 0);
    copyList.insert(500, 1);
    
    cout << "\nCopy Constructor Test:\n";
    cout << "========== orgList ==========\n   ";
    orgList.display();
    
    cout << "========== copyList ==========\n   ";
    copyList.display(); 
    
    // Assignment operation
    copyList = orgList;
    orgList.insert(77, 2);
    orgList.insert(88, 5);
    
    cout << "\nAssignment Operator Test:\n";
    cout << "========== orgList ==========\n   ";
    orgList.display();
    
    cout << "========== copyList ==========\n   ";
    copyList.display(); 
    
    return 0;
}