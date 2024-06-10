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
	T* Find(T* key){ //modded
	
		T* current = first;
		while (current != 0) { //modded
			if (*current == *key) //if at end of list  //modded
				return current;
			else
				current = current->next;
		}

		return 0; // modded - ESSENTIAL!
	}

	void Insert(T* newLink){ 
		//prepend - new items become first...
		newLink->next = first; 
		first = newLink;
	}

	bool IsEmpty() {
		return (first == 0);
	}
	T* Delete(T* key) {
		T* current = first;
		T* previous = first;
		while (*current != *key) {  //modded
			if (current->next == 0)
				return 0;
			else {
				previous = current; //modded
				current = current->next;
			}
		}
		if (current == first)
			first = first->next;
		else
			previous->next = current->next;
		return current;
	}

	//W11 EX 1-3 
	T* Pop() {
		if (IsEmpty() == true)
			return 0;
		T *temp = first;
		first = first->next;
		return temp;
	}


	void Append(T* newLink) {
		//append - add to end of list
		T* current = first;

		if (first == 0) //if emoty, newlink becomes first
			first = newLink;
		else { //scan through the list until next pointer is null
			while (current->next != 0)
				current = current->next;
			current->next = newLink; //once found end of list - add new node
		}
	}

	//W3 EX7
	T* DeleteFirst() {
		T *temp = first;
		first = first->next; //assign old first's next to be new first
		return temp;
	}
	//W5 EX3
	T* Delete() { //delete top/first item
		T *tempFirst = first;
		first = first->next;
		return tempFirst;
	}

};