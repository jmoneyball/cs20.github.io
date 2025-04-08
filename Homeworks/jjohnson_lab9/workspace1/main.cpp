#include "ArrayStack.hpp"
int main() {
	//creates stack
	cout << "Creating an array-based stack..." << endl;
	ArrayStack<int> myStack(5);
	cout << "Max size: " << myStack.getMaxSize() << endl << endl;

	//pushing elements into the stack
	cout << "Pushing elements to the stack... " << endl;
	for(int i = 1; i <= 5; i++) {
		myStack.push(i);
	}
	cout << "Stack length: " << myStack.getLength() << endl << endl;

	//tests overflow handling
	cout << "Attempting to push an element into a full stack..." << endl;
	myStack.push(0);
	cout << "Stack length: " << myStack.getLength() << endl << endl;

	//copies myStack to copyStack
	cout << "Testing stack copy function..." << endl;
	ArrayStack<int> copyStack(myStack);
	cout << "Stack length: " << copyStack.getLength() << endl << endl;

	//outputting elements in stack
	cout << "Empties stack using pop function..." << endl;
	while(!myStack.isEmpty()){
		cout << myStack.top() << endl;
		myStack.pop();
	}
	cout << "Stack length: " << myStack.getLength() << endl << endl;

	//clearing copy stack
	cout << "Clearing copyStack..." << endl;
	copyStack.clear();
	cout << "Stack length: " << myStack.getLength() << endl << endl;

	//tests underflow handling
	cout << "Attempting to pop from an empty stack..." << endl;
	myStack.pop();
	cout << "Stack length: " << myStack.getLength() << endl << endl;

	//tests top for error handling
	cout << "Attempting to view an empty stack..." << endl
		 << myStack.top() << endl << endl;

	cout << "Program ending...";


	return 0;
}
