//Title: hw0_1.cpp
//Abstract: This program will read a positive integer from a user and then display the sum
//ID: 1507
//Name: Nicole Safty
//Date: 08/23/2021
#include <iostream>
using namespace std;

int main() {
 int user;//the intger taking by the user
int ans=0;//the answer for the user
//int sum=0;
int p=0;

string response= "y"; 
do{
cout<<"Enter a number: ";
cin>>user;
ans=0;//we add this to insure that the count resets
for(int i=0;i<=user;i++){
ans+=i;
}
cout<<ans<<endl;
cout<<"Repeat?(y/n)";
cin>>response;

}while (response == "y");
if(response=="n"){
  cout<<"bye!";
}
}