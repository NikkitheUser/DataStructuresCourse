
//title: lab1_1.cpp
//Abstract: this program will ask for 4 numbers and find the biggest number
//ID: 1507
//Name: Nicole Safty
//Date: 08/27/2021
#include <iostream>
using namespace std;
int main(){
int num1,num2,num3,num4;
cout<<"Enter 4 numbers: "<<endl;
cin>>num1;
cin>>num2;
cin>>num3;
cin>>num4;

if(num1>num2&&num1>num3){
    cout<<"Max is "<<num1<<endl;
}else if(num1>num4){
    cout<<"Max is "<<num1<<endl;
}//num1 is the biggest number
else if (num2>num1&&num2>num3){
    cout<<"Max is "<<num2<<endl;
}else if (num2>num4){
    cout<<"Max is "<<num2<<endl;
}//num2 is the biggest number
else if (num3>num2&&num3>num4){
    cout<<"Max is "<<num3<<endl;
    }else if (num3>num1){
    cout<<"Max is "<<num3<<endl;
}//num3 is the biggest number
else if(num4>num1&&num4>num2){
        cout<<"Max is "<<num4<<endl;
    }else if(num4>num3){
      cout<<"Max is "<<num4<<endl;
    }//num4 is the biggest number
}