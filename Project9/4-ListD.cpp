/*
Name: Latrevious Groninger
Class: CPSC 122
Date Submitted: March 4/12, 2024 
Assignment: Project 9 
Description: holds all the functions that are executed in 4-ListDTst.cpp
*/

#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

 ListD::ListD()
{
 InitializeVars();
}

ListD::ListD(ListD* lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

void ListD::InitializeVars()
{
 length = 0;

//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

//how would you do this?
ListD::~ListD()
{
  doubleNode* cur = head;
  while(cur != NULL)
      Delete(1);
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 

void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }

  cur = NULL;
}

void ListD::PrintBackward()
{
  doubleNode* cur = tail -> prev;
  int i = 0;
  while (i < length)
    {
      cout << cur->item << endl;
      cur = cur->prev;
      i++;
    }
  cur = NULL;
}

void ListD::Delete(int pos)
{
  doubleNode* cur = FindPosition(pos + 1);
  doubleNode* prev = cur->prev;
  doubleNode* next = cur->next;

  prev->next = next;
  next->prev = prev;
  delete cur;
  length--;

  cur = NULL;
  prev = NULL;
  next = NULL;
}

int ListD::DeleteAll(itemType item)
{
  int count = 0;
  doubleNode* cur = head;
  doubleNode* prev = NULL;
  doubleNode* next = NULL;

  while(cur != NULL)
    {
      if(cur->item == item)
      {
        prev = cur -> prev;
        next = cur -> next;
        prev->next = next;
        next->prev = prev;
        delete cur;
        length--;
        count++;
        cur = next;
      } else
      {
        cur = cur->next;
      }
    }
  cur = NULL;
  prev = NULL;
  next = NULL;
  return count;
}