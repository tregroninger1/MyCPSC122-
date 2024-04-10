/*
Name: Latrevious Groninger
Class: CPSC 122
Date Submitted: March 4/12, 2024 
Assignment: Project 9 
Description: holds all the functions that are executed in 4-ListDTst.cpp
*/

#include <iostream>
using namespace std;

#include "4-ListD.h"

//All tests are controlled by a dedicated function
void TestInsert();
void TestCopyConstructor();
void TestPrintBackward();
void TestDelete();
void TestDeleteAll();

int main()
{
 //TestInsert();
 //TestCopyConstructor();
 TestPrintBackward();
 TestDelete();
 TestDeleteAll();
}



void TestInsert()
{

 ListD* lst = new ListD;
 for (int i = 1; i <= 5; i++)
  lst->Insert(i,i);

 cout << "test general case insert" << endl;
 cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 cout << "test insert at the head" << endl;
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 cout << "test insert at the tail" << endl; 
 lst->Insert(100,7);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;

 cout << "test insert within the list" << endl; 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
 lst->PrintForward();
 cout << endl;
 delete lst;
}

void TestCopyConstructor()
{
 ListD* lst1 = new ListD;
 for (int i = 1; i <= 3; i++)
  lst1->Insert(i,i);

 ListD* lst2(lst1);

 cout << "Test Copy Constructor" << endl; 
 cout << "Test passed if copy is indentical to initial list" << endl; 
 cout << "Traverse inital list" << endl;
 lst1->PrintForward();
 cout << endl;
 cout << "Traverse copy" << endl;
 lst2->PrintForward();

 //delete lst1;
 //delete lst2;
}

void TestPrintBackward()
{
  ListD* lst = new ListD;
  for (int i = 1; i <= 5; i++)
    lst->Insert(i,i);

  cout << "test printing the doubly linked list backwards" << endl;
  cout << "Passed Print Backwards Test 1 if 5 through 1 appear on subsequent lines" << endl;
  lst->PrintBackward();
  cout << endl;

  delete lst;
}

void TestDelete()
{
  ListD* lst = new ListD;
  for (int i = 1; i <= 5; i++)
    lst->Insert(i,i);

  cout << "test deleting a specific node at a position in the middle of a list" << endl;
  cout << "Passed Delete Test 1 if 1, 3, 4, 5 appear on subsequent lines" << endl;
  lst->Delete(2);
  lst->PrintForward();
  cout<<endl;

  cout << "test deleting the first node in a list" << endl;
  cout << "Passed Delete Test 2 if 3, 4, 5 appear on subsequent lines" << endl;
  lst->Delete(1);
  lst->PrintForward();
  cout<<endl;

  cout << "test deleting the last node in a list" << endl;
  cout << "Passed Delete Test 3 if 3, 4 appear on subsequent lines" << endl;
  lst->Delete(3);
  lst->PrintForward();
  cout<<endl;
  delete lst;
}

void TestDeleteAll()
{
  ListD* lst = new ListD;
  for (int i = 1; i <= 5; i++)
    lst->Insert(i,i);
  lst->Insert(3,1);
  lst->Insert(3,7);
  lst->PrintForward();

  cout << "test deleting all nodes in a list containing a certian item, in the first, middle and last spot" << endl;
  cout << "Passed Insert Test 1 if out is 3 and 1, 2, 4, 5 appear on subsequent lines. Out is: ";
  cout << lst->DeleteAll(3) << endl;
  lst->PrintForward();
  cout << endl;
  delete lst;
}