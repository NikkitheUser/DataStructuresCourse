#include <iostream>
#include <fstream>
using namespace std;

int frequency(int arr[], int size){
   bool check[size];//this bool will determine if we have a repeat
   for(int i=0;i<size;i++){
      check[i] = 0;//all repeats in our repeat array starts at zero
   }
   for(int i=0; i<size; i++){
      if(check[i]== 1){
         continue;//if there is no repeats, only one value, then it continues
      }
      int count = 1;
      for(int j = i+1; j<size; j++){
         if (arr[i] == arr[j]){
            check[j] = 1;
            count++;//every time a repeat is found, its counted
         }
      }
      cout<<arr[i]<<"      "<< count << endl;//our result!
   }
   return 0;}


int main() {
cout<<"Enter input file name: ";
string file_name;
cin>>file_name;

ifstream f_input(file_name);
if(f_input.fail())
{
  cout<<"Error: Input file open failed.\n";
    return 0;
}
int size;
f_input>> size; //reads the first value
int count= size;//now the array has the correct number of values
int arr[count];//our array

for(int a = 0; a < count; a++){
    f_input >> arr[a];
}//all values from file is now in array

int min=arr[0];//our random starting value for min
for(int small=0;small<=count;small++){
  if(min>arr[small]){
min=arr[small];
//we go through the array and compare each value to the other
//which ever is the smallest intger becomes min
  }
}

cout<<"Min number is: "<<min<<endl;
cout<<"Number"<< " "<<"Count"<<endl;
frequency(arr, size);//the function being executed
f_input.close();
return 0;}