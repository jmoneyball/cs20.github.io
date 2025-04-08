#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include "Stack.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedStack : public Stack<T> {
    protected:
        // represents an element in the stack
        struct Node {
            T value;
            Node* next;

            Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the stack
        Node* head;

    private:
        // copy the values from the argument stack to `this`
        void copy(const LinkedStack<T>&);

    public:
        // default constructor
        LinkedStack();

        // copy constructor
        LinkedStack(const LinkedStack<T>&);

        // overloaded assignment operator
        LinkedStack<T>& operator=(const LinkedStack<T>&);

        // destructor
        virtual ~LinkedStack();

        // remove all elements in the stack
        virtual void clear() override;

        // return the current length of the stack
        virtual int getLength() const override;

        // determine if the stack currently empty
        virtual bool isEmpty() const override;

        // remove the top element from the stack
        virtual void pop() override;

        // add the argument to the top of the stack
        virtual void push(const T&) override;

        // return the element at the top of the stack
        virtual T top() const override;
};

template <typename T>
LinkedStack<T>::LinkedStack() {
	head = nullptr;
}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& copyObj) { // @suppress("Class members should be properly initialized")
    copy(copyObj);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template <typename T>
void LinkedStack<T>::clear() {
	while(head != nullptr) {
		Node* n = head;
		head = head->next;
		delete n;
	}
	this->length = 0;
}

template <typename T>
void LinkedStack<T>::copy(const LinkedStack<T>& copyObj) {
	this->length = copyObj.length;
	head = nullptr;

	if(this->length > 0) {
		head = copyObj.head;
		Node* curr = head;
		Node* copyCurr = copyObj.head->next;

		while(copyCurr != nullptr) {
			curr->next = copyCurr;
			curr = copyCurr;
			copyCurr = copyCurr->next;
		}
	}
}

template <typename T>
int LinkedStack<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedStack<T>::pop() {
    if(!isEmpty()) {
    	Node* prev = head;
    	if(this->length == 1)
    		head = nullptr;
    	else
			head = head->next;
    	delete prev;
    	this->length--;
    }
    else
    	cerr << "ERROR... the stack is empty" << endl;
}

template <typename T>
void LinkedStack<T>::push(const T& elem) {
	Node* n = new Node(elem);

	if(!isEmpty())
		n->next = head;

	head = n;
	this->length++;
}

template <typename T>
T LinkedStack<T>::top() const {
	if(!isEmpty())
		return head->value;
	else {
    	cerr << "ERROR... there is no top value to return" << endl;
		throw -1;
	}
}

#endif
