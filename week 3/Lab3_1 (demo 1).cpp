//title: lab3_1 (demo 1).cpp
//Abstract: Using classes, we show an accounts monetary holdings. We do this by getting the amount and setting new ammounts
//ID: 1507
//Name: Nicole Safty
//Date: 09/10/2021

#include <iostream>
using namespace std;

class Money{
private: 
int dollar;
int cent;

public:
  bool setAmount(int newDollar, int newCent);
  void output( );
int getCents();
int getDollars();
void setCents(int newCent );
void setDollars(int newDollar );
};

int main() {

 Money m1, m2;  

m1.setAmount(0, 0);
m2.setAmount(0, 0);

cout<< "m1 initial amount: " << m1.getDollars()<< " and " << m1.getCents() << endl;   
 cout << "m1 output: ";  
 m1.output();
 
 m1.setDollars(20);
 m1.setCents(35);
 m2.setDollars(10);
 m2.setCents(98);

cout << "m1 new amount:" << m1.getDollars() << " and "<< m1.getCents() << endl; 
cout << "m2 output: "; 
 m2.output();   
 
 m1.setDollars(50); 
cout << "m1 new amount: ";
 m1.output();    

 return 0;
}


int Money::getDollars(){
  return dollar;
}

int Money::getCents(){
  return cent;
}

bool Money::setAmount(int newDollar, int newCent){
  dollar=newDollar;
  cent=newCent;
  if(dollar<0){ 
    cout<<"error: negative amount"<<endl;
    return false;
  }
if(cent>99||cent<0){
  cout<<"error: unstable amount"<<endl;
  return false;
}
return true;
}

void Money::output(){
  cout<<dollar<<" dollars and "<<cent<<" cents"<<endl;
}

void Money::setDollars( int newDollar){
dollar=newDollar;
}

void Money::setCents( int newCent){
cent=newCent;
}