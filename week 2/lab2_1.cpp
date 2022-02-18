//title: lab2_1.cpp
//Abstract: this program will ask a user to shift an array to the left or right
//ID: 1507
//Name: Nicole Safty
//Date: 09/03/2021
#include <iostream>
using namespace std;
int main() {

int num[10]={5,10,20,30,35,40,45,50,60,70};
int choice;//for either left or right shift
string con;//for continue
int left=1;
int right=1;

cout<<"Array values: ";
for(int i=0;i<10;i++){
  cout<<num[i]<<" ";
}
cout<<endl;
cout<<"This is the list of options "<<endl;
cout<<"1.Right shift"<<endl<< "2.Left shift"<<endl;




do{
cout<<"enter your option "<<endl;
cin>>choice;

if(choice==1){//we move to the left
 int remove = 0, temp; //we add a zero to the left
   for (int i = 0; i < 10; i++) { 
       temp = num[i]; //temp stores num[i]
        num[i] = remove;//we make num[i]=0
         remove = temp;//without this, everything becomes 0, so besides the first number on the array, all integers get their temp number back
         }}
         
if(choice==2){//we move to the right
   int remove = 0, temp;//we add the zero to the right
   for (int i = 10; i>=0; i--) { 
       temp = num[i];//temp stores num[i]
        num[i] = remove;//we then make num[i]=0
         remove = temp; //without this, everything becomes 0, so besides the last number on the array, all integers get their temp number back
         }}

cout<<"New array values ";
for(int i=0;i<10;i++){
  cout<<num[i]<<" ";
}
cout<<endl;
cout<<"Continue? (Y/N):";
cin>>con;

}while(con!="N"&&con!="n");


}