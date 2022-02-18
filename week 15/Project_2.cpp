//title: Project2.cpp
//Abstract: This project requires implmentation of 7 functions. 1. a function that reads through a txt file and creats accounts. 2. a close account function 3. a function that displays an account with either a SSN,account number or last name. 4.a disply of the number of accounts&customers. 5. account balance transfer 6. display all account information and 7. exit the program
//ID: 1507
//Name: Nicole Safty
//Date: 12/09/21


#include <iostream>
using namespace std;
class Account;
#include <fstream>
class Account
{
public:
Account();    // Constructor
    Account(int capacityValue);
    int getCapacity( ) const { return myCapacity; }
    int getNumberUsed( ) const { return mySize; }
     ~Account( );              // Destructor
     Account(const Account& org); // Copy constructor
     Account& operator =(const Account& rightSide);  // Assignment operato
  bool setAccount(int SSN,string newFirst, string newLast, int newNumber, int newType, double newBalance);
void displayAccountInfo();
int newSize(int size);
 

//functions for the choices
void choiceThree(Account * ptr[], int size);//3
void totalSSN(Account * ptr[], int size);//4
void countAccounts(Account * ptr[], int size);//4
void countCustomers();//4


//get/remake integers
   int getType();//get checking or saving
    int getaccount();//get account number
       string getFirst();//get first name back
    string getLast();//get last name back
   int getSSN();//get SSN back
   double getBalance();//get money number
   double newBalance(double transfer);//for the transfer, new balance
   int getSize();//the size of the array
   

private:
 int mySize;     // current size of list
   int myCapacity; // capacity of array
   int newCapacity;
   int * myArray;  // pointer to dynamic array
   int * newArray;
 int account;//account number
  int type;//checking or savings
  int SSN;//social security 
  double balance;//money
  string first;//first name
  string last;//last name
};


//--- Definition of class constructor
Account::Account()     
: mySize() ,myCapacity(20)
{
   myArray = new int[myCapacity];
}


//Destructor
Account::~Account( )
{
   delete [] myArray;
}

int Account::newSize(int size){
  int mySize=size;
return mySize;
}


// Copy constructor
Account::Account(const Account& org)
  :myCapacity(org.getCapacity( )), mySize(org.getNumberUsed( ))
{
    myArray = new int[myCapacity];
    for (int i = 0; i < mySize; i++)
    {
        myArray[i] = org.myArray[i];
    }
}

// Assignment operator
Account& Account::operator =(const Account& rightSide)
{
    // Check for self-assignment
    if (this != &rightSide)
    {
        if (myCapacity != rightSide.myCapacity)
        {
            delete [] myArray;
            myArray = new int[rightSide.myCapacity];
        }
    
        myCapacity = rightSide.myCapacity;
        mySize = rightSide.mySize;
        for (int i = 0; i < mySize; i++)
        {
            myArray[i] = rightSide.myArray[i];
        }
    }
    
    return *this;
}

Account::Account(int capacityValue)     
: mySize(0), myCapacity(capacityValue)
{
    myArray = new int[myCapacity];
}
bool Account::setAccount(int newSSN,string newFirst, string newLast, int newNumber, int newType, double newBalance)
{
    first = newFirst;
    last=newLast;
    SSN=newSSN;
    account = newNumber;
    if (newType == 1 || newType == 2)
    {
        type = newType;
    }
    else
    {
        cout << "Error: Incorrect account type." << endl;
        return false;
    }
    if (newBalance < 0.0)
    {
        cout << "Error: Negative balance is not acceptable." << endl;
        return false;
    }
    else
    {
        balance = newBalance;
    }
    mySize++;
    return true;
}
void Account::displayAccountInfo( )
{
    cout << "\n======================================" << endl;
    cout<< "Account Holder SSN: "<< SSN<<endl;
    cout << "Account Holder Name: " << first<<" "<<last << endl;
    cout << "Account Number: " << account << endl;
    cout << "Account Type: " << type << endl;
    cout << "Current Balance: $" << balance << endl;
    cout<<endl;
}

//6
void displaySix(Account * ptr[], int size);
void displaySix(Account * ptr[], int size){
  if(size>20){
      
  for(int i=0;i<20;i++){

    cout<< "Account Holder SSN: "<< ptr[i]->getSSN()<<endl;
    cout << "Account Holder Name: " << ptr[i]->getFirst()<<" "<<ptr[i]->getLast() << endl;
  cout<<endl;
  }
  }

  if(size<20){
  for(int i=0;i<size;i++){

    cout<< "Account Holder SSN: "<< ptr[i]->getSSN()<<endl;
    cout << "Account Holder Name: " << ptr[i]->getFirst()<<" "<<ptr[i]->getLast() << endl;
  cout<<endl;
  }}
}

//3
void choiceThree(Account * ptr[], int size){
  int pick;//for choices
int find;//find the ssn or account
string look;//find the name
cout<<"SSN(1)/Last Name(2)/Account Number(3): ";
cin>>pick;
if(pick<0||pick>=4){
  cout<<"Error: not allowed"<<endl;
}
if (pick==1){//SSN
cout<<endl<<"Enter SSN: ";
cin>>find;
int account_index = -1;
    for(int i = 0; i < size; i++)
    {
        if(ptr[i]->getSSN() == find)
        {
           account_index = i;
           ptr[i]->displayAccountInfo();
           break;
            }
    }
if(account_index==-1){
  cout<<"No one with this SSN"<<endl;
}
            }
if(pick==2){//Last Name
cout<<endl<<"Enter Last name: ";
cin>>look;
int account_index = -1;
    for(int i = 0; i < size; i++)
    {
      if(ptr[i]->getLast() == look)
       {
         account_index = i;
         ptr[i]->displayAccountInfo();
        continue;
        }
    }
if(account_index==-1){
  cout<<"No one with this Last name"<<endl;
}
              }
if(pick==3){//Account
cout<<endl<<"Enter Account number: ";
cin>>find;
int account_index = -2;
    for(int i = 0; i < size; i++)
    {
       
      if(ptr[i]->getaccount() == find)
      {
        account_index = i;
         ptr[i]->displayAccountInfo();
        break;
      }
    }
if(account_index==-1){
  cout<<"No one with this account number"<<endl;
}
            }
}

//4
void totalSSN(Account * ptr[], int size){
  int counter=size;
  int skip=-1;
  for(int i=0;i<size;i++){
    for(int j=1+i;j<size;j++){
    if(ptr[i]->getSSN()==ptr[j]->getSSN()){
skip=j;
counter--;
    }
    if(i==skip){
      continue;
    }
  }
  }
  cout<<counter<<endl;

  for(int i=0;i<size;i++){
    if(i==skip){
      continue;
    }
    else{
    cout<<ptr[i]->getFirst()<<" "<<ptr[i]->getLast()<<":"<<ptr[i]->getSSN()<<" - "<<ptr[i]->getaccount()<< ": "<< "$"<<ptr[i]->getBalance()<<endl;}
    }
  }

//4
void countAccounts(Account * ptr[], int size);
void countAccounts(Account * ptr[], int size){//shows account and balance
for(int i =0;i<size;i++){
  if(ptr[i]!=nullptr){
    cout<<ptr[i]->getaccount()<< ": "<< "$"<<ptr[i]->getBalance();
if(ptr[i]->getType()==1){
cout<<"(checking)"<<endl;
}
if(ptr[i]->getType()==2){
  cout<<"(savings)"<<endl;
}
  }
  else{
    continue;
  }
} 
}

void Account::countCustomers(){//shows account and balance
cout<<first<<" "<<last<<":"<<SSN<<" - "<<account<< ": "<< "$"<<balance<<endl;
}

//for choice 5
void transfer(Account * ptr[], int size,int account1, int account2,double money);
void transfer(Account * ptr[], int size,int account1, int account2,double money){
int flag=0;
  int account1_index=-1;
 int account2_index=-1;
  int account1_ssn,account2_ssn;
for(int i = 0; i < size; i++)
    {
      for(int j=1-i;j<size;j++){
        // Should check if there is an object in the pointer.
        // This nullptr checking is very important.
        // Otherwise, the program may crash.
        if(ptr[i] != nullptr)
        {
            if(ptr[i]->getaccount() == account1&&ptr[j]->getaccount()==account2)
            {
              flag++;
                account1_index = i;
                account2_index=j;
                break;
            }
}}
if (flag==0){
cout<<"error: account(s) were not found"<<endl;
return;
}
}
if(ptr[account1_index]->getSSN()==ptr[account2_index]->getSSN()){
  //this means its from two accounts belonging to the same person 
  double balance1=ptr[account1_index]->getBalance();
  double balance2=ptr[account2_index]->getBalance();
  balance1=balance1-money;
  if(balance1<0){
    cout<<"Transfer Fail – Insufficient amount."<<endl;
    return;
  }
  balance2=balance2+money;
  ptr[account1_index]->newBalance(balance1);
  ptr[account2_index]->newBalance(balance2);
  cout<<"Transfer Succesful"<<endl;
  cout<<"New Balance"<<endl;
  cout<<account1<<": $"<<balance1<<endl;
  cout<<account2<<": $"<<balance2<<endl;
  
}
else if( ptr[account1_index]->getSSN()!=ptr[account2_index]->getSSN()){//means that two accounts are not the same person
money=money-5;
 double balance1=ptr[account1_index]->getBalance();
  double balance2=ptr[account2_index]->getBalance();
  balance1=balance1-money;
  if(balance1<0){
    cout<<"Transfer Fail – Insufficient amount."<<endl;
    return;
  }
  balance2=balance2+money;
  ptr[account1_index]->newBalance(balance1);
  ptr[account2_index]->newBalance(balance2);
  cout<<"Transfer Succesful"<<endl;
  cout<<"New Balance"<<endl;
  cout<<account1<<": $"<<balance1<<endl;
  cout<<account2<<": $"<<balance2<<endl;
 

}
if(account1_index==-1)
{
cout<<"Incorrect Account number"<<endl;
}
if(account1_index!=-1&&account2_index==-2)
{
  cout<<"Incorrect SSN number"<<endl;
}
}

  int Account::getaccount()
  {
return account;
  }

  int Account::getSSN()
  {
return SSN;
  }

  double Account::getBalance()
  {
    return balance;
  }
string Account::getFirst()
{
  return first;
}
  string Account::getLast()
  {
return last;
  }

  int Account::getType()
  {
  return type;
  }

  double Account::newBalance(double transfer)
  {
balance=transfer;
return balance;
  }

int main() {
Account a;
 Account *acc_ptr[20];//this is the capacity
int size;//size of array
int choice=0;

while(choice!=7)
{
  cout<<endl;
  cout<<"Select your choice:"<<endl;
cout<<"1. Read customer data file"<<endl; 
cout<<"2. Close an account"<<endl;
cout<<"3. Customer Info"<<endl;
cout<<"4. Bank Info"<<endl;
cout<<"5. Transfer Money"<<endl;
cout<<"6. Customer List"<<endl;
cout<<"7. Exit"<<endl;

cout<<"make a choice:";
cin>>choice;

//in case if user chose wrong option
if(choice>=8||choice<=0)
{
  cout<<"not valid option"<<endl;
}

//read customer data file
if(choice==1){
cout << "Enter input file name: ";
    string file_name;
    cin >> file_name;

    ifstream f_input(file_name);
    if (f_input.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }
f_input>>size;
a.newSize(size);
string first, last;
int SSN,account,type;
double balance;
for(int i=0;i<size;i++)
{
  f_input>>SSN>>first>>last>>account>>type>>balance;
  acc_ptr[i] = new Account;
    acc_ptr[i]->setAccount(SSN,first,last, account, type, balance);
}

for(int i=0;i<size;i++){
  acc_ptr[i]->displayAccountInfo();
}
for(int i=0;i<size;i++){
  for(int j=i+1;j<size;j++){
    //If SSN is the same, check the names
    if(acc_ptr[i]->getSSN()==acc_ptr[j]->getSSN())
    {
if(acc_ptr[i]->getLast()==acc_ptr[j]->getLast()&&acc_ptr[i]->getType()!=acc_ptr[j]->getType())
{
  cout<<"These are owned by the same customer, but "<<acc_ptr[i]->getaccount()<< " is "<< acc_ptr[i]->getType()<< "and "<<acc_ptr[j]->getaccount()<< " is "<< acc_ptr[j]->getType()<<endl;
}
if(acc_ptr[i]->getLast()==acc_ptr[j]->getLast()&&acc_ptr[i]->getType()==acc_ptr[j]->getType())
{
  cout<<acc_ptr[i]->getFirst()<<" "<<acc_ptr[i]->getLast() <<"cannot have two "<< acc_ptr[i]->getType()<<" accounts"<<endl;
   int account_index=j;
   for(int z = account_index; z< size; z++)
    {
        acc_ptr[z] = acc_ptr[z + 1];
    }
}
if(acc_ptr[i]->getLast()!=acc_ptr[j]->getLast())
{
  cout<<"A customer with SSN " << acc_ptr[i]->getSSN()<<" already exists."<<endl;
  int account_index=j;
   for(int z = account_index; z< size; z++)
    {
        acc_ptr[z] = acc_ptr[z + 1];
    }
  size--;
  continue;
}
    }
    if(acc_ptr[i]->getaccount()==acc_ptr[j]->getaccount())
    {
      cout<<"Account number "<<acc_ptr[i]->getaccount()<<" already exists"<<endl;
      int account_index=j;
   for(int z = account_index; z < size; z++)
    {
        acc_ptr[z] = acc_ptr[z + 1];
    }
    size--;
    continue;
      }
    }
  }
}


//close an account
if(choice==2){
  int account_num,account_ssn;
 cout << "Enter an account number: ";
    cin >> account_num;
    cout<<"Enter Accounts SSN:";
    cin>>account_ssn;
    int account_index = -1;
    for(int i = 0; i < size; i++)
    {
        if(acc_ptr[i] != nullptr)
        {
            if(acc_ptr[i]->getaccount() == account_num && acc_ptr[i]->getSSN())
            {
                account_index = i;
                break;
            }
       if(acc_ptr[i]->getaccount() == account_num && acc_ptr[i]->getSSN()!=account_ssn)
            {
                account_index = -2;
                break;
            } 
          }
    }
    if(account_index == -1)
    {
        cout << "Account closing failed. Account number doesn’t exist." << endl;
    }
    else if(account_index==-2){
      cout<<"SSN is incorrect;"<<endl;
    }
    else
    {
      acc_ptr[account_index]->displayAccountInfo();
        // Shift array elements left to close the gap
    for(int i = account_index; i < size; i++)
    {
        acc_ptr[i] = acc_ptr[i + 1];
    }
    size--;
        cout << "Account closed." << endl;
    }
}



//find account with SSN,last name or account
if(choice==3){
choiceThree(acc_ptr,size);
}


if(choice==4){//bank Info
  cout<<endl<<"Number of Accounts: "<<size<<endl;
  countAccounts(acc_ptr, size);
  
  //find total of SSN;
  cout<<endl<<"Number of Customers:";
  totalSSN(acc_ptr,size);
  double total=0;
  for(int i=0;i<size;i++){
    total+=(*acc_ptr[i]).getBalance();
  }
  cout<<"Total Balance: $"<<total<<endl;
}
//transfer
if(choice==5){
  int a1, a2;
  double money;
  cout<<"Source Account: ";
  cin>>a1;//account 1
  cout<<"Destination Account: ";
  cin>>a2;//account 2
  cout<<"Money Account: ";
  cin>>money;//the money from account1 to account 2
 transfer(acc_ptr,size,a1,a2,money);
}

//show the list
if(choice==6){
  cout<<"========== Customer List =========="<<endl;
displaySix(acc_ptr,size);
cout<<"===================================";
}

//close program
if(choice==7){
  cout<<"goodbye";
  return 0;
}

}}
