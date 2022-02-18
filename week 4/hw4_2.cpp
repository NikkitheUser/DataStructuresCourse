
//title: hw4_2.cpp
//Abstract: this program will check to see if theres any repeating values and then sorts values from decreasing order
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
    bool isDuplicate();
    void sort();

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

bool List::isDuplicate(){
  for(int i=0;i<mySize;i++){
    for(int j=i+1;j<mySize;j++){
if(myArray[i]==myArray[j]){
  return true;
}}
  }
  return false;
}

void List::sort(){
  	for(int i=0;i<mySize;i++)
	{		
		for(int j=i+1;j<mySize;j++)
		{
			if(myArray[i]<myArray[j])
			{
				int temp  =myArray[i];
				myArray[i]=myArray[j];
				myArray[j]=temp;
			}
		}
	}
}

//--- Client program to test List class.
int main()
{
    /*List intList;

    // Check if a list is empty or not.
    if (intList.empty())
        cout << "List is empty.\n";

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

    cout << "\n===== Numbers in the List =====\n";
    intList.display();

    return 0;*/
    List intList;  
     intList.insert(10, 0);    
     intList.insert(20, 1);    
     intList.insert(15, 2);    
     intList.display();    
     cout << (intList.isDuplicate() ? "Yes" : "No") << endl;    intList.insert(20, 3);    
     intList.display();    
     cout << (intList.isDuplicate() ? "Yes" : "No") << endl;    intList.sort();    
     intList.display();    
     return 0;
}


