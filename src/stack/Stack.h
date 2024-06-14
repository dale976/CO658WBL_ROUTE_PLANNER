#pragma once
template <class T>
class Stack
{
private:
    int maxSize;
    T **stackData; // modded
    int top;

    void resize() {
        int newCapacity = maxSize * 2;
        T** newStackData = new T*[newCapacity];
        for (int i = 0; i < maxSize; i++) {
            newStackData[i] = stackData[i];
        }
        delete[] stackData;
        stackData = newStackData;
        maxSize = newCapacity;
    }
public:

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
       if (IsEmpty()) {
            return nullptr; // Or throw an exception
        }
        return stackData[top];
    }
    T *Pop()
    {                                    // modded
        if (IsEmpty()) {
            return nullptr; // Or throw an exception
        }
        return stackData[top--];
    }
    void Push(T *value)
    { // modded
        if (IsFull()) {
            resize();
        }
        stackData[++top] = value;
    }

    // W11
    int Count()
    {
        return top + 1;
    }
};