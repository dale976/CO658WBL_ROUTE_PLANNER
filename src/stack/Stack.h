#pragma once
template <class T>
class Stack
{
public:
    int maxSize;
    T **stackData; // modded
    int top;
    Stack<T>(int maxSize)
    {
        this->maxSize = maxSize;
        stackData = new T *[maxSize]; // modded
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
    { // modded
        return stackData[top];
    }
    T *Pop()
    {                                    // modded
        T *valToReturn = stackData[top]; // modded
        // stackData[top] = 0; //if want to delete element
        top--;
        return valToReturn;
    }
    void Push(T *value)
    { // modded
        top++;
        stackData[top] = value;
    }

    // W11
    int Count()
    {
        return top + 1;
    }
};