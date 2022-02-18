//title: lab3_1.cpp
//Abstract: Using classes, we show an accounts monetary holdings. We do this by getting the amount and setting new ammounts. we then add more money into the account
//ID: 1507
//Name: Nicole Safty
//Date: 09/12/2021
#include <iostream>
#include <string>
using namespace std;
class Money
{
  public:
bool setAmount(int newDollars, int newCents);
int getDollars();
int getCents();
bool setDollars(int sDollars);
bool setCents(int sCents);
void output();
void addAmount(int aDollars, int aCents);

 private:
int dollars;
int cents;
};
int main(){
  Money m1, m2;
  m1.setAmount(0, 0);
  m2.setAmount(25, 95);

  cout << "m1 output: ";
  
  m1.output();
 
  cout << "m2 output: ";
  m2.output();
  m1.addAmount(75, 9);
  m2.addAmount(30, 10);
  
  cout << "\n=== After addAmount() ===" << endl;
  cout << "m1 output: ";
 
  m1.output();
  cout << "m2 output: ";
 
  m2.output();
  return 0;}
int Money::getDollars(){
  return dollars;
}

int Money::getCents(){
  return cents;
}
bool Money::setAmount(int newDollars, int newCents)
{if ((newDollars < 0) || (newCents < 0)){
  cout << "Error: Negative amount cannot be accepted\n";return false;}
else if(newCents > 100)
{
  cout << "Error: Cents cannot exceed the 99 cent mark\n";
  return false;
  }else
  {dollars = newDollars;
  cents = newCents;
  return true;
  }}

    void Money::output(){
      cout << dollars << " dollars and " << cents << " cents\n";
      }



bool Money::setDollars(int sDollars){
dollars=sDollars;
return true;
}

bool Money::setCents(int sCents){
cents=sCents;
return true;
}

void Money::addAmount(int Adddollar, int Addcent){
dollars+=Adddollar;
cents+=Addcent;

if(cents>=100){
  cents=cents-100;
  dollars=dollars+1;
}
}