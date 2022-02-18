//title: hw3_2.cpp
//Abstract: using classes, this program adds and removes students from the class course. it also shows the course name, instructor, course number and enrolled students
//ID: 1507
//Name: Nicole Safty
//Date: 09/13/2021
#include <iostream>
using namespace std;

class Course{
  private:
  string title; //name of course
  int num;//course number
  string prof;//name of instructor
  int enroll=0;//number of students enrolled, if its 5 then its full
  string student[5];//student name
  int id[5];//student id


  public:
  void setCourse(string newTitle,string newProf,int newNum);
  bool addStudent(string newStudent, int newId);
  bool dropStudent(int badId);
  void printAll();

};
int main() {
  int x=0;
  Course cst238;    
  cst238.setCourse("Data Structures", "Dr. Byun", 238);    cst238.addStudent("Tom",   1000);  
  cst238.addStudent("Brian", 2000);
  cst238.addStudent("Alex",  3000); 
 
cst238.dropStudent(2000);   
 cout << "===== Course Report =====" << endl;   
  cst238.printAll();    
  return 0;

}

  void Course::setCourse(string newTitle,string newProf,int newNum){
title=newTitle;
prof=newProf;
num=newNum;
  }

  bool Course::addStudent(string newStudent, int newId){
for(int i=0;i<5;i++){//if id is copied or too many are enrolled, return false
   if (id[i]==newId || enroll==5){
   
return false;
}}

 if (enroll!=5){
student[enroll]=newStudent;
id[enroll]=newId;
enroll++;
return true;
}return true;}


  bool Course::dropStudent(int badId){
for(int i=0;i<=5;i++){
  if (id[i]==badId){
  enroll--;
  id[i]=0;
  student[i]=" ";
    return true;
  }
  else{
    continue;
  }
}
return false;
  }


  void Course::printAll(){
    cout<<"Course Title: "<<title<<endl;
cout<<"Instructor: "<<prof<<endl;
cout<<"Course Number: "<<num<<endl;
cout<<"Enrollment: "<<enroll<<endl;
for(int i=0; i<=enroll;i++){
  if(student[i]==" "){
    continue;
  }
  cout<<student[i]<<": "<<id[i]<<endl;
}
  }