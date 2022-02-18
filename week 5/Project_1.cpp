//title: project_1.cpp
//Abstract: This project reads data off a txt file, which then determine what is done to an array. 10 things can be done with this program. 
  //Append, Insert and Erase students from an array. It can update exam scores, display a students info with an ID or display all students info. 
  //The program can also sort the array either by ID or by the best average exam score. The program can also tell you how many 
  //students are in the array and the average of all students.
//ID: 1507
//Name: Nicole Safty
//Date: 10/04/2021
// A sample list of Student objects.
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Student
{
public:
    Student();
    void setStudent(string newName, int newID, float newExam1, float newExam2);
    void displayStudent() const;
    string rname();
    int rID();
    float rexam1();
    float rexam2();
    float rAvg();
    float setNewexam(float newexam1, float newexam2);//thank you Dr.Byun for your help

private:
    string name;
    int ID;
    float exam1;
    float exam2;
    float avg;
};


// Constructor
Student::Student()   
: name("UNKNOWN"), ID(0), exam1(0),exam2(0)
{}


void Student::setStudent(string newName, int newID,float newExam1, float newExam2)
{
    name = newName;
    ID = newID;
    exam1=newExam1;
    exam2=newExam2;
	return;
}

float Student::setNewexam(float newexam1,float newexam2){
exam1=newexam1;
exam2=newexam2;
return exam1;
return exam2;
}
string Student::rname(){
  return name;
}
int Student::rID(){
  return ID;
}
float Student::rexam1(){
  return exam1;
}
float Student::rexam2(){
  return exam2;
}
float Student::rAvg(){
 float sum=rexam1()+rexam2();
 float average=sum/2;
  avg=average;
  return avg;
}

void Student::displayStudent( ) const
{
    cout << "\n======================================" << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << ID << endl;
	return;
}

// Maximum capacity of a list.
const int CAPACITY = 50; 


class StudentList
{
public:
    StudentList(); 
    bool empty() const; 
    void add(string name, int ID, float exam1,
    float exam2,int pos);
    void displayAll() const; 
    void append(int ID,string name, float exam1,float exam2);//1
    void insert(int pos, int ID, string name, int exam1,int exam2);//2
     void erase(int ID);//3
    void update(int ID,float exam1,float exam2);//4
    void display(int ID);//5
    void displayMost();//6
    void IDsort();//7
    void avgsort();//8
    void stats();//9
    string quit();//10
    int returnsize();
private:
    int mySize;  
    Student myArray[CAPACITY];  // Keep Student objects.
}; 


// Constructor
StudentList::StudentList()     
: mySize(-1)
{}
int StudentList::returnsize(){
  return mySize;
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


// Add a student with the name and ID to the position.
void StudentList::add(string name, int ID, float exam1,
    float exam2,int pos)
{
    if (mySize == CAPACITY)
    {
        cout << "*** No space for a new StudentList element ***\n";
        return;
    }

    if (pos < 0 || pos > mySize)
    {
        cout << "*** Illegal location to insert -- " << pos << " ***\n";
        return;
    }

    // Shift array elements right to make a room for a new item
    for(int i = mySize; i > pos; i--)
    {
        myArray[i] = myArray[i - 1];
    }

    // Insert a new item at the position pos and increase StudentList size  
    myArray[pos].setStudent(name, ID, exam1,exam2);
   mySize++;
}


//key 1 append a student to the back of the Array
void StudentList::append(int ID,string name, float exam1,float exam2){
  if (mySize == CAPACITY)
    {
        cout << "*** No space for list element -- terminating "
            "execution ***\n";
    } mySize++;

           for(int i = mySize; i <mySize; i--)
    {
        myArray[i] = myArray[i - 1];
    }
    myArray[mySize].setStudent(name, ID, exam1,exam2);
     cout<<"Append"<<endl;
    cout<<"ID: "<<myArray[mySize].rID()<<endl;
    cout<<"name: "<<myArray[mySize].rname()<<endl;
    cout<<"exam1: "<<myArray[mySize].rexam1()<<endl;
    cout<<"exam2: "<<myArray[mySize].rexam2()<<endl; 
  }

  //key 2, add stuent to a PATICULAR part in the array
void StudentList::insert(int pos, int ID, string name, int exam1,int exam2){

if (mySize == CAPACITY)
    {
        cout << "*** No space for list element -- terminating "
            "execution ***\n";
    }
    mySize++;
   for(int i = mySize; i > pos; i--)
    {
        myArray[i] = myArray[i - 1];
    }   
    myArray[pos].setStudent(name, ID, exam1,exam2);
        cout<<"Insert: "<<endl;
    cout<<"Position: "<<pos<<endl;
    cout<<"ID: "<<myArray[pos].rID()<<endl;
    cout<<"Name: "<<myArray[pos].rname()<<endl;
    cout<<"exam1: "<<myArray[pos].rexam1()<<endl;
    cout<<"exam2: "<<myArray[pos].rexam2()<<endl;  
}
  
//key 3, erase a student with the chosen ID
void StudentList::erase(int ID){
  int flag=0;
  int position;
  for(int i=0;i<mySize+1;i++){
 if(myArray[i].rID()==ID){
 flag++;
  cout<<"Erase: "<<endl;
    cout<<"ID: "<<ID<<endl;
 int position=i;  
  for(int j = position; j < mySize; j++)
    {
        myArray[j] = myArray[j + 1];
    } 
    mySize--;}}
  
if(flag==0){
      cout<<"This is not a valid ID: "<<ID<<endl;
      cout<<"We can not erase"<<endl;
      }}



//key 4 update a students score with new ones
 void StudentList::update(int ID,float exam1,float exam2){
int flag=0;
cout<<"Update Scores"<<endl;
for(int i=0;i<=mySize;i++){
  if (myArray[i].rID()==ID){
    flag=1;
    cout<<endl;
myArray[i].setNewexam(exam1,exam2);
cout<<"We have updated Student ID "<<ID<<" Exam scores:"<<endl;
cout<<"exam1 updated: "<<exam1<<endl;
cout<<"exam2 updated: "<<exam2<<endl;
break;
}}
if(flag==0){
  cout<<"This is not a valid ID: "<<ID<<endl;
}

}


//key 5 display a specific student with their ID
 void StudentList::display(int ID){
   cout<<"Display Student "<<ID<<endl;
   int flag=0;
   for(int i=0;i<=mySize;i++){
    if(myArray[i].rID()==ID){
      flag=1;
      cout<<"Name: "<<myArray[i].rname()<<endl;
      cout<<"ID: "<<myArray[i].rID()<<endl;
      cout<<"Exam1: "<<myArray[i].rexam1()<<endl;
      cout<<"Exam2: "<<myArray[i].rexam2()<<endl;
      cout<<"key5 "<<i<<endl;
      break;
    }}
    if(flag==0){
      cout<<"Thats not a vaild ID: "<<ID<<endl;
    }}

 //key 6 Display IDs, names, and averages of all students
void StudentList::displayMost(){
  cout<<"Display All Students:"<<endl;
  for(int i=0;i<=mySize;i++){
   float sum=myArray[i].rexam1()+myArray[i].rexam2();
 float average=sum/2;
    cout<<myArray[i].rID()<<": "<<myArray[i].rname()<<"("<<average<<")"<<endl;
}}


//key 7 Sort by ID
void StudentList::IDsort(){
Student temp;
Student tempa;
cout<<"We have sorted by ID:"<<endl;
for(int i=0;i<=mySize;i++)
	{		
		for(int j=i+1;j<=mySize;j++)
		{
			if(myArray[i].rID()>myArray[j].rID())
			{
				temp = myArray[i];
				myArray[i]=myArray[j];
				myArray[j]=temp ;


			}
		}
	}
for(int i=0;i<=mySize;i++){
  cout<<myArray[i].rID()<<": "<<"("<<myArray[i].rAvg()<<")"<<endl;
}}


//key 8 sort by the average scores
void StudentList::avgsort(){
  Student temp;
  cout<<"We have sorted by averages:"<<endl;
for(int i=0;i<=mySize;i++)
	{		
		for(int j=i+1;j<=mySize;j++)
		{
			if(myArray[i].rAvg()<myArray[j].rAvg())
			{
				 temp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = temp;
			}
		}
	}
for(int i=0;i<mySize+1;i++){
  cout<<myArray[i].rID()<<": "<<"("<<myArray[i].rAvg()<<")"<<endl;
}
}


//key 9 how many students, and the overall average
void StudentList::stats(){
  float avg[CAPACITY];
float sum;
int size=0;
cout<<"Number of students: "<<mySize+1<<endl;
for(int i=0;i<=mySize;i++){
  avg[i]=myArray[i].rexam1()+myArray[i].rexam2();
  size= size+2;
}
for(int i=0;i<=mySize;i++){
  sum+=avg[i];
}
float result=sum/size;
cout<<"Overall average: "<<result  <<endl;
}

//key 10 exit the program
 string StudentList::quit(){
  cout<<endl;
  cout<<"BYE!";
  return 0;
}


// A client program to test the StudentList of students.
int main()
{

   int ID;
string name;
float exam1, exam2;
int pos;

  cout << "Enter input file name: ";
    string file_name;
    cin >> file_name;
ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }

int key=0;//the first number in the txt file
    StudentList cst238List;
int size=cst238List.returnsize();
while(key!=10){
int key=0;
f_input>>key;

//append
if(key==1){
  f_input>>ID>>name>>exam1>>exam2;
  cout<<endl;
 //  cst238List.add(name,ID,exam1,exam2,size);
  cst238List.append(ID,name,exam1,exam2); 
}

//insert
 if(key==2){
   cout<<endl;
f_input>>pos>>ID>>name>>exam1>>exam2;
//cst238List.add(name,ID,exam1,exam2,pos);
cst238List.insert(pos,ID,name,exam1,exam2);
  }

  //erase
 if(key==3){
   cout<<endl;
 f_input>>ID;
key=0;
cst238List.erase(ID);
}

//Update Scores
if(key==4){
  f_input>>ID>>exam1>>exam2;
cout<<endl;
cst238List.update(ID,exam1,exam2);
//we need to acess the new exam scores and replace it
//with the old ones
}

//display ID
if(key==5){
  cout<<endl;
  f_input>>ID;
  cst238List.display(ID);
}

//Display IDs, names, and averages of all students
if(key==6){
  cout<<endl;
  cst238List.displayMost();
  //7777 Alice (82.5)
}

//sort by id
if(key==7){
  cout<<endl;
cst238List.IDsort();
}

//sort by Average
if(key==8){
  cout<<endl;
cst238List.avgsort(); 
}

//Display statistics of the list
if(key==9){
  cout<<endl;
  //num of students
  //overall average of all students
  cst238List.stats();
}

//exit program
 if(key==10){
   cout<<endl;
  cout<<"BYE!";
return 0;
}
}
    return 0;
}
