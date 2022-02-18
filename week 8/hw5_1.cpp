//title: hw5_1.cpp
//Abstract: this program is a queue array. We added a sort array, it sorts in ascending order. And a function that tests to see if a function is sorted, either decending or ascending 
//ID: 1507
//Name: Nicole Safty
//Date: 10/18/21
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
    void sort();//will sort
    bool isSorted();//checks if it is sorted

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

//sort by ascending order
void Queue::sort(){
  int temp;
for(int i=myFront;i<myBack;i++){
  for(int j=i+1;j<myBack;j++){
    if(myArray[i]>myArray[j]){
temp=myArray[i];
myArray[i]=myArray[j];
myArray[j]=temp;
    }
  }
}
}
//is the array sorted?
bool Queue::isSorted(){
int count=0;
int count2=0;
int x=myBack-myFront;
//if theres only 1 or 2 values, it is automatically sorted!
if(x==2||x==1){
  return true;
}
//going down
  for(int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY){
  for(int j = myFront+1; j != myBack; j = (j + 1)%QUEUE_CAPACITY){
    if(myArray[i]>myArray[j]){
      count++;
}
}}
if (count==x){
  return true;
}
//going up
for(int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY){
  for(int j = myFront+1; j != myBack; j = (j + 1)%QUEUE_CAPACITY){
    if(myArray[i]<myArray[j]){
      count2++;
}}}
if (count2==x){
  return true;
}
//if its not sorted up or down, its not sorted at ALL
return false;}

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
      q1.enqueue(200);    
      q1.enqueue(100);    
      q1.enqueue(300);    
      cout << "isSorted()? " << boolalpha << q1.isSorted() << endl;    q1.sort();    
      q1.display();    
      cout << "isSorted()? " << boolalpha << q1.isSorted() << endl;    q1.dequeue();    
      q1.enqueue(50);    
      cout << "isSorted()? " << boolalpha << q1.isSorted() << endl;    q1.dequeue();    
      cout << "isSorted()? " << boolalpha << q1.isSorted() << endl;    return 0;
}