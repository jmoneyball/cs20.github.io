#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP

#include "BinaryTree.hpp"
#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
class MaxHeap : public BinaryTree<T> {
    private:
        // copy the values from the argument heap to `this`
        void copy(const MaxHeap<T>&);

        // return the position of the "tail" element for the given level
        // by "tail", this means the last element in that level
        int getTailPos(int) const;

        // determine if the given index (parameter 1) is the "tail" element for
        // the given level (parameter 2)
        bool isTailPos(int, int) const;

        // sift down the element at the given position
        void siftDown(int);

        // sift up the element at the given position
        void siftUp(int);

        // swap the elements at the given positions
        void swap(int, int);

    protected:
        // the underlying (dynamic) array
        T* buffer;

        // the number of elements in the heap
        int n;

        // the max size of the heap
        int maxSize;

    public:
        // default constructor
        MaxHeap(int = 100);

        // copy constructor
        MaxHeap(const MaxHeap<T>&);

        // overloaded assignment operator
        MaxHeap<T>& operator=(const MaxHeap<T>&);

        // destructor
        virtual ~MaxHeap();

        // return the index of the target value (if found)
        int find(const T&) const;

        // return the left subtree (NOT ALLOWED)
        virtual BinaryTree<T>* getLeft() const override;

        // return the left child index
        int getLeft(int) const;

        // return the maximum size of the heap
        int getMaxSize() const;

        // return the parent index
        int getParent(int) const;

        // return the right subtree (NOT ALLOWED)
        virtual BinaryTree<T>* getRight() const override;

        // return the right child index
        int getRight(int) const;

        // return the value of the root (NOT ALLOWED)
        virtual T getValue() const override;

        // return the value at the given position
        T getValue(int) const;

        // sort the given collection of values using heapsort
        // and then print the sorted data
        void heapsort(const T[], const int);

        // find the height of the heap
        virtual int height() const override;

        // insert the given value into the heap
        void insert(const T&);

        // insert an entire collection of values into the heap
        // this replaces the buffer contents
        void insert(const T[], const int);

        // determine if the MaxHeap is a leaf node (NOT ALLOWED)
        virtual bool isLeaf() const override;

        // determine if the node at the given index is a leaf node
        bool isLeaf(int) const;

        // find the number of leaves in the heap
        virtual int numLeaves() const override;

        // find the number of nodes in the heap
        virtual int numNodes() const override;

        // print the contents of the heap in buffer order
        void printBuffer() const;

        // print the contents of the heap as a tree
        void printTree(int = 0, int = 0) const;

        // remove the node at the given position
        void remove(int);

        // remove the root of the heap
        void removeRoot();

        // update the left subtree (NOT ALLOWED)
        virtual void setLeft(BinaryTree<T>*) override;

        // update the right subtree (NOT ALLOWED)
        virtual void setRight(BinaryTree<T>*) override;

        // update the value of the root (NOT ALLOWED)
        virtual void setValue(const T&) override;
};

template <typename T>
int MaxHeap<T>::find(const T& target) const { // @suppress("No return")
	try {
		for(int i = 0; i < numNodes(); i++)
		if(buffer[i] == target)
			return i;
		throw -1;
	}
	catch (...) {
		cout << "ERROR: the target value does not exist\n";
	}
}

template <typename T>
void MaxHeap<T>::heapsort(const T ARR[], const int ARR_SIZE) {
	this->insert(ARR, ARR_SIZE);
	while(n > 1) removeRoot();
	cout << "Sorted values:\n";
	for(int i = 0; i < ARR_SIZE; i++)
		cout << buffer[i] << " ";
	cout << endl;
}

template <typename T>
void MaxHeap<T>::insert(const T& k) {
	if(maxSize == numNodes()) {
		cout << "ERROR: heap is full\n";
		return;
	}
	int i = n++;
	buffer[i] = k;
	siftUp(i);
}

template <typename T>
void MaxHeap<T>::insert(const T NEW_BUFFER[], const int NEW_MAX_SIZE) {
	if(n < NEW_MAX_SIZE) {
		delete[] buffer;
		buffer = new T[NEW_MAX_SIZE];
	}
	maxSize = NEW_MAX_SIZE;
	n = 0;
	for(int i = 0; i < maxSize; i++) {
		buffer[i] = NEW_BUFFER[i];
		n++;
	}
	int i = abs(n/2) - 1;
	while(i >= 0) siftDown(i--);
}

template <typename T>
void MaxHeap<T>::remove(int r) {
	if(r >= 0 && r < n && n != 1) {
		swap(r, --n);
		siftUp(r);
		siftDown(r);
	}
	else if(n == 1) cout << "ERROR: there is only one element in the heap\n";
	else cout << "ERROR: there is no element to remove with that index\n";
}

template <typename T>
void MaxHeap<T>::removeRoot() {
	if(n > 1) {
		swap(0, --n);
		siftDown(0);
	}
	else cout << "ERROR: there is only one element in the heap\n";
}

template <typename T>
void MaxHeap<T>::siftDown(int r) {
	while(!isLeaf(r)) {
		int left = getLeft(r);
		try {
			int right = getRight(r);
			if(buffer[right] > buffer[left] && buffer[right] > buffer[r])
				swap(r, right);
			else if(buffer[left] > buffer[r])
				swap(r, left);
		}
		catch (...) {
			if(buffer[left] > buffer[r])
				swap(r, left);
		}
		r++;
	}
}

template <typename T>
void MaxHeap<T>::siftUp(int r) {
	while(r != 0 && buffer[getParent(r)] < buffer[r]) {
		swap(r, getParent(r));
		r = getParent(r);
	}
}

/*******************************************************************************
********************************************************************************
********************************************************************************
********************CODE BELOW DOES NOT NEED TO BE MODIFIED!********************
********************************************************************************
********************************************************************************
*******************************************************************************/

template <typename T>
MaxHeap<T>::MaxHeap(int i) {
    maxSize = i;
    n = 0;
    buffer = new T[maxSize];
}

template <typename T>
MaxHeap<T>::MaxHeap(const MaxHeap<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
MaxHeap<T>& MaxHeap<T>::operator=(const MaxHeap<T>& rightObj) {
    if (this != &rightObj) {
        delete[] buffer;
        copy(rightObj);
    }
    return *this;
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    delete[] buffer;
}

template <typename T>
void MaxHeap<T>::copy(const MaxHeap<T>& copyObj) {
    maxSize = copyObj.maxSize;
    n = copyObj.n;
    buffer = new T[maxSize];

    for (int i = 0; i < n; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
BinaryTree<T>* MaxHeap<T>::getLeft() const {
    cout << "This version of getLeft() is not allowed for a heap\n";
    throw -1;
}

template <typename T>
int MaxHeap<T>::getLeft(int r) const {
    if (r < 0 || r > n / 2 - 1) {
        //cout << "ERROR: no left child for this node position\n";
        throw -1;
    }

    return 2 * r + 1;
}

template <typename T>
int MaxHeap<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
int MaxHeap<T>::getParent(int r) const {
    if (r <= 0) {
        //cout << "ERROR: no parent for this node position\n";
        throw -1;
    }

    return (r - 1) / 2;
}

template <typename T>
BinaryTree<T>* MaxHeap<T>::getRight() const {
    cout << "This version of getRight() is not allowed for a heap\n";
    throw -1;
}

template <typename T>
int MaxHeap<T>::getRight(int r) const {
    if (r < 0 || r > ceil(n / 2.0) - 2) {
        //cout << "ERROR: no right child for this node position\n";
        throw -1;
    }

    return 2 * r + 2;
}

template <typename T>
int MaxHeap<T>::getTailPos(int level) const {
    if (level == 0) {
        return 0;
    }
    return pow(2, level) + getTailPos(level - 1);
}

template <typename T>
T MaxHeap<T>::getValue() const {
    cout << "This version of getValue() is not allowed for a heap\n";
    throw -1;
}

template <typename T>
T MaxHeap<T>::getValue(int r) const {
    if (r < 0 || r >= n) {
        cout << "Invalid index position to getValue()\n";
        throw -1;
    }

    return buffer[r];
}

template <typename T>
int MaxHeap<T>::height() const {
    return ceil(log2(n + 1));
}

template <typename T>
bool MaxHeap<T>::isLeaf() const {
    cout << "This version of isLeaf() is not allowed for a heap\n";
    throw -1;
}

template <typename T>
bool MaxHeap<T>::isLeaf(int r) const {
    return r > n / 2 - 1 && r < n;
}

template <typename T>
bool MaxHeap<T>::isTailPos(int r, int level) const {
    return r == getTailPos(level);
}

template <typename T>
int MaxHeap<T>::numLeaves() const {
    return ceil(n / 2.0);
}

template <typename T>
int MaxHeap<T>::numNodes() const {
    return n;
}

template <typename T>
void MaxHeap<T>::printBuffer() const {
    cout << "Buffer contents in heap:\n";
    for (int i = 0; i < n; i++) {
        cout << buffer[i] << ' ';
    }
    cout << endl;
}

template <typename T>
void MaxHeap<T>::printTree(int r, int level) const {
    if (level == this->height()) {
        cout << endl;
        return;
    }

    int rc = 0;
    for (int cond = 0; rc < pow(2, level); rc++) {
        cond = (rc == 0) ?
               pow(2, this->height() - level - 1) - 1 :
               pow(2, this->height() - level);
        
        for (int i = 0; i < cond; i++) {
            cout << "   ";
        }

        if (r + rc < n) {
            cout << buffer[r + rc] << (isTailPos(r + rc, level) ? '\n' : ' ');
        }
    }

    printTree(r + rc, level + 1);
}

template <typename T>
void MaxHeap<T>::setLeft(BinaryTree<T>* l) {
    cout << "Cannot call setLeft() on a heap\n";
}

template <typename T>
void MaxHeap<T>::setRight(BinaryTree<T>* r) {
    cout << "Cannot call setRight() on a heap\n";
}

template <typename T>
void MaxHeap<T>::setValue(const T& v) {
    cout << "Cannot call setValue() on a heap\n";
}

template <typename T>
void MaxHeap<T>::swap(int i, int j) {
    T t = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = t;
}

#endif
