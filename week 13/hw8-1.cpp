
//title: hw8_1.cpp
//Abstract: For this lab, we implement a recursion. The user will enter a number, and said number will print out in reverse. Ex: user enters 43, the function spits out 34
//ID: 1507
//Name: Nicole Safty
//Date: 11/18/21
#include <iostream>
using namespace std; 


void printReverse(int n);

void printReverse(int n){
  if(n<0){//in case of a negative number
    cout<<"Hey! That's a negative number! Postive numbers only!"; 
  }
   if(n == 0) //in case user inputs a zero
        return;
    else{
        cout << n % 10; 
        printReverse(n/10); }
}


int main() {
  int n;
  cout<<"Enter a positive number: ";
cin>>n;
cout<<"The reverse of "<< n <<" is: ";
printReverse(n);
} 