#pragma once
#include <iostream>

using namespace std;

template <class T>
class LinkedList {
public:
	T* first;
	LinkedList(){
		first = 0;
	}
	void Display(){
		T *current = first;
		while (current != 0) {
			current->Display();
			current = current->next;
		}
	}
	T* Find(T* key){
	
		T* current = first;
		while (current != 0) {
			if (*current == *key)
				return current;
			else
				current = current->next;
		}

		return 0;
	}

	void Insert(T* newLink){ 
		newLink->next = first; 
		first = newLink;
	}

	bool IsEmpty() {
		return (first == 0);
	}
	T* Delete(T* key) {
		T* current = first;
		T* previous = first;
		while (*current != *key) {
			if (current->next == 0)
				return 0;
			else {
				previous = current;
				current = current->next;
			}
		}
		if (current == first)
			first = first->next;
		else
			previous->next = current->next;
		return current;
	}

	T* Pop() {
		if (IsEmpty() == true)
			return 0;
		T *temp = first;
		first = first->next;
		return temp;
	}


	void Append(T* newLink) {
		T* current = first;

		if (first == 0)
			first = newLink;
		else {
			while (current->next != 0)
				current = current->next;
			current->next = newLink;
		}
	}

	T* DeleteFirst() {
		T *temp = first;
		first = first->next;
		return temp;
	}
	T* Delete() {
		T *tempFirst = first;
		first = first->next;
		return tempFirst;
	}

};