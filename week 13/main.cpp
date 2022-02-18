//title: lab12.cpp
//Abstract: this program is split into 3 files. This program is a part of a future project. We need to implemeent a close function, a delete function and a create function using linked nodes
//ID: 1507
//Name: Nicole Safty
//Date: 11/21/2021

// Starting code for the lab12.
// Note that there are three files in the repl.

#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
      // Declare an array of Account pointers.
    // The array can hold up to five Account objects.
    Account *acc_ptr[5];

    // Don't forget to initialize the pointers with nullptr.
    for (int i=0; i < 5; i++)
    {
        acc_ptr[i] = nullptr;
    }

  int size=0;
  int option=0;
  while(option!=3){
  cout<<endl<<"======== Program Menu ========"<<endl;
  cout<<"1: Open an account"<<endl<<"2: Close an account"<<endl<<"3: Exit the program"<<endl;


  cout<<"enter your option: ";
  cin>>option;



  if(option==1){
    string name;
    int j;
    int count=0;
    int account,type;
    double balance;
    if(size==5){
      cout<<"No space"<<endl;
      break;
    }
    cout<<"Enter a name: "; 
    cin>>name;
cout<<"Enter an account number: ";
cin>>account;
cout<<"Enter a type: ";
cin>>type;
cout<<"Enter an initial balance: ";
cin>>balance;
for(int i=0;i<=5;i++){
  if(count==1){
    break;
  }
if (acc_ptr[i]==nullptr){
    acc_ptr[i] = new Account;
    acc_ptr[i]->setAccount(name, account, type, balance);
    size++;
   int j=i;
   count=1;
   }}
   for(int i=0;i<=5;i++){
     if(i==j){
       continue;
     }
     else if(acc_ptr[i]==nullptr){
       continue;
     }
   else if ((*acc_ptr[j]).getNumber()==(*acc_ptr[i]).getNumber()){
      cout<<"sorry this account number is already taken"<<endl;
  delete acc_ptr[j];
    acc_ptr[j] = nullptr;
    break;
    }}
}



if(option==2){
  int account;
  int flag=0;
  cout<<"enter the account number: ";
  cin>>account;
  for(int i=0;i<5;i++){
  
    if(acc_ptr[i]==nullptr){
      flag++;
      continue;
    }
  if(account==(*acc_ptr[i]).getNumber()){
   delete acc_ptr[i];
    acc_ptr[i] = nullptr;
    size--;
cout<<"account closed"<<endl;
break;
  }
if(account!=(*acc_ptr[i]).getNumber()){
  flag++;
}
  }
     if(flag==5){
    cout<<"this account does not exsit"<<endl;
  }
 
}

if(option==3){  
  acc_ptr[0]->displayAccountInfo();
  cout<<"bye!"<<endl;
  return 0;
}
  

  }