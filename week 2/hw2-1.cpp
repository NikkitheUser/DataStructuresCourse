//title: hw2_1.cpp
//Abstract: this program will ask a user choses between 3 operations
//1. deletes the max number 2. appends an empty zero 3. reverses the array
//ID: 1507
//Name: Nicole Safty
//Date: 09/03/2021
#include <iostream>
using namespace std;
int main() {

int num[10]={10,20,30,40,50,15,25,35,45,55};
int choice;
int size=10;

string con;//for continue
int append;

cout<<"Array values: ";
for(int i=0;i<10;i++){
  cout<<num[i]<<" ";
}
cout<<endl;
cout<<"This is the list of operations "<<endl;
cout<<"1.Delete the max"<<endl<< "2.Append a number"<<endl<<"3.Reverse the array" <<endl<<endl;




do{
cout<<"enter your option: ";
cin>>choice;
cout<<endl;

  if(choice==1){//we delete the max
  int max=0;
  int remove;
  int store=0;
    for (int i = 0;  i < size; i++){
  
        if (num[i] > max){
          max = num[i];
        }
    }

    for (int i = 0;  i < size; i++){
        if(num[i]==max){
          store=i;
          num[i]=0;
        }  
     }
    for(int i=store;i<size-1;i++){
      num[i]=num[i+1];
      }
  }
  
if(choice==2){//we append
  int x=0;
  for(int i=0;i<size;i++){
    if(num[i]==0){
       cout<<"chose a number to append:";
        cin>>append;
        num[i]=append;  
        x=1;
        break;} 
  }
cout<<"nothing to append"<<endl;}

if(choice==3){//we reverse the array
int i=0; 
int j=size;
  while(i<j){
    if(num[j]==0){
     j--;
     continue;
     }
  int temp = num[i];
  num[i] = num[j];
  num[j] = temp;
  ++i;
  --j;
} }


cout<<"New array values ";
for(int i=0;i<10;i++){
  cout<<num[i]<<" ";
}
cout<<endl;
cout<<"Continue? (Y/N):";
cin>>con;
cout<<endl;

}while(con!="N"&&con!="n");}
