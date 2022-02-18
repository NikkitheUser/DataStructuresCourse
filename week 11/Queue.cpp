/**********************************************************
 * Queue implementation with a static array.
 * Original code: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap08/Figure8.2/
 * Updated by Dr. Byun for CST238.
 * Basic operations:
 *   Constructor: Constructs an empty queue
 *   empty:       Checks if a queue is empty
 *   enqueue:     Modifies a queue by adding a value at the back
 *   front:       Accesses the front queue value; leaves queue unchanged
 *   dequeue:     Modifies a queue by removing the value at the front
 *   display:     Displays the queue elements from front to back
 *
 **********************************************************/ 
#include <iostream>
using namespace std;
#include <cstdlib>  //for exit() function
#include <string>
#include "Queue.h"

// Destructor
Queue::~Queue( )
{
    delete [] myArray;
}


// Copy constructor
Queue::Queue(const Queue& org)
  :myFront(org.myFront), myBack(org.myBack),mySize(org.mySize), myCapacity(org.myCapacity)
{
    myArray = new int[myCapacity];
    for (int i = myFront; i != myBack; i = (i + 1)%myCapacity)
        myArray[i] = org.myArray[i];
}

// Assignment operator
Queue& Queue::operator =(const Queue& rightSide)
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
        myFront=rightSide.myFront;
        myBack=rightSide.myBack;
        for (int i = myFront; i != myBack; i = (i + 1)%myCapacity)
        {
            myArray[i] = rightSide.myArray[i];
        }
    }
  
    return *this;
}

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0),mySize(0), myCapacity(16)
{myArray = new int[myCapacity];
}


//--- Definition of empty()
bool Queue::empty() const
{ 
    return (myFront == myBack); 
}


//--- Definition of enqueue()
void Queue::enqueue(QueueElement value)
{
    int newBack = (myBack + 1) % myCapacity;
    if (newBack != myFront)     // queue isn't full
    { 
        myArray[myBack] = value;
        myBack = newBack;
    }
    else
    {
        cout << "*** Queue full -- can't add new value ***\n"
            "Must increase value of QUEUE_CAPACITY.\n";
    }
}


//--- Definition of display()
void Queue::display() const
{
    for (int i = myFront; i != myBack; i = (i + 1)%myCapacity) 
    {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of front()
QueueElement Queue::front() const
{
    if ( !empty() ) 
    {
        return (myArray[myFront]);
    }
    else
    {
        cout << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}


//--- Definition of dequeue()
void Queue::dequeue()
{
    if ( !empty() )
    {
        myFront = (myFront + 1) % myCapacity;
    }
    else
    {
        cout << "*** Queue is empty -- "
            "can't remove a value ***\n";
    }
}