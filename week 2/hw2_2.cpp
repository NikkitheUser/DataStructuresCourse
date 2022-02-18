//title: hw2_2.cpp
//Abstract: With a seperate file, this program will put file inputs into a structure, and ask for the user to call an name from the structure
//ID: 1507
//Name: Nicole Safty
//Date: 09/05/2021
#include <iostream>
#include <fstream>
using namespace std;

struct Bank{
      string customer;
      int account;
      double balance;
    };


int main() {
cout << "Enter input file name: ";
    string file_name;
    cin >> file_name;

    ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }

string choice="y";//so our user can either keep using the program or stop
string name;
int flag=0; //we use this in case an invalid name is used
  int size=30;  
Bank arr[30];

     do{

    cout<<"---------------------------------------------------"<<endl;
    cout<<" Record Finder - Enter a customer name: ";
    cin>>name;
    cout<<"---------------------------------------------------"<<endl;

  for(int i=0;i<=size;i++){
    f_input>>arr[i].customer>>arr[i].account>>arr[i].balance; //we add the inputs from the file into the struct array
   };



for(int i=0;i<=size;i++){

    if(name==arr[i].customer){
      flag =1;//we flag that an account has been found
 cout<<"Name: "<<arr[i].customer<<endl;
     cout<<"Account: "<< arr[i].account<<endl;
     cout<<"Balance: " << arr[i].balance<<endl;

    cout<<"---------------------------------------------------"<<endl;}

}


     
 if(!flag){//Using name!=customer only caused the program to fail if you dont go in order of the file. 
 //I.E. if i called alice, it would fail because it read Tom only, if you continue, you would get alice next
 //I used flag to get around this
  cout<<" Fail."<< name<< " doesn’t exist."<<endl;
cout<<"---------------------------------------------------"<<endl;
   
}
    cout<<"do you want to continue? (Y/N): ";
cin>>choice;
flag=0;//we make flag 0, so in case the next account doesnt exsist, we wont accidently not trigger the fail option
if(choice=="n"||choice=="N"){
  cout<<"Bye!";
}

         }  while(choice=="y"||choice=="Y");
}