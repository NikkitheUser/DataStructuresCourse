//title: lab11_2.cpp
//Abstract: We will insert a node into the list. This is done by making a new node and inserting it after a selcted node.
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
   ListNode * head;
    ListNode *link; 
}; 

typedef ListNode* ListNodePtr;

void headInsert(ListNodePtr& head, int newData);
void display(ListNodePtr head);
bool find(ListNodePtr ptr, int target);
ListNodePtr search(ListNodePtr ptr, int target);
void appendNode(ListNodePtr& head, int newData);
void insert(ListNodePtr afterMe, int theData);




//afterme function
void insert(ListNodePtr afterMe, int theData)
{ 
 ListNodePtr p = new ListNode;//we create the new node to insert
    p->data = theData; //the node now has data from the main function
    p->link = afterMe->link;//the node will now link "afterMe"
    afterMe->link = p;
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

cout << "\n===== Afterme Function Test =====" << endl;

insert(first,4867);
display(first);
    
    return 0;
}


