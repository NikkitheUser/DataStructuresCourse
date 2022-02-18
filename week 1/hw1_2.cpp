//title: hw1_2.cpp
//Abstract: this program will read an input file and then crate a histrogram
//ID: 1507
//Name: Nicole Safty
//Date: 08/27/2021
#include <iostream>
#include <fstream>
using namespace std;
int main() {
cout << "Enter input file name: ";
    string file_name;
    cin >> file_name;
    
 
    ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }


//this took way too long for me to figure out
//had to use arrays, but i forgot how that works with file inputs
//then figuring out the histogram made me lose it
//this was a fun first hw assignment
    cout<<"===== Vertical Histogram ====="<<endl;
  int max=0;//the biggest    
int count=8;
int arr[count];     

for(int a = 0; a < count; a++){
    f_input >> arr[a];
}



for(int check=0;check<8;check++){
  if(arr[check]>max){
    max=arr[check];
  }
}
  
  for(int rows=max;rows>=1;rows--){
    for(int cols=0;cols<=7;cols++){
      if(arr[cols]>=rows){
        cout<<"* ";}
        else{
          cout<<"  ";
        }
       
      }
     cout<<endl;
  
}
cout<<"-------------"<<endl;
for(int x=0; x<7;x++){
  cout<<arr[x]<<" ";
}
   f_input.close();
   return 0; 

}