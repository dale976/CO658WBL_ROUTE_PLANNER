#pragma once
template <class T>
class PriorityQueue {
	int size;
	T **data;
	int count;
public:
	PriorityQueue(int size) {
		data = new T*[size];
		count = 0;
	}
	~PriorityQueue() {}
	void Insert(T*  item) {
		if (count == 0) {
			data[count++] = item;
		}
		else {
			int j;
			for (j = (count - 1); j >= 0; j--) {
				if (*item > *data[j]) {
					data[j + 1] = data[j];
				}
				else {
					break;
				}
			}
			data[j + 1] = item;
			count++;
		}
	}
	T*  Remove() {
		return data[--count];
	}
	T*  PeakMin() {
		return data[count - 1];
	}
	bool IsEmpty() {
		return count == 0;
	}
	bool IsFull() {
		return count == size;
	}
	int Size() {
		return size;
	}
	T* PeakFirst() {
		return data[0];
	}
};