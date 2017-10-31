/************************************************************
 CSCI 241 - Assignment 5 - Fall 2017

 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: Sumaiya Abdul
 Date Due: October 31, 2017

 Purpose: This assignment is an exercise in implementing the
 stack ADT using a dynamically-allocated array, as well as 
 techniques for managing dynamically-allocated storage in C++.
                _________________
               /                /|
              /                / |
             /________________/ /|
          ###|      ____      |//|
         #   |     /   /|     |/.|
        #  __|___ /   /.|     |  |_______________
       #  /      /   //||     |  /              /|                  ___
      #  /      /___// ||     | /              / |                 / \ \
      # /______/!   || ||_____|/              /  |                /   \ \
      #| . . .  !   || ||                    /  _________________/     \ \
      #|  . .   !   || //      ________     /  /\________________  {   /  }
      /|   .    !   ||//~~~~~~/   0000/    /  / / ______________  {   /  /
     / |        !   |'/      /9  0000/    /  / / /             / {   /  /
    / #\________!___|/      /9  0000/    /  / / /_____________/___  /  /
   / #     /_____\/        /9  0000/    /  / / /_  /\_____________\/  /
  / #                      ``^^^^^^    /   \ \ . ./ / ____________   /
 +=#==================================/     \ \ ./ / /.  .  .  \ /  /
 |#                                   |      \ \/ / /___________/  /
 #                                    |_______\__/________________/
 |                                    |               |  |  / /       
 |                                    |               |  | / /       
 |                                    |       ________|  |/ /________       
 |                                    |      /_______/    \_________/\
 |                                    |     /        /  /           \ )       
 |                                    |    /OO^^^^^^/  / /^^^^^^^^^OO\)       
 |                                    |            /  / /        
 |                                    |           /  / /
 |                                    |          /___\/
 |                                    |           oo
 |____________________________________|

************************************************************/

#include "Stack.h"

/***************************************************************
 Stack Constructor 

 Use: Instantiates Stack object and sets it's data attributes. 

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
 Copy Constructor

 Use: Allows a Stack object to be copied. 

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

 Use: Makes it possible to delete a Stack object to save memory. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
Stack::~Stack()
{
    delete[] stackArray;
}


/***************************************************************
 Assignment Operator 

 Use: Sets another Stack object to "this" stack object's values.  

 Parameters: Reference to a const stack object. 

 Returns: Pointer to this instance of the stack object.
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

 Use: Makes it possible to output Stack objects using cout.

 Parameters: Reference to a const stack object. 

 Returns: lhs a reference to an ostream object.
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

 Use: Sets the Stack objects size to zero. "Clears" the object. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
void Stack::clear()
{
    stackSize = 0;
}


/***************************************************************
 Size method 

 Use: Getter method basically.  Only returns stacksize. 

 Parameters: No parameters. 

 Returns: The Stack objects size "stackSize" attribute.
***************************************************************/
size_t Stack::size() const
{
    return stackSize;
}


/***************************************************************
 Capacity method 

 Use: Getter method basically. Only returns objects capacity. 

 Parameters: No parameters. 

 Returns: The Stack objects capacity "stackCapacity" attribute.
***************************************************************/
size_t Stack::capacity() const
{
    return stackCapacity;
}


/***************************************************************
 Empty method

 Use: Just tells the user if the stack object has anything in
 it's stackSize data attribute. Hence the name. 

 Parameters: No parameters. 

 Returns: A bool.
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

 Use: Getter method that returns the stack objects top "item". 

 Parameters: No parameters. 

 Returns: The top item in the stackArray data type.
***************************************************************/
int Stack::top() const
{
    return stackArray[stackSize -1]; 
}


/***************************************************************
 Push method 

 Use: Loads a value into the stack.  Easy way to think of this
 is the plates on the buffet, I'm pushing a new value into the 
 "stack".  

 Parameters: An integer value, appropriately named "val". Neat. 

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

 Use: Pop the plate off the top of the stack.   

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
void Stack::pop()
{
    --stackSize;
}


/***************************************************************
 Reserve Method 

 Use: Increases the stackArray when necessary.  Grows when needed.

 Parameters: "n" of size_t data type.  Can't be a negative num. 

 Returns: No return.
***************************************************************/
void Stack::reserve(size_t n)
{
    if (n < stackSize || n == stackCapacity)
        return;
    
    stackCapacity = n;

    int* tempArray = new int[stackCapacity];
    
    for (size_t i = 0; i < stackSize; ++i)
    {
        tempArray[i] = stackArray[i];
    }

    delete[] stackArray;

    stackArray = tempArray;
}


/***************************************************************
 Subscript operator overloader 

 Use: This method returns the element of the stack array at 
 subscript n.

 Parameters: size_t "n" so we know what subscript the user wants. 

 Returns: The item of the stackArray that the user asked for.
 Also known as "n".
***************************************************************/
int Stack::operator[](size_t n) const
{
    return stackArray[n];
}


/***************************************************************
 Non const Subscript operator overloader 

 Use: This method should return the element of the stack array 
 at subscript n 

 Parameters: Reference to a const stack object. 

 Returns: The item of the stackArray that the user asked for.
 Also known as "n".
***************************************************************/
int& Stack::operator[](size_t n)
{
    return stackArray[n];
}


/***************************************************************
 Comparison operator overloading 

 Use: Make it possible to compare two stack objects. 

 Parameters: A constant reference to a Stack object.

 Returns: Either true or false. #boollife.
***************************************************************/
bool Stack::operator==(const Stack& rhs) const
{
    if(this->stackSize==rhs.stackSize)
    {
         for (size_t i = 0; i < stackSize; ++i)
         {
             if (this->stackArray[i] != rhs.stackArray[i])
             {
                 return false;
             }
         }
     }
     else
     {
         return false;
     }

     return true;
}
