//title: hw8_2.cpp
//Abstract: For this lab, we are using list nodes. We implemented a function that inserts a node in a specfic spot and warns us if the spot is out of range. We also added a 
//function that checks if the nodes are sorted in ascending order or not
//ID: 1507
//Name: Nicole Safty
//Date: 11/18/21
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
int counter();
bool find(ListNodePtr ptr, int target);
ListNodePtr search(ListNodePtr ptr, int target);
void appendNode(ListNodePtr& head, int newData);
void insert(ListNodePtr& head, int value, int index);//our new insert function
bool isSorted(ListNodePtr head);//check if the nodes are in ascending order


int counter(){//this counts the nodes in the list. each time insert is used, the counter goes up.
  int nodes=1;
  return nodes;
}

//insert the new node at a specfic position
void insert(ListNodePtr& head, int value, int index){
ListNodePtr temp1 = new ListNode();
   temp1->data = value;
   temp1->link = NULL;
   if (index == 0){
    temp1->link = head;
    head = temp1;
    return;
   }
      if(index<0||index>counter()){//if the index is out of range
cout<<"Error: out of range!"<<endl;
return;
   }
   ListNodePtr temp2 = head;
   if(index>0){
   for (int i=0;i<index-1;i++) {
     temp2=temp2->link;}
 temp1->link = temp2->link;
   temp2->link = temp1;
    int counter(+1);//a node is added, the list is bigger
   return;
}}//used the video from lecture 18.2 as a guide to getting this right


bool isSorted(ListNodePtr head){
   ListNodePtr temp;
    if (head == NULL){ //if its empty
    cout<<"sorted"<<endl;
        return true; }
    for (temp=head; temp->link != NULL; temp=temp->link) {
       if (temp->data > temp->link->data) {//if node one is bigger than the the node next to it, its not sorted
            cout<<"not sorted"<<endl;
            return false; 
}}
            cout<<"sorted"<<endl;
    return true; 
}

// Function to add a new node at the head of the linked list
void headInsert(ListNodePtr& head, int newData)
{
    ListNodePtr p = new ListNode;
    p->data = newData;
    p->link = head;
    head = p;
   int counter(+1);
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
   int counter(+1);
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
  
 ListNodePtr head = nullptr;
    insert(head, 100, 5); // Should display "Error: Out of range."
    insert(head, 100, 0); 
    display(head);    // Should display "100".
    insert(head, 50, 0); 
    display(head);    // Should display "50 100".
    insert(head, 200, 1); 
    display(head);    // Should display "50 200 100".
   insert(head, 200, 6); 
    return 0;
}