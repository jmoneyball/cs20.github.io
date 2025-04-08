#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedQueue : public Queue<T> {
    protected:
        // represents an element in the queue
        struct Node {
            T value;
            Node* next;

            Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the queue
        Node* head;

        // a pointer to the back of the queue
        Node* last;

    private:
        // copy the values from the argument queue to `this`
        void copy(const LinkedQueue<T>&);

    public:
        // default constructor
        LinkedQueue();

        // copy constructor
        LinkedQueue(const LinkedQueue<T>&);

        // overloaded assignment operator
        LinkedQueue<T>& operator=(const LinkedQueue<T>&);

        // destructor
        virtual ~LinkedQueue();

        // return the element at the back of the queue
        virtual T back() const override;

        // remove all elements in the queue
        virtual void clear() override;

        // remove the front element from the queue
        virtual void dequeue() override;

        // add the argument to the back of the queue
        virtual void enqueue(const T&) override;

        // return the element at the front of the queue
        virtual T front() const override;

        // return the current length of the queue
        virtual int getLength() const override;

        // determine if the queue currently empty
        virtual bool isEmpty() const override;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
LinkedQueue<T>::LinkedQueue() {
	head = nullptr;
	last = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of accesses to `last`.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
	if(!isEmpty())
		return this->last->value;
	return 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(n)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
	Node* curr = head;

	while(curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}

	this->length = 0;
	head = last = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(n)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
	this->length = copyObj.length;
	head = nullptr;

	if(this->length > 0) {
		head = copyObj.head;
		Node* myCurr = head;
		Node* copyCurr = copyObj.head -> next;

		while(copyCurr != nullptr) {
			myCurr->next = copyCurr;
			myCurr = copyCurr;
			copyCurr = copyCurr->next;
		}
		last = myCurr;
	}
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::dequeue() {
	// <TODO>
	if(head == nullptr)
		cout << "UNDERFLOW... there are no nodes to dequeue" << endl;
	else if(head->next == nullptr) {
		delete head;
		head = last = nullptr;
		this->length--;
	}
	else {
		Node *n = head->next;
		delete head;
		head = n;
		this->length--;
	}
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(n)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
	if(head == nullptr)
		head = last = new Node(elem);

	else {
		Node *curr = head;
		while(curr->next != nullptr)
			curr = curr->next;
		curr->next = last = new Node(elem);
	}
	this->length++;
}

/*******************************************************************************
*   Analyzing the number of accesses to `head`.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
	if(!isEmpty())
		return this->head->value;
	return 0;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       O(1)
*******************************************************************************/
template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}

#endif
