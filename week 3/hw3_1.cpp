//title: hw3_1.cpp
//Abstract: This program reads a structure from a file. It then takes the scores, removes the min score and then averages them. 
//the program then sorts by Id and then by the highest average 
//ID: 1507
//Name: Nicole Safty
//Date: 09/13/2021
#include <iostream>
#include<fstream>
using namespace std;

struct Account{
string student;
int id;
double score[5];

};
int main() {
int size;//the number of students
Account arr[30];
double avg[30];
double sum[30];
double small[30];

  cout<<"enter file name: ";
  string file_name;
    cin >> file_name;
    ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }

    f_input>>size;//get the size
  
for(int i=0;i<=size;i++){//read the numbers
   f_input>>arr[i].student>>arr[i].id>>arr[i].score[0]>>arr[i].score[1]>>arr[i].score[2]>>arr[i].score[3]>>arr[i].score[4];
}

for(int i=0;i<=size;i++){
  small[i]=11;
  sum[i]=0;
  avg[i]=0;
}

  for(int i=0;i<=size;i++){//find the smallest score
    for(int j=0;j<=4;j++){
  if(small[i]>arr[i].score[j]){
small[i]=arr[i].score[j];
}else{
  continue;
}}}
for(int i=0;i<=size;i++){
  for(int j=0;j<=4;j++){
  if(small[i]==arr[i].score[j]){
arr[i].score[j]=0;//make the smallest score 0
break;
}
else{
  continue;
}}
}



for(int i=0;i<=size;i++){//add all scores
  for(int j=0;j<=4;j++){
    sum[i]+=arr[i].score[j];}}

for(int i=0;i<=size;i++){//find the average 
  for(int j=0;j<=4;j++){
    avg[i]=sum[i]/4;}}



cout<<"======= Order By ID Number ======="<<endl;//sort by id
for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(arr[i].id>arr[j].id)
			{
				int temp = arr[i].id;
				arr[i].id=arr[j].id;
				arr[j].id=temp;

        int tempa = avg[i];
				avg[i]=avg[j];
				avg[j]=tempa;
			}
		}
	}
for(int i=0;i<size;i++){
  cout<<arr[i].id<<": "<<avg[i]<<endl;
}


cout<<"======= Order By Average ======="<<endl;//sort by Avg;
for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(avg[i]<avg[j])
			{
				int temp = arr[i].id;
				arr[i].id=arr[j].id;
				arr[j].id=temp;

        int tempa = avg[i];
				avg[i]=avg[j];
				avg[j]=tempa;
			}
		}
	}
for(int i=0;i<size;i++){
  cout<<arr[i].id<<": "<<avg[i]<<endl;
}

 f_input.close();
return 0;
}