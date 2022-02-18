
//title: hw6_2.cpp
//Abstract: We read from the text file and put the values in a dynamic array. we can append numbers, delete duplicates, sort the array or show duplicates.
//ID: 1507
//Name: Nicole Safty
//Date: 10/31/21
#include <iostream>
using namespace std;
#include <fstream>
int main()
{
cout << "Enter input file name: ";
    string file_name;
    cin >> file_name;

    ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }
int* ptr;
    int truesize;
    
      string ans="y";
  
    f_input>>truesize;
  
     ptr= new int[truesize];
    int size=truesize;//size vs. truesize so we know when option 1 is too full
  
  int value;
    cout << "Enter the number of values: ";

for(int i=0;i<truesize;i++){
  f_input>>value;
 
  ptr[i]=value;
}

    //show array as it is
    cout<<"Array Values:"<<endl;
   for(int i=0;i<truesize;i++){
cout<<" "<<ptr[i]<<" ";
   }

cout<<"This is a list of operations:"<<endl;
cout<<"1. Append Number"<<endl;
cout<<"2. Delete duplicated numbers"<<endl;
cout<<"3. Sort numbers"<<endl;
cout<<"4. Display duplicated numbers"<<endl;

do{
  int option=0;
  cout<<"Enter your option: ";
  cin>> option;


//1.append numbers to the back
  if(option==1){

if(truesize==size){
  cout<<"No space to append the array!"<<endl;
}
else if(truesize!=size){
  int num;
  cout<<"enter a value to add to the array: ";
  cin>>num;
  size++;
   ptr[size-1]=num;
  cout<<endl<<"New Value Arrays:";
  for(int i=0;i<size;i++){
    cout<<" "<<ptr[i]<<" ";
  }
}
cout<<endl;
  }


//2.delete the duplicates
  if(option==2){
    int *newarray;
    int same=0;
 newarray= new int [size];
for(int i=0;i<size;i++){
   newarray[i]= ptr[i];
}
for(int i=0;i<size;i++){
  for(int j=1+i;j<size;j++){
if(newarray[i]==newarray[j]){
same++;
   for(int x=i;x<size;x++){
newarray[x]=newarray[x+1];
}same++;
   for(int l=j;l<size;l++){
newarray[l]=newarray[l+1];
}
}
  }}
size-=same;
cout<<size<<endl;
for(int i=0;i<size;i++){
  ptr[i]=newarray[i];
}

 
cout<<"New Array Values:";

for(int i=0;i<size;i++){
  cout<<" "<<ptr[i]<<" ";
}

cout<<endl;
}
  

  //3.sort numbers from low to high
if (option==3){
for(int i=0;i<size;i++){
  for(int j=i+1;j<size;j++){
    if(ptr[i]>ptr[j]){
    int temp=ptr[i];
    ptr[i]=ptr[j];
    ptr[j]=temp;
    }
  
  }
}
cout<<"New Array Values:";
for(int i=0;i<size;i++){
  cout<<" "<<ptr[i]<<" ";
}
cout<<endl;
}

//4.show the duplicates
if(option==4){
  int flag=0;
  int v=1;
  int newarray[size];
  for(int i=0;i<size+1;i++){
    newarray[i]=ptr[i];
  }
  for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (newarray[i] == newarray[j]) {
                if (v == 1 && newarray[j] != '\0') {
                    cout << newarray[i] << " ";
                    flag++;
                }
                newarray[j] = '\0';
                v++;
            }
        v = 1;}}
        
        if(flag==0){
          cout<<"there is no duplicates"<<endl;
        }
}

cout<<endl;
cout<<"Continue? (y/n):";
cin>>ans;
if(ans=="n"||ans=="N"){

}
}while(ans=="y"||ans=="Y");
   
    // release the dynamic array
    delete [] ptr;
    ptr = nullptr;

    cout << "Bye!" << endl;
    
    return 0;
}