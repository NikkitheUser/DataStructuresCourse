
//title: hw7_1.cpp
//Abstract: for this hw, we must add the "big three"(destructor,copy constructor and assignment operator) and split the program into three seperate files
//ID: 1507
//Name: Nicole Safty
//Date: 11/12/21
#include <iostream>
#include <string>
#include <cstdlib>  //for exit() function
#include "Queue.h"  // Include the interface file.
 using namespace std;
int main()
{
   Queue q1;
    q1.enqueue(100);
    q1.enqueue(200);
    Queue q2(q1);  // copy constructor
    q1.dequeue();
    q1.enqueue(300);
    cout << "========== ANSWER: 200 300 ==========\n   ";
    q1.display();
    cout << endl;
    
    cout << "========== ANSWER: 100 200 ==========\n   "; 
    q2.display();
    cout << endl;
    
    Queue q3;
    q3.enqueue(500);

    q2 = q3;     // assignment operator
    cout << "========== ANSWER: 500 ==========\n   "; 
    q2.display();
    cout << endl;
    return 0;
}