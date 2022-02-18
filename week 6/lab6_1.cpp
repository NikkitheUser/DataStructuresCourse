

//title: Lab6_1.cpp
//Abstract: using a queue, we will make a function that searches for a specific value and it will tell us where on the array it is!
//ID: 1507
//Name: Nicole Safty
//Date: 10/01/2021
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

const int QUEUE_CAPACITY = 7;
typedef int QueueElement;

class Queue
{
public:
    Queue();
    bool empty() const;
    void enqueue(QueueElement value);
    void display() const;
    QueueElement front() const;
    void dequeue();
    int find(QueueElement value);

private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration


//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}


//--- Definition of empty()
bool Queue::empty() const
{ 
    return (myFront == myBack); 
}


//--- Definition of enqueue()
void Queue::enqueue(QueueElement value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
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
    for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
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
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    }
    else
    {
        cout << "*** Queue is empty -- "
            "can't remove a value ***\n";
    }
}

int Queue::find(QueueElement value){
  cout<<endl;
for(int i=0;i<QUEUE_CAPACITY;i++){
  if( value==myArray[i]){
    cout<<"Found: "<<i<<endl;
    break;
  }
  if(i>myBack||i<myFront){
    cout<<"invalid number"<<-1<<endl;
    break;
  }

}return true;}

int main()
{
    Queue q1;
    cout << "Queue empty? " << q1.empty() << endl;

    // Enqueue three values 100, 200, and 300
    q1.enqueue(100);
    q1.enqueue(200);
    q1.enqueue(300);
    q1.find(200);
    q1.find(600);

    cout << "\n===== Queue Contents =====\n";
    q1.display(); 

    cout << "\nFront value: " << q1.front() << endl;
    
    // Dequeue the front value
    q1.dequeue();
    
    cout << "\n===== Queue Contents =====\n";
    q1.display(); 

    return 0;
}