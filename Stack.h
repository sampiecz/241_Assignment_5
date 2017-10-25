#ifndef STACK_H
#define STACK_H
    
Class Stack
{
    // Friend functions
    friend ostream& operator<<(ostream& lhs, const Stack& rhs) 

    // Data members
    private:
        int* stackArrayPointer;
        size_t stackCapacity;
        size_t stackSize;
        int stackTopSubscript = stackSize -1;
    // Methods
    public:
        Stack::Stack();
        Stack::~Stack();
        Stack::Stack(const Stack& other);
        Stack& Stack::operator=(const Stack& other);
        ostream& operator<<(ostream& lhs, const Stack& rhs);
        size_t Stack::size() const;
        size_t Stack::capacity() const;
        bool Stack::empty() const;
        int Stack::top() const;
        void Stack::push(int val);
        void Stack::pop();
        void Stack::reserve(size_t n);
        int Stack::operator[](size_t n) const;
        int& Stack::operator[](size_t n);
        bool Stack::operator==(const Stack& rhs) const;
}; 

#endif
