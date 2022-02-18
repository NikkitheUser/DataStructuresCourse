//title: lab1_2.cpp
//Abstract: this program will draw a square and a triangle based on a user inputed number
//ID: 1507
//Name: Nicole Safty
//Date: 08/27/2021
#include <iostream>
using namespace std;
int main() {
int length;
cout<<"enter a length: ";
cin>>length;

//square
for(int i=0; i<length;i++){
    for(int x=0; x<length;x++){
        cout<<" * ";
}
cout<<endl;}

cout<<endl<<endl;//space inbetween

//triangle
for(int x=0; x<length;x++){
  for(int y=0;y<=x;y++){
cout<<" * ";
  }
cout<<endl;
}
}