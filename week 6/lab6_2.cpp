

//title: Lab6_2.cpp
//Abstract: Using a stack, we will reverse float numbers
//ID: 1507
//Name: Nicole Safty
//Date: 10/01/2021
/***********************************************************************
 * Original code: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap07/Figures7.4-5/
 * Updated by Dr. Byun for CST238
 * Basic operations:
 *   constructor:  Constructs an empty stack
 *   empty:        Checks if a stack is empty
 *   push:         Modifies a stack by adding a value at the top
 *   top:          Retrieves the top stack value; leaves stack unchanged
 *   pop:          Modifies stack by removing the value at the top
 *   display:      Displays all the stack elements
 ************************************************************************/

#include <iostream>
using namespace std;

const int STACK_CAPACITY = 128;
typedef float StackElement;

class Stack
{
public:
    Stack();
    bool empty() const;
    void push(StackElement value);
    void display() const;
    StackElement top() const;
    void pop();
    void reverse();
    void mydisplay();

private:
    StackElement myArray[STACK_CAPACITY];
    int myTop;
}; // end of class declaration


//--- Definition of Stack constructor
Stack::Stack()
: myTop(-1)
{}


//--- Definition of empty()
bool Stack::empty() const
{ 
    return (myTop == -1); 
}


//--- Definition of push()
void Stack::push(StackElement value)
{
    if (myTop < STACK_CAPACITY - 1) //Preserve stack invariant
    { 
        ++myTop;
        myArray[myTop] = value;
    }
    else
    {
        cout << "*** Stack full -- can't add new value ***\n"
            "Must increase value of STACK_CAPACITY.\n";
        return;
    }
}


//--- Definition of display()
void Stack::display() const
{
    for (int i = myTop; i >= 0; i--) 
    {
        cout << myArray[i] << endl;
    }
}


//--- Definition of top()
StackElement Stack::top() const
{
    if ( !empty() ) 
    {
        return (myArray[myTop]);
    }
    else
    {
        cout << "*** Stack is empty ***\n";
        // returning -1 as a garbage value.
        return -1;  
    }
}


//--- Definition of pop()
void Stack::pop()
{
    if ( !empty() )
    {
        myTop--;
    }
    else
    {
        cout << "*** Stack is empty -- can't remove a value ***\n";
    }
}
void Stack::reverse(){
  
  for(int i=0;i<=myTop;i++){
	{		
		for(int j=i+1;j<=myTop;j++)
		{
			if(myArray[i]<myArray[j])
			{
				int temp = myArray[i];
				myArray[i]=myArray[j];
				myArray[j]=temp;
}
}}}
 }

int main()
{
    Stack s;
    int num;

    cout << "Stack Empty? " << boolalpha << s.empty() << endl;
cout<<"Enter a number of input values: ";
cin>>num;

double number=0;
int value=num;
double newArray;
for(int i=0;i<num;i++){
  cout<<endl<<"Enter "<<value<<" values:";
   cin>> number;
   s.push(number);}
   s.reverse();
    cout << "\nStack contents in reverse order:\n";
    s.display();
    cout<<endl;

	return 0;
}