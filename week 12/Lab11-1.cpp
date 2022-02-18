//title: lab11_1.cpp
//Abstract: A replace function has been added. The function will pick a postion and replace the data of the chosen node
//ID: 1507
//Name: Nicole Safty
//Date: 11/12/21
/*
 * Title: LinkedList_struct_v2.cpp
 * A sample linked list using struct.
 * This program is updated by Dr. Byun based on the code
 * from Savitch's textbook.
 */
#include <iostream>
using namespace std;

struct ListNode 
{
    int data;
    ListNode *link; 
}; 

typedef ListNode* ListNodePtr;

void headInsert(ListNodePtr& head, int newData);
void display(ListNodePtr head);
bool find(ListNodePtr ptr, int target);
ListNodePtr search(ListNodePtr ptr, int target);
void appendNode(ListNodePtr& head, int newData);
void replace(ListNodePtr head, int target, int newData);

//replace function
void replace(ListNodePtr head, int target, int newData)
{
  int flag=0;
 ListNodePtr nodePtr; 
   while(nodePtr != nullptr) {
      if(head->data == target) {
        flag++;
         head->data = newData;
         return;
      } 
      if(flag==0){
         cout<<"Nothing to replace"<<endl;
      return;
      }
}
 
}
// Function to add a new node at the head of the linked list
void headInsert(ListNodePtr& head, int newData)
{
    ListNodePtr p = new ListNode;
    p->data = newData;
    p->link = head;
    head = p;
}


// A function to append a new node to the end of the list.   
void appendNode(ListNodePtr& head, int newData)
{
   ListNodePtr newNodePtr;  // To point to a new node
   ListNodePtr nodePtr;     // To move through the list

   // Allocate a new node and store data.
   newNodePtr = new ListNode;
   newNodePtr->data = newData;
   newNodePtr->link = nullptr;

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
   {
      head = newNodePtr;
   }
   else// Otherwise, insert newNode at the end.
   {
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find the last node in the list.
      while (nodePtr->link)
      {
         nodePtr = nodePtr->link;
      }

      // Insert newNode as the last node.
      nodePtr->link = newNodePtr;
   }
}


// Display every node one by one
void display(ListNodePtr ptr)
{
    cout << "===== Content =====" << endl;
    while (ptr != nullptr) 
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}



bool find(ListNodePtr ptr, int target)
{
    while (ptr != nullptr) 
    {
        if (ptr->data == target)
        {
            return true;
        }
        ptr = ptr->link;
    }
    
    return false;
}


ListNodePtr search(ListNodePtr ptr, int target)
{
    while (ptr != nullptr) 
    {
        if (ptr->data == target)
        {
            return ptr;
        }
        ptr = ptr->link;
    }
    
    return ptr;
}


int main()
{
    // A linked list with the head named "first".
    ListNodePtr first = nullptr;
    ListNodePtr p;
    
    appendNode(first, 300);
    appendNode(first, 400);
    display(first);
    
    headInsert(first, 200);
    headInsert(first, 100);
    appendNode(first, 500);
    display(first);

    cout << "\n===== Search Function Test =====" << endl;
    p = search(first, 100);
    if(p != nullptr)
        cout << p->data << " found" << endl;
    else
        cout << "100 not found" << endl;    
    
    p = search(first, 101);
    if(p != nullptr)
        cout << p->data << " found" << endl;
    else
        cout << "101 not found" << endl;    

cout << "\n===== Replace Function Test =====" << endl;
replace(first,100,30);
        display(first);
    
    return 0;
}

