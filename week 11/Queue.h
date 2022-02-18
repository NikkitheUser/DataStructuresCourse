#ifndef QUEUE_H
#define QUEUE_H
#include <string>
typedef int QueueElement;
const int myCapacity = 16;
using namespace std;

class Queue
{
public:
    Queue();
    bool empty() const;
    void enqueue(QueueElement value);
    void display() const;
    QueueElement front() const;
    void dequeue();
   ~Queue( );              // Destructor
    Queue(const Queue& org); // Copy constructor
    Queue& operator =(const Queue& rightSide);  // Assignment operator

private:
    int myFront;
    int myBack;
    int *myArray;
    int mySize;     // current size of list
   int myCapacity; // capacity of array
}; // end of class declaration
#endif