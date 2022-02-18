//title: lab10_2.cpp
//Abstract: This Lab will calculate power with recursions. input a base number and a power number and get the result
//ID: 1507
//Name: Nicole Safty
//Date: 11/5/21
#include <iostream>
using namespace std;
int power(int x, int n);
int main() {
  
  int x,n;
  cout<<"enter X value: ";
  cin>>x;
  cout<<endl<<"enter N value: ";
  cin>>n;
  cout<<"result: "<<power(x,n)<<endl;
  return 0;
} 
int power(int x, int n){
if (n == 0) 
    {             
        return 1;  // Base case
    }
    else    
    { 
        return x * power(x ,n-1);  // Recursive case
    }
}