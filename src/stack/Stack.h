#pragma once
template <class T>
class Stack
{
public:
    int maxSize;
    T **stackData;
    int top;
    Stack<T>(int maxSize)
    {
        this->maxSize = maxSize;
        stackData = new T *[maxSize];
        top = -1;
    }
    bool IsEmpty()
    {
        return (top == -1);
    }
    bool IsFull()
    {
        return (top == (maxSize - 1));
    }
    T *Peek()
    {
        return stackData[top];
    }
    T *Pop()
    {                                   
        T *valToReturn = stackData[top];
        top--;
        return valToReturn;
    }
    void Push(T *value)
    {
        top++;
        stackData[top] = value;
    }
    int Count()
    {
        return top + 1;
    }
};