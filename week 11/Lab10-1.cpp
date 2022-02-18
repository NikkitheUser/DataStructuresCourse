//title: lab10_1.cpp
//Abstract: This Lab introduces the idea of Merge sort. 2 arrays are made (already sorted), and we add them into a combined array, without sorting them
//ID: 1507
//Name: Nicole Safty
//Date: 11/5/21
#include <iostream>
using namespace std;
int main() {

  int num;//values in arrays
  int n,m;//the size of array1 & array2
  int countn=0;
  int countm=0;
 

  cout<<"Enter the first size of the Array:";
  cin>>n;
    int array1[n];
  cout<<endl<<"Enter the Array content: ";
  for(int i=0;i<n;i++){
    cin>>num;
    array1[i]=num;
  }
//sort array1
 for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
    if(array1[i]>array1[j]){
    int temp=array1[i];
    array1[i]=array1[j];
    array1[j]=temp;
    }
  }
  }

cout<<"Enter the Second size of the Array:";
  cin>>m;
  int array2[m];
  cout<<endl<<"Enter the Array content: ";
  for(int i=0;i<m;i++){
    cin>>num;
    array2[i]=num;
  }//sort array2
  for(int i=0;i<m;i++){
  for(int j=i+1;j<m;j++){
    if(array2[i]>array2[j]){
    int temp=array2[i];
    array2[i]=array2[j];
    array2[j]=temp;
    }}}
cout<<endl<<"combined Array: "<<endl;

int x=n+m;//combined size of final array
 int combo[x];
 int countx=0; 

while(countx<=x){
  if(array2[countm]==array2[m]){//when array2 is finsihed, it wont keep counting
    for(int i=countn;i<=n;i++){
  combo[countx]=array1[countn];
  countx++;
  countn++;}
}
 else if(array1[countn]==array1[n]){//when array 1 is finished, it wont keep counting it
    for(int i=countm;i<=m;i++){
  combo[countx]=array2[countm];
  countx++;
  countm++;}
}

 else if(array1[countn]<array2[countm]){//if array one is smaller, it gets added
  combo[countx]=array1[countn];
  countx++;
  countn++;
}
else if(array1[countn]>array2[countm]){//if array2 is smaller it gets added
  combo[countx]=array2[countm];
  countx++;
  countm++;
}
else if(array1[countn]==array2[countm]){//if they are the same number, array1 goes first and then array 2
  combo[countx]=array1[countn];
  countx++;
  countn++;
  combo[countx]=array2[countm];
  countx++;
  countm++;
} 


}
for(int i=0;i<x;i++){//the final array
  cout<<" "<<combo[i]<<" ";
}
  }