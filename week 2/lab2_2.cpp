//title: lab2_2.cpp
//Abstract: this program will read a txt file and display the scores of 2 students and determine which score average is better between the two students
//ID: 1507
//Name: Nicole Safty
//Date: 09/03/2021

#include <iostream>
#include<fstream>
using namespace std;
int main() {
  string student1,student2; //our two students
  double score1,score2,score3,score4; //score1 and score2 is student1 scores, score3 and score4 are student2 scores.
  cout<<"enter file name: ";
  string file_name;
    cin >> file_name;
    
 
    ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }
f_input>>student1>>score1>>score2>>student2>>score3>>score4;
/*cout<<student1<<" "<<score1<<" "<<score2<<endl;
cout<<student2<<" "<<score3<<" "<<score4<<endl;*/
//this was to test to see if the file would work

double average1=(score1+score2)/2;//student1 average
double average2=(score3+score4)/2;//student2 average
cout<<student1<<"'s"<<" average: "<<average1<<endl;
cout<<student2<<"'s"<<" average: "<<average2<<endl;

if(average1>average2){
  cout<<student1<<" has a better score than "<<student2;
}
else if( average2>average1){
  cout<<student2<<" has a better score than "<<student1;
}
else{
  cout<<student1<<" and "<<student2<<" have the same scores";
}

}