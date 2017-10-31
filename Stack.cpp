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
    stackTopSubscript = stackSize -1;
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
   {
      stackArray = nullptr;
   }
   else
   {
      stackArray = new int[stackCapacity];
   }

   for (size_t i = 0; i < stackSize; ++i)
   {
      stackArray[i] = other.stackArray[i];
   }
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
 Assignment Operator 

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        delete[] stackArray;
        stackCapacity = other.stackCapacity;
        stackSize = other.stackSize;
                
        if (stackCapacity == 0)
        {
            stackArray = nullptr;
        }
        else
        {
            stackArray = new int[stackCapacity];
        }

        for (size_t i = 0; i < stackSize; ++i)
        {
            stackArray[i] = other.stackArray[i];
        }
    }
    
    return *this;

}


/***************************************************************
 Output Operator 

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
ostream& operator<<(ostream& lhs, const Stack& rhs)
{

    for (size_t i = 0; i < rhs.stackSize; i++)
    { 
        lhs << rhs.stackArray[i] << " "; 
    }

    return lhs;

}


/***************************************************************
 Clear method 

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
void Stack::clear()
{
    stackSize = 0;
}


/***************************************************************
 Size method 

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
size_t Stack::size() const
{
    return stackSize;
}


/***************************************************************
 Capacity method 

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
size_t Stack::capacity() const
{
    return stackCapacity;
}


/***************************************************************
 Empty method

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
bool Stack::empty() const
{
    if (stackSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/***************************************************************
 Top method 

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
int Stack::top() const
{
    return stackSize -1;
}


/***************************************************************
 Push method 

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
void Stack::push(int val)
{

    if (stackSize == stackCapacity)
    {
        if (stackCapacity == 0)
            reserve(1);
        else
           reserve(stackCapacity * 2);
    }

    stackArray[stackSize] = val;
    ++stackSize;

}

/***************************************************************
 Pop method

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
void Stack::pop()
{
    stackSize -= 1;
}


/***************************************************************
 Copy Constructor

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
void Stack::reserve(size_t n)
{
    if (n < stackSize || n == stackCapacity)
        return;
    
    int* tempArray = new int[n];
    
    for (size_t i = 0; i < stackSize; ++i)
    {
        tempArray[i] = stackArray[i];
    }

    stackCapacity = n;
    delete[] stackArray;
    stackArray = tempArray;
}


/***************************************************************
 Copy Constructor

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
int Stack::operator[](size_t n) const
{
    return stackArray[n];
}


/***************************************************************
 Copy Constructor

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
int& Stack::operator[](size_t n)
{
    return stackArray[n];
}


/***************************************************************
 Copy Constructor

 Use: 

 Parameters: Reference to a const stack object. 

 Returns: No return.
***************************************************************/
bool Stack::operator==(const Stack& rhs) const
{
    if (this->stackSize == rhs.stackSize)
    {
        for (size_t i = 0; i < stackSize; i++)
        {
            if (this->stackArray[i] != rhs.stackArray[i])
            {
                return false;      
            }
            else
            {
                continue;
            }
        } 
    }
    else
    {
        return false;
    }

    return true;
}
