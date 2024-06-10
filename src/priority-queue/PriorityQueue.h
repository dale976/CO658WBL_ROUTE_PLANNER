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
		// Queue is empty
		if (count == 0) {
			data[count++] = item;
		}
		else {
			int j;
			// Start at the end work backwards 
			for (j = (count - 1); j >= 0; j--) {
				// If the new item is larger than current
				if (*item > *data[j]) {
					// Shift the current up
					data[j + 1] = data[j];
				}
				else {
					// Finished shifting
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
};