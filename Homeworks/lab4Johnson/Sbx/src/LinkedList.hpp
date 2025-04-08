#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList : public List<T> {
    protected:
        // represents an element in the linked list
        struct Node {
            T value;
            Node* next;

            Node(T v = T{}, Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the list
        Node* head;

    public:
        // default constructor
        LinkedList();

        // destructor
        virtual ~LinkedList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list
        virtual void clear() override;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // remove the element at the given position (argument)
        virtual void remove(int) override;
        
        /***********************************************************************
        *   No real implementations yet :(
        ***********************************************************************/

        // return the element at the given position (argument)
        virtual T getElement(int) const { return 0; }

        // return the current length of the list
        virtual int getLength() const { return 0; }

        // determine if the list currently empty
        virtual bool isEmpty() const { return false; }

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) { }

        friend ostream& operator<<(ostream& outStream, const LinkedList& myObj) {
            if (myObj.head == nullptr) {
                outStream << "List is empty, no elements to display.\n";
            }
            else {
                Node* curr = myObj.head;
                while (curr != nullptr) {
                    outStream << curr->value;
                    if (curr->next != nullptr) {
                        outStream << " --> ";
                    }
                    curr = curr->next;
                }
                outStream << endl;
            }

            return outStream;
        }
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) O(1) ?
*******************************************************************************/
template <typename T>
LinkedList<T>::LinkedList() {
   head = nullptr;
}

/*******************************************************************************
*   Analyzing the number of delete operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block executes:
*       T(n) = 3 + 1 = 4
*
*   Scenario #2, the else block executes:
*       T(n) = 3 + (3 + n)
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::append(const T& elem) {
    //creates temporary new node
	Node *n = new Node;
    n -> value = elem;
    n -> next = nullptr;

    if(head == nullptr) head = n; //if list is empty
    else { //if list is not empty
    	Node *c = new Node;
    	c = head;
    	while(c -> next != nullptr) c = c -> next;
    	c -> next = n;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 5 + 2n
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::clear() {
	//creates temporary current and next nodes
    Node *c = new Node;
    Node *n = new Node;
    c = head;
    n = nullptr;

    //deletes list starting with head and iterating through
    while (c != nullptr) {
	   n = c -> next;
	   delete c;
	   c = n;
	}
    //resets head to nullptr
    head = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list and length > 1.
*
*   T(n) = 7 + n + 2 + ....
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    //creates temporary new nodes
	Node *n = new Node;
    n -> value = elem;
    n -> next = nullptr;
    Node *c = new Node;
    Node *p = new Node;
    c = head;

    //counts elements in the list
    int count = 0;
    while (c -> next != nullptr) {
    	count++;
    	c = c -> next;
    }

    //determines if position is within bounds
    if(position > count || position < 0) {
    	cout << "ERROR: position is out of bounds" << endl;
    	return;
    }

    //initializes nodes for current and previous
    c = head;
    p = nullptr;

    if(position == 0) { //if the node is being inserted at the beginning
    	n -> next = head;
    	head = n;
    }
    else if(position > 0) { //if the node is NOT being inserted at the beginning
    	for(int i = 0; i < position-1; i++) {
    		p = c;
    		c = c -> next;
    	}
    	p -> next = n;
    	n -> next = c;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list and length > 1.
*
*   T(n) = n + some constant
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::remove(int position) {
	//creates temporary new nodes
    Node *c = new Node;
    Node *p = new Node;
    c = head;

    //counts elements in the list
    int count = 0;
    while (c -> next != nullptr) {
    	count++;
    	c = c -> next;
    }

    //determines if position is within bounds
    if(position > count || position < 0){
    	cout << "ERROR: position is out of bounds" << endl;
    	return;
    }

    //initializes nodes for current and previous
    c = head;
    p = nullptr;

    //moves through list to find node that needs to be deleted
	for(int i = 0; i < position; i++) {
		p = c;
		c = c -> next;
	}

	//deletes node
	p -> next = c -> next;
	delete c;
}

#endif
