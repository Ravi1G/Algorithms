#ifndef STACK_H_
#define STACK_H_



template <class TYPE>
class Stack
{
    private:
        TYPE *S;
        int top;
        int size;

    public:
        Stack(int);
        ~Stack();
        void push(TYPE);
        TYPE pop();
        bool isEmpty();
};


template <class TYPE>
Stack<TYPE>::Stack(int sz)
{
    S = new TYPE[sz];
    size = sz;
    top = 0;
}


template <class TYPE>
Stack<TYPE>::~Stack()
{
    delete [] S;
}


template <class TYPE>
void Stack<TYPE>::push(TYPE val)
{
    if (top == 9)
        std::cout << "stack is full";
    else
        S[top++] = val;
}


template <class TYPE>
bool Stack<TYPE>::isEmpty()
{
    if (top == 0)
        return true;
    else
        return false;
}


template <class TYPE>
TYPE Stack<TYPE>::pop()
{
    if (isEmpty())
        return -1;
    else
        return S[--top];

}



#endif // STACK_H_
