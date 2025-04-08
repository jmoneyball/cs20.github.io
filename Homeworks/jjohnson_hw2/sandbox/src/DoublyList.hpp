#ifndef DOUBLY_LIST_HPP
#define DOUBLY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class DoublyList : public List<T> {
    protected:
        // represents an element in the doubly linked list
        struct Node {
            T value;
            Node* next;
            Node* prev;

            Node(T v = T{}, Node* n = nullptr, Node* p = nullptr)
            : value(v), next(n), prev(p) { }
        };

        // a pointer to the front of the list
        Node* head;

        // a pointer to the end of the list
        Node* last;

    private:
        // copy the values from the argument doubly linked list to `this`
        void copy(const DoublyList<T>&);

    public:
        // default constructor
        DoublyList();

        // copy constructor
        DoublyList(const DoublyList<T>&);

        // overloaded assignment operator
        DoublyList<T>& operator=(const DoublyList<T>&);

        // destructor
        virtual ~DoublyList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        /***********************************************************************
        *   Analyzing the number of output operations.
        *   Input size n is the length of the list.
        *
        *   Asymptotic analysis:
        *       T(n) = O(n)
        ***********************************************************************/
        friend ostream& operator<<(ostream& outStream, const DoublyList& myObj) {
            if (myObj.isEmpty()) {
                outStream << "List is empty, no elements to display.\n";
            }
            else {
                Node* curr = myObj.head;
                while (curr != nullptr) {
                    outStream << curr->value;
                    if (curr->next != nullptr) {
                        outStream << " <--> ";
                    }
                    curr = curr->next;
                }
                outStream << endl;
            }

            return outStream;
        }
};

//maintains last - 1/3
/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
DoublyList<T>::DoublyList() {
    head = nullptr;
    last = nullptr;
    this -> length = 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

/*******************************************************************************
*   Analyzing the number of delete operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
}

//uses last - 1/5
/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void DoublyList<T>::append(const T& elem) {
	Node* n = new Node(elem);

	if(head == nullptr) {
		head = last = n;
	}
	else {
		last -> next = n;
		n -> prev = last;
		last = n;
	}

	this -> length++;
}

//maintains last - 2/3
/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::clear() {
	Node* p = nullptr;

	while(head != nullptr) {
		p = head;
		head = head -> next;
		delete p;
	}
	head = last = nullptr;
	this -> length = 0;

}

//maintains last - 3/3
/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    this->length = copyObj.length;
    head = last = nullptr;

    if (this->length > 0) {
        head = new Node(copyObj.head->value);
        Node* myCurr = head;
        Node* copyCurr = copyObj.head->next;

        while (copyCurr != nullptr) {
            Node* n = new Node(copyCurr->value);
            n -> prev = myCurr;
            myCurr->next = n;
            myCurr = n;
            copyCurr = copyCurr->next;
        }
        last = myCurr;
    }
}

//uses last 2/5
/*******************************************************************************
*   Analyzing the number of links accessed.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
T DoublyList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }

    Node* curr = head;
    int half = this -> length / 2;

    if(position < half)
        for (int i = 0; i < position; i++)
            curr = curr->next;
    else if (position >= half) {
  		curr = last;
		for(int i = 0; i < (this -> length - position); i++)
			curr = curr -> prev;
    }

    return curr->value;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}

//uses last 3/5
/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
	if (position < 0 || position >= this->length) {
		cout << "ERROR: position out of bounds\n";
	}
	else {
		Node* n = new Node(elem);
		Node* curr = head;
		Node* p = nullptr;
		float half = (this->length)/2;

		if (position != 0) {
			if(position < half) {
				for (int i = 0; i < position; i++) {
					p = curr;
					curr = curr->next;
				}
			}
			else if(position >= half) {
				curr = last;
				p = last -> prev;
				for(int i = 0; i < (this -> length - position); i++) {
					curr = curr -> prev;
					p = curr -> prev;
				}
			}
			p->next = n;
			n->prev = p;
		}
		else if (position == 0) {
			head = n;
		}
		n -> next = curr;
		curr -> prev = n;
		this -> length++;
    }
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length == 0;
}

//uses last 4/5
/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::remove(int position) {

	//checks to make sure that position is within bounds
	if (position < 0 || position >= this->length) {
		cout << "ERROR: position out of bounds\n";
	}
	else {
		Node* curr = head;
		int half = this -> length / 2;

		if(position < half) {
			if(position == 0){ //if removing head
				if(curr -> next == nullptr) { //if head is only node
					head = last = nullptr;
				}
				else { //if head is not only node
					head = head -> next;
					head -> prev = nullptr;
				}
			}
			else { //if removing between head and half
				for (int i = 0; i < position; i++) {
					curr = curr -> next;
				}
				curr -> prev -> next = curr -> next;
				curr -> next -> prev = curr -> prev;
			}
		}
		else if(position >= half) {
			curr = last;

			if((position + 1) == this -> length) { //if removing last
				last = last -> prev;
				last -> next = nullptr;
			}
			else { //if removing between half and last
				for(int i = 0; i < (this -> length - position); i++)
					curr = curr -> prev;
				curr -> prev -> next = curr -> next;
				curr -> next -> prev = curr -> prev;
			}
		}
		delete curr;
		this -> length--;
	}
}

//uses last 5/5
/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
	//checks to make sure that position is within bounds
	if (position < 0 || position >= this->length) {
		cout << "ERROR: position out of bounds\n";
	}
	else {
		//declarations
		Node* curr = head; //current pointer set to head of list
		int half = this -> length / 2; //halfway point in list

		if(position < half) { //if replace position is within HALF of list
			//traverse to replace point
			for (int i = 0; i < position; i++) curr = curr -> next;
			//replace node
			curr -> value = elem;
		}
		else if(position >= half) { //if replace point is BETWEEN HALF AND LAST
			curr = last;
			//traverse list BACKWARDS to reach remove point quicker
			for(int i = 0; i < (this -> length - position); i++) curr = curr -> prev;
			//insert node and update pointers
			curr -> value = elem;
		}
	}
}
#endif
