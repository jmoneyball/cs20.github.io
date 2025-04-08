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

    private:
        // copy the values from the argument linked list to `this`
        void copy(const LinkedList<T>&);

        // recursive auxiliary functions
        void appendRec(Node*, Node*);										//x
        void clearRec(Node*);												//x
        void copyRec(const LinkedList<T>&, Node*, Node*);					//x
        T getElementRec(int, Node*, int = 0) const;							//x
        void insertRec(int position, Node*, Node*, Node*, int i = 0);		//x
        void removeRec(int position, Node*, Node*, int i = 0);				//x
        void printRec(ostream&, Node*) const;								//x
        void replaceRec(int, Node*, const T& elem, int i = 0);				//x

    public:
        // default constructor
        LinkedList();

        // copy constructor
        LinkedList(const LinkedList<T>&);

        // overloaded assignment operator
        LinkedList<T>& operator=(const LinkedList<T>&);

        // destructor
        virtual ~LinkedList();

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

        friend ostream& operator<<(ostream& outStream, const LinkedList& myObj) {
            if (myObj.isEmpty()) {
                outStream << "List is empty, no elements to display.\n";
            }
            else {
                myObj.printRec(outStream, myObj.head);
            }

            return outStream;
        }
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    appendRec(new Node(elem), head);
    this->length++;
}

template <typename T>
void LinkedList<T>::appendRec(Node* n, Node* curr) {
    // base case 1: list is empty
    if (curr == nullptr) {
        head = n;
    }

    // base case 2: `curr` is the last node in the list
    else if (curr->next == nullptr) {
        curr->next = n;
    }

    // recursive case
    else {
        appendRec(n, curr->next);
    }
}

template <typename T>
void LinkedList<T>::clear() {
	clearRec(head);
	this->length = 0;
}

template <typename T>
void LinkedList<T>::clearRec(Node* prev) {
	//base case & recursive case
	if(head != nullptr) {
		head = head -> next;
		delete prev;
		clearRec(head);
	}
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
	this -> length = copyObj.length;
	head = nullptr;
	//if the length of the list isn't zero
	if (this -> length > 0) {
		head = new Node(copyObj.head -> value);
		copyRec(copyObj, head, copyObj.head -> next);
	}
}

template <typename T>
void LinkedList<T>::copyRec(const LinkedList<T>& copyObj, Node* myCurr, Node* copyCurr) {
	//base case & recursive case
	if(copyCurr != nullptr) {
		Node* n = new Node(copyCurr->value);
		myCurr->next = n;
		myCurr = n;
		copyRec(copyObj, myCurr, copyCurr -> next);
	}
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
        throw -1;
    }
    
    return getElementRec(position, head);
}

template <typename T>
T LinkedList<T>::getElementRec(int position, Node* curr, int i) const {
    // base case: position has been reached
    if (i == position) {
        return curr->value;
    }
    // recursive case
    return getElementRec(position, curr->next, i + 1);
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
	//checks bounds
	if (position < 0 || position >= this->length) {
		cout << "ERROR: position out of bounds\n";
	}
	//inserts if position is within bounds
	else {
		insertRec(position, new Node(elem), head, nullptr);
		this->length++;
	}
}

template <typename T>
void LinkedList<T>::insertRec(int position, Node* n, Node* curr, Node* prev, int i) {
	//base case 1: if insert position is the head
	if(position == 0) {
		n -> next = head;
		head = n;
	}
	//base case 2: if insert position is reached && position != zero
	else if(position == i && position != 0) {
		prev -> next = n;
		n -> next = curr;
	}
	//recursive case
	else insertRec(position, n, curr -> next, curr, i + 1);
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::printRec(ostream& outStream, Node* curr) const {
    // base case: list is empty
    if (curr == nullptr) {
        outStream << endl;
    }

    // recursive case
    else {
        outStream << curr->value;
        if (curr->next != nullptr) {
            outStream << " --> ";
        }
        printRec(outStream, curr->next);
    }
}

template <typename T>
void LinkedList<T>::remove(int position) {
	//check bounds
	if (position < 0 || position >= this->length) {
		cout << "ERROR: position out of bounds\n";
	}
	//remove if within bounds
	else {
		removeRec(position, head, nullptr);
		this->length--;
	}
}

template <typename T>
void LinkedList<T>::removeRec(int position, Node* curr, Node* prev, int i) {
	//base case 1: delete only node
	if(head -> next == nullptr) {
		delete head;
		head = nullptr;
	}
	//base case 2: delete first node
	else if (position == 0) {
		prev = head;
		head = head -> next;
		delete prev;
	}
	//base case 3: delete node at position
	else if (position == i) {
		prev -> next = curr -> next;
		delete curr;
	}
	//recursive case
	else removeRec(position, curr -> next, curr, i + 1);
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
	//checks bounds
	if (position < 0 || position >= this->length) {
		cout << "ERROR: position out of bounds\n";
	}
	//replaces if within bounds
	else replaceRec(position, head, elem);
}

template <typename T>
void LinkedList<T>::replaceRec(int position, Node* curr, const T& elem, int i) {
	//base case
	if(position == i) curr -> value = elem;
	//recursive case
	else replaceRec(position, curr -> next, elem, i + 1);
}

#endif
