//Title: hw0_2.cpp
//Abstract: This program will take in 5 integers, point out and remove the smallest integer 
//and then average out the other integers
//ID: 1507
//Name: Nicole Safty
//Date: 08/23/2021
#include <iostream>
using namespace std;

int main() {
int score[5];//array of user entered integers
int bad=score[0]; //the integer that is the lowest
int sum=0;//the sum of all added integers
float avg=0;//the average of the sum

cout<<"Enter a score ";
cin>>score[0];
cout<<"Enter a score ";
cin>>score[1];
cout<<"Enter a score ";
cin>>score[2];
cout<<"Enter a score ";
cin>>score[3];
cout<<"Enter a score ";
cin>>score[4];

    for(int i = 0; i < 5; i++){
        if(score[i] < bad){
            bad = score[i];
        }
    }
 
cout<<"ignore the worst score "<<bad<<endl;
   for(int i = 0; i < 5; i++){
        if(score[i] == bad){
            score[i]=0;
        }
    }
 for(int w = 0; w < 5; w++) {
       if(score[w]/=bad){ 
        sum += score[w];}
else{
  continue;
}
    }
    avg = (float)sum / 4;
cout<<"the average "<<avg;


}