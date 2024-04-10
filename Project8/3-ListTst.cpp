/*
Name: Latrevious Groninger
Class: CPSC 122, Section 1
Date Submitted: March, 2022
Assignment: 8 
Description: Program illustrates a linked list both head and tail pointers 
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{
  ListT lst;

  cout << "Test PutItemH and Print" << endl;
  cout << "Correct if output is 4, 3, 2, 1, 0 on subsequent lines" << endl;
    for (int i = 0; i < 5; i++) 
      lst.PutItemH(i);


  lst.Print();
  cout << endl;

  cout << "Test IsEmpty" << endl;
  cout << "Correct if output is 0" << endl;
  cout << lst.IsEmpty() << endl;
  cout << endl;

  cout << "Test GetLength" << endl;
  cout << "Correct if output is 5" << endl;
  cout << lst.GetLength() << endl;
  cout << endl;

  cout << "Test GetItemH" << endl;
  cout << "Correct if output is 4" << endl;
  cout << lst.GetItemH() << endl;
  cout << endl;

  cout << "Test DeleteItemH and prints" << endl;
  cout << "Correct if output is 3, 2, 1, 0 on subsequent lines" << endl;
  lst.DeleteItemH();
  lst.Print();
  cout << endl;

  cout << "Test FindItem" << endl;
  cout << "Correct if output is 1" << endl;
  cout << lst.FindItem(2) << endl;
  cout << endl;

  cout << "Test PutItemT and Print" << endl;
  cout << "Correct if output is 3, 2, 1, 0, 8 on subsequent lines" << endl;
  lst.PutItemT(8);
  lst.Print();
  cout << endl;

  cout << "test GetItemT" << endl;
  cout << "Correct if output is 8" << endl;
  cout << lst.GetItemT() << endl;
  cout << endl;

  cout << "Test DeleteItemT and prints" << endl;
  cout << "Correct if output is 3, 2, 1, 0 on subsequent lines" << endl;
  lst.DeleteItemT();
  lst.Print();
  cout << endl;


  lst.PutItemT(2);
  lst.PutItemT(3);
  lst.PutItemT(3);
  lst.PutItemT(2);
  lst.Print();

    cout << "Test DeleteItem and prints" << endl;
  cout << "Correct if out is 2, length is 3, and  3, 1, 0 is printed on subsequent lines" << endl;
  cout << lst.DeleteItem(2) << ", Length: " << lst.GetLength() << endl;
  lst.Print();
  cout << endl;



  return 0;
}
