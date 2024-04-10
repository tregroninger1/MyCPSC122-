/*
Name: Latrevious Groninger
Class: CPSC 122, Section 1
Date Submitted: April, 20224
Assignment: 8 
Description: Program illustrates a linked list both head and tail pointers 
*/

#include <iostream>
using namespace std;
#include "3-ListT.h"

//Constructor
ListT::ListT()
{
 length = 0;
 head = NULL;
 tail = NULL;
}

//No need to write this function
ListT::~ListT()
{
  node* cur = head;
  while(cur != NULL)
    {
      DeleteItemH();
      cur = head;
    }
}

//This function puts a new item in at the front of the list
void ListT::PutItemH(itemType itemIn)
{
 node* tmp = new node;
 if (tail == NULL)
   tail = tmp;
 tmp->item = itemIn;
 tmp->next = head;
 head = tmp;
 length++;
}

//This function prints the items in the list
void ListT::Print() const
{
 node* cur = head;
 while(cur != NULL)
  {
   cout << cur->item << endl;
   cur = cur->next;
  }
}

//This function deletes the first item in the list
void ListT::DeleteItemH() 
{
  node* temp = head;
  head = temp -> next;
  delete temp;
  temp = NULL;
  length--;
}

//This function returns the length of the list
int ListT::GetLength() const
{
  return length;
}

//This function checks if the list it empty
bool ListT::IsEmpty() const
{
  return length == 0;
}

//This function returns the first item in the list
itemType ListT::GetItemH() const
{
return head -> item;
}

//This function returns the number of times a target item is in the list
int ListT::FindItem(const itemType target) const
{
  int count = 0;
  node* cur = head;
  while(cur != tail)
    {
      if(cur -> item == target)
        count++;
      cur = cur -> next;
    }
  return count;
}

//This function adds a new node at the end of the list
void ListT::PutItemT(const itemType itemIn){
node* tmp = new node;
  tmp->item = itemIn;
  tmp->next = NULL;
  if (head == NULL) {
    head = tmp;
    tail = tmp;
  } else {
    tail->next = tmp;
    tail = tmp;
  }
  length++;
}

//This function returns the last item in the list
itemType ListT::GetItemT() const
{
  return tail -> item;
}

//This function deletes the last item in the list
void ListT::DeleteItemT()
{
  if (head == tail) 
    {
      delete tail;
      head = NULL;
      tail = NULL;
      length = 0;
      return;
    }
    node* cur = head;
    while (cur->next != tail)
    {
      cur = cur->next;
    }

    delete tail;
    cur->next = NULL;
    tail = cur;
    length--;
}

//This function deletes a target item and returns the number of nodes deleted
int ListT::DeleteItem(const itemType target)
{
  int count = 0;
  node* cur = head -> next;
  node* prev = head;

  while (head -> item == target)
    {
    DeleteItemH();
    count++;
    }

  while (cur != NULL)
  {
    if (cur->item == target)
    {
      if (cur -> next == tail)
      {
        delete tail;
        tail = prev;
        prev -> next = tail;
        count ++;
        length--;
        return count;

      }
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
      length--;
      count++;
    }
    else
    {
      prev = cur;
      cur = cur->next;
    }
  }
  if (head->item == target)
  {
    node* temp = head;
    head = head->next;
    delete temp;
    length--;
    count++;
  }
  return count;
} 