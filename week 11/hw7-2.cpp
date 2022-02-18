
//title: hw7_2.cpp
//Abstract: for this hw, we add the ability to append a node, remove a the last node and to reset the list with a new capacity
//ID: 1507
//Name: Nicole Safty
//Date: 11/12/21

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
    ~List( );              // Destructor
    List(const List& org); // Copy constructor
    List& operator =(const List& rightSide);  // Assignment operator
    bool empty() const; 
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
    int getMySize();//returns size
      int getMyCapacity( );

      void appendItem(int item);
      bool removeLast(); 
      void reset(int newCapacity); 
private:
   int mySize;     // current size of list
   int myCapacity; // capacity of array
   int * myArray;  // pointer to dynamic array
   int * newArray; //the other dynamic array for reset
  
   
}; 

//mySize 
int List::getMySize(){
return mySize;
}
//myCapacity
int List::getMyCapacity(){
  return myCapacity;
}

//add item to end of list
 void List::appendItem(int item){
   if(mySize==myCapacity){
     myCapacity*=2;
     }
     if(mySize!=myCapacity){
myArray[mySize]=item;
mySize++;
     }
   }

 //remove last
bool List::removeLast(){
  if(!myArray){
    return false;
  }
  else{
    for(int i=mySize;i<myCapacity;i++){
myArray[i]=myArray[i-1];

    }
  }
  mySize--;
return true;
}

//reset the list
void List::reset(int newCapacity)
{
 newArray= new int [newCapacity];

  if(newCapacity > myCapacity||newCapacity==myCapacity){
    for(int i=0;i<mySize;i++){
      newArray[i]=myArray[i];
  } 
  delete [] myArray;
  myArray = newArray;
  }

 if(newCapacity < myCapacity){
   for(int i=0;i<myCapacity-1;i++){
       newArray[i]=myArray[i];
  } 
  delete [] myArray;
  myArray = newArray;
 }
}


// Destructor
List::~List( )
{
    delete [] myArray;
    
  
    
}

// Copy constructor
List::List(const List& org)
  :myCapacity(org.myCapacity), mySize(org.mySize), myArray(org.myArray), newArray(org.newArray)
{ 
myArray = new int[myCapacity];
    for (int i =0; i < mySize; i++){
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


//--- Definition of class constructor
List::List()     
: mySize(0), myCapacity(50)
{
    myArray = new int[myCapacity];
}

//
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
 // Create a small array with capacity is 1.
   List intList(1);
   
   cout << "=== Solution: 1 0 ===\n";
   cout << intList.getMyCapacity() << " " << intList.getMySize();
   intList.appendItem(10);
   intList.appendItem(20);
   cout << "\n=== Solution: 2 2 ===\n";
   cout << intList.getMyCapacity() << " " << intList.getMySize();
   intList.appendItem(30);
   cout << "\n=== Solution: 4 3 ===\n";
   cout << intList.getMyCapacity() << " " << intList.getMySize();
   cout << "\n==== Solution: 10 20 30 ========\n";
   intList.display();
   intList.removeLast();
   cout << "\n==== Solution: 10 20 ========\n";
   intList.display();
   intList.reset(5);
   cout << "\n==== reset test ========\n";
   intList.appendItem(32);
   intList.appendItem(2);
   intList.display();
   return 0;
}
