
//title: Lab5_2.cpp
//Abstract: this program will read a text file and then depending on the key number, will either; append a student, erase a student, insert
// a student at a select location and exit the program
//ID: 1507
//Name: Nicole Safty
//Date: 09/24/2021
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student{
string name;
int ID;
float exam1;
float exam2;
int pos;
};

int main() {
 int mySize=30;
  int CAPACITY=50;
  int key=0;
Student arr[CAPACITY];
string name;
int ID;
float exam1;
float exam2;
int pos;
int add=0;

cout << "Enter input file name: ";
    string file_name;
    cin >> file_name;
ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }


while(key==0){
int key=0;
f_input>>key;



//append
if(key==1){
  cout<<endl;
if (mySize == CAPACITY)
    {
        cout << "*** No space for list element -- terminating "
            "execution ***\n";
    }
    mySize++;
f_input>>arr[mySize].ID>>arr[mySize].name>>arr[mySize].exam1>>arr[mySize].exam2;

    for(int i = mySize; i <mySize; i--)
    {
        arr[i] = arr[i - 1];
    }
    cout<<"Append"<<endl;
    cout<<"ID: "<<arr[mySize].ID<<endl;
    cout<<"name: "<<arr[mySize].name<<endl;
    cout<<"exam1: "<<arr[mySize].exam1<<endl;
    cout<<"exam2: "<<arr[mySize].exam2<<endl;
    add++;
    key=0;
    continue;
}
//insert
 if(key==2){
   cout<<endl;
add++;
key=0;
  if (mySize == CAPACITY)
    {
        cout << "*** No space for list element -- terminating "
            "execution ***\n";
    }

f_input>>arr[add].pos>>arr[add].ID>>arr[add].name;
pos=arr[add].pos;
cout<<"Insert: "<<endl;
    cout<<"Position: "<<pos<<endl;
    cout<<"ID: "<<arr[add].ID<<endl;
    cout<<"Name: "<<arr[add].name<<endl;
 for(int i = mySize; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    
    continue;
      }

  
//erase
 if(key==3){
   cout<<endl;
  for(int i=0;i<1;i++){
f_input>>ID;
}
key=0;
for(int i=0;i<mySize;i++){
    if (arr[i].ID==ID){
       for(int j = i; j < mySize; j++)
    {
        arr[j] = arr[j + 1];
    }
    }
  }    mySize--;
   cout<<"Erase: "<<endl;
    cout<<"ID: "<<ID<<endl;
  continue;
}

//quit
 if(key==10){
  cout<<"Bye!"<<endl;
  return 0;
}}
}