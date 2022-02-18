//title: lab4_1.cpp
//Abstract: Using constructs, we will add, erase and search for values in an array. We wi;l also reverse the array as well.
//ID: 1507
//Name: Nicole Safty
//Date: 09/17/2021

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
#include <string>
using namespace std;

const int CAPACITY = 16; // Maximum capacity of a list.

class List
{
public:
    List(); // Class constructor
    bool empty() const; 
    void insert(int item);
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
    int search (int value);
    void reverse();

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


//--- Definition of insert()
void List::insert(int item, int pos)
{
    if (mySize == CAPACITY)
    {
        cout << "*** No space for list element -- terminating "
            "execution ***"<<endl;
        return;
    }
    if (pos < 0 || pos > mySize)
    {
        cout << "*** Illegal location to insert -- " << pos 
            << ".  List unchanged. ***\n";
      
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

//when theres only one item
void List::insert(int item){
  if (mySize == CAPACITY)
    {
        cout << "*** No space for list element -- terminating "
            "execution ***"<<endl;
        return;
    }
      myArray[mySize]=item;
      mySize++;
    
}

//--- Definition of erase()
void List::erase(int pos)
{
    if (mySize == 0)
    {
        cout << " List is empty\n";
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
   mySize=mySize-2;

}
//find a item in array
int List::search(int value){

for(int i=0;i<=mySize;i++){
  if (value==myArray[i]){
   
    return i;
  }}
return -1;}

//reverse array
void List::reverse(){
  int j=mySize-1;
  for(int i=0;i<j;i++){
  int temp = myArray[i];
   myArray[i] = myArray[j];
   myArray[j] = temp;
    j--;
  }
  }

//--- Client program to test List class.
int main()
{
 /*
 //demo 1
    List intList;

    // Check if a list is empty or not.
    if (intList.empty()){
       cout<<"list is empty";}

    // Inserting a number 1234 at the position 0
    intList.insert(1234, 0);

    // Inserting a number 500 at the position 1
    intList.insert(500, 1);

    // Inserting a number 2000 at the position 0
    intList.insert(2000, 0);

    cout << "\n===== Numbers in the List =====\n";
    intList.display();
    

    cout << "\nTry to insert 3000 at position 10" << endl;
    intList.insert(3000, 10);

    // Test erase()
    cout << "\nRemove a number in the position 1" << endl;
    intList.erase(1);

    cout << "\n===== Numbers in the List ====="<<endl;
    intList.display();

    return 0;*/

    //demo 2
        List intList;    
        intList.insert(20,0);    
        intList.insert(10,0); 
           intList.insert(30);  
             intList.display(); 
                intList.reverse();    
                intList.insert(15);    
                intList.display();    
                intList.reverse();    
                intList.display();    
                cout << intList.search(20) << endl;  
                  cout << intList.search(100) << endl;    
                  return 0;
}


