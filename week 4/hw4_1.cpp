//title: hw4_1.cpp
//Abstract: this program will check to see if theres any repeating values, add values, and remove values
//ID: 1507
//Name: Nicole Safty
//Date: 09/22/2021

/*-----------------------------------------------------------------
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

const int CAPACITY = 16; // Maximum capacity of a list.

class List
{
public:
    List(); // Class constructor
    bool empty() const; 
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
    bool isSorted();//checks if the list is sorted in the ascending order or not
    bool removeAll(int value);//removes all variables with this value

private:
    int mySize;  // Current size of elements stored in the list
    int myArray[CAPACITY];  
}; 


//--- Definition of class constructor
List::List()     
: mySize(0)
{}


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

 bool List::isSorted(){
int flag=0;
for(int i=0;i<mySize-1;i++){
  if(myArray[i]<myArray[i+1]){//if its not sorted
     flag++;
  }
  else if(myArray[i]>myArray[i+1]){
  return false;
  }
  }
  if(mySize==1){//if theres only one item
    return true;
  }
  if(flag==mySize){
    return true;
  }
return true;
 }



//--- Definition of insert()
void List::insert(int item, int pos)
{
    if (mySize == CAPACITY)
    {
        cout << "*** No space for list element -- terminating "
            "execution ***\n";
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

 bool List::removeAll(int value){ // we erase the chosen value 
    for (int i=0; i <mySize; i++){
        for(int j=0;j<mySize;j++){
            if(myArray[i]==value){
                mySize--;
                for (int k=i; k<mySize; k++){
                    myArray[k]=myArray[k+1];
                }
              i--;
            }
        }
    }
    return true;
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


//--- Client program to test List class.
int main(){  
    List intList;    
    intList.insert(10, 0);    
    intList.insert(20, 1);    
    cout << (intList.isSorted() ? "Yes" : "No") << endl;    intList.insert(15, 2);
  cout << (intList.isSorted() ? "Yes" : "No") << endl;    intList.insert(20, 3);    
  intList.display();    
  intList.removeAll(20);    
  intList.display();    
  intList.removeAll(10);    
  intList.display();   
   return 0;}