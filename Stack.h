#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class Stack
{
    // Friend functions
    friend ostream& operator<<(ostream& lhs, const Stack& rhs); 

    // Data members
    private:
        int* stackArray;
        size_t stackCapacity;
        size_t stackSize;
    // Methods
    public:
        Stack();
        ~Stack();
        Stack(const Stack& other);
        Stack& operator=(const Stack& other);
        size_t size() const;
        size_t capacity() const;
        bool empty() const;
        int top() const;
        void clear();
        void push(int val);
        void pop();
        void reserve(size_t n);
        int operator[](size_t n) const;
        int& operator[](size_t n);
        bool operator==(const Stack& rhs) const;
}; 

#endif
