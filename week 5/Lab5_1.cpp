
//title: Lab5_1.cpp
//Abstract: this program will add students with their name, id and major into an array. Then we can search for students using their ID
//ID: 1507
//Name: Nicole Safty
//Date: 09/24/2021
/*-----------------------------------------------------------------
  Original source: https://repl.it/@YBYUN/StudentList
  Updated by Dr. Byun for CST238.
-------------------------------------------------------------------------*/
// A sample list of Student objects.

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student();
    void setStudent(string newName, int newID, string newMajor);
    void displayStudent() const;
    int getId();

private:
    string name;
    int ID;
    string major;
    int pos;
};


// Constructor
Student::Student()   
: name("UNKNOWN"),ID(0)
{}
//get the private ID number 
int Student::getId(){
  return ID;
}

void Student::setStudent(string newName, int newID, string newMajor)
{
    name = newName;
    ID = newID;
    major= newMajor;
	return;
}


void Student::displayStudent( ) const
{
    cout << "\n======================================" << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << ID << endl;
    cout<<"Student Major: " << major <<endl;
	return;
}

// Maximum capacity of a list.
const int CAPACITY = 50; 

class StudentList
{
public:
    StudentList(); 
    bool empty() const; 
    void add(string name, int ID, string major, int pos);
    void displayAll() const; 
    void search (int id);
    

private:
    int mySize;  
    Student myArray[CAPACITY];  // Keep Student objects.
}; 


// Constructor
StudentList::StudentList()     
: mySize(0)
{}
//adds students into the list
void StudentList::add(string name, int ID, string major,int pos){
   for(int i =0; i > pos; i--)
    {
      
        myArray[i] = myArray[i - 1];

    }
myArray[pos].setStudent(name, ID, major);
    mySize++;
    // Insert a new item at the position pos and increase StudentList size  
    
}

bool StudentList::empty() const
{
    return mySize == 0;
}


// Display all students' information.
void StudentList::displayAll() const
{
    for (int i = 0; i < mySize; i++)
    {
        myArray[i].displayStudent();
    }
    cout << endl;
}

//Serches for students with the ID entered in
void StudentList::search (int id){
 int flag=0;
  for(int i=0;i<mySize;i++){
    if(myArray[i].getId()==id){
      flag=1;
      cout<<endl;
      cout<<"**************************"<<endl;
      cout<<"Student Id "<<id<<" found: "<<endl;
      cout<<"**************************"<<endl;
 myArray[i].displayStudent();
 break;
    }}
    if (flag==0){
      cout<<endl;
      cout<<"**************************"<<endl;
      cout<<"There is no student with the Id: "<<id<<endl;
      cout<<"**************************"<<endl;
    }
  
}


int main(){
 StudentList intList;    
 
     intList.add("Bob Otter", 7777, "Undeclared",0);
	intList.add("Alice Otter", 1234, "Computer Science",1);
    intList.add("Chris Otter", 2222, "Communication Design",2);
    intList.displayAll();
    intList.search(1234);
    intList.search(2342);

    
   return 0;
}