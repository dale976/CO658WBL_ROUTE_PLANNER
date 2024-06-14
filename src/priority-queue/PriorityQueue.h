#pragma once

#include <iostream>

template <class T>
class PriorityQueue {
private:
    int size;
    T **data;
    int count;

public:
    PriorityQueue(int size) : size(size), count(0) {
        data = new T*[size];
    }

    ~PriorityQueue() {
        delete[] data;
    }

    void Insert(T* item) {
        if (count == 0) {
            data[count++] = item;
        } else {
            int j = count - 1;
            while (j >= 0 && *item > *data[j]) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = item;
            count++;
        }
    }

    T* Remove() {
        if (count > 0) {
            return data[--count];
        } else {
            return nullptr; // or throw an exception for empty queue
        }
    }

    T* PeakMin() {
        if (count > 0) {
            return data[count - 1];
        } else {
            return nullptr; // or throw an exception for empty queue
        }
    }

    bool IsEmpty() {
        return count == 0;
    }

    bool IsFull() {
        return count == size;
    }

    int Size() {
        return count;
    }
};
