
//title: hw5_2.cpp
//Abstract: this program is a queue array. We added the ability to drop a specific value, and to remove the back value
//ID: 1507
//Name: Nicole Safty
//Date: 10/18/21
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

const int QUEUE_CAPACITY = 10;
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
    bool drop(int value);
    void removeBack();

private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration


//drop the value
bool Queue::drop(int value){
//is it there?
int flag=0;
  int pos;//the position of the value
for(int i=myFront;i<myBack;i++){
  if(myArray[i]==value){
    pos=i; //if theres a repeat, we take the repeat at the end of the array
    flag++;
  }
}
//if the value is not there
 if(flag==0){
     cout<<"Error, "<<value<<" is not in this array!"<<endl;
    return false;
    return false;
  }
for(int i =pos; i < myBack; i++)
    {
        myArray[i] = myArray[i + 1];
    }
    // Decrease list size
    myBack--;
  return true;
}



//removes the back
void Queue::removeBack(){
for(int i = myBack; i < myBack; i++)
    {
        myArray[i] = myArray[i + 1];
    }
    myBack--;
}

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


int main()
{
  Queue q1;   
  q1.enqueue(100);  
   q1.enqueue(200);   
   q1.enqueue(300);   
   q1.enqueue(400);   
   q1.removeBack();     
   q1.display();    // Queue has 100 200 300   
   q1.drop(200);   
   q1.display();    // Queue has 100 300   
   return 0;
}