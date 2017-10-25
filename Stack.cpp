/************************************************************
 CSCI 241 - Assignment 5 - Fall 2017

 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: Sumaiya Abdul
 Date Due: October 31, 2017

 Purpose:   
************************************************************/

#include "Stack.h"

/***************************************************************
 Stack Constructor 

 Use: 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
Stack::Stack()
{
    stackSize = 0;
    stackCapacity = 0;
    stackArray = nullptr;
}

/***************************************************************
 Stack Destructor 

 Use: 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
Stack::~Stack()
{
    delete[] stackArray;
}


/***************************************************************
 Copy Constructor

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
Stack::Stack(const Stack& other)
{
   stackCapacity = other.stackCapacity;
   stackSize = other.stackSize;

   if (stackCapacity == 0)
      stackArray = nullptr;
   else
      stackArray = new int[stackCapacity];

   for (size_t i = 0; i < stackSize; ++i)
      stackArray[i] = other.stackArray[i];
}


