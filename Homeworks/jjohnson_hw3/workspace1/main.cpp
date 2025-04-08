#include "LinkedList.hpp"
#include <ctime>

//constants
const int SIZE = 10;
const int MAX = 101;

//function prototypes
void print(LinkedList<int>);

//main function
int main() {
	//declarations
	LinkedList<int> myLL1, myLL2;
	srand(time(0));

	//testing recursive append
	for(int i = 1; i <= SIZE; i++) {
		myLL1.append(rand() % MAX);
		myLL2.append(i);
	}
	cout << "Using append to create linked lists...\n______________________________________\n\n";
	cout << "myLL1 = "; print(myLL1);
	cout << "myLL2 = "; print(myLL2);
	cout << "\n\n";

	//testing recursive remove
	cout << "Removing a node at the beginning, middle, and end of the lists...\n_________________________________________________________________\n\n";
	myLL1.remove(SIZE - 1); myLL2.remove(SIZE - 1); //remove at last node
	myLL1.remove((SIZE/2)); myLL2.remove((SIZE/2)); //remove at middle node
	myLL1.remove(0); myLL2.remove(0); //remove at first node
	cout << "myLL1 = "; print(myLL1);
	cout << "myLL2 = "; print(myLL2);
	cout << "\n\n";

	//testing recursive insert
	cout << "Inserting a node at the beginning, middle, and end of the lists...\n__________________________________________________________________\n\n";
	myLL1.insert(0, rand() % MAX); myLL2.insert(0, rand() % MAX); //inserts at first node
	myLL1.insert((SIZE/2), rand() % MAX); myLL2.insert((SIZE/2), rand() % MAX); //inserts at middle node
	myLL1.insert(SIZE - 2, rand() % MAX); myLL2.insert(SIZE - 2, rand() % MAX); //inserts at last node
	cout << "myLL1 = "; print(myLL1);
	cout << "myLL2 = "; print(myLL2);
	cout << "\n\n";

	//testing recursive replace
	cout << "Replacing0 a node at the beginning, middle, and end of the lists...\n________________________________________________________________\n\n";
	myLL1.replace(SIZE - 1, 100); myLL2.replace(SIZE - 1, 10); //replace at last node
	myLL1.replace(SIZE/2, 6); myLL2.replace(SIZE/2, 6); //replace at middle node
	myLL1.replace(0, 1); myLL2.replace(0, 1); //replace at first node
	cout << "myLL1 = "; print(myLL1);
	cout << "myLL2 = "; print(myLL2);
	cout << "\n\n";

	//testing recursive get element
	cout << "Returning the element at the beginning, middle, and end of the lists...\n_______________________________________________________________________\n\n";
	cout << "myLL1, element 0 --> " << myLL1.getElement(0) << "\t\t"; cout << "myLL2, element 0 --> " << myLL2.getElement(0) << endl; //get first element
	cout << "myLL1, element 4 --> " << myLL1.getElement(SIZE/2 - 1) << "\t\t"; cout << "myLL2, element 4 --> " << myLL2.getElement(SIZE/2 - 1) << endl; //get middle element
	cout << "myLL1, element 9 --> " << myLL1.getElement(SIZE - 1) << "\t"; cout << "myLL2, element 9 --> "<< myLL2.getElement(SIZE - 1) << endl; //get last element
	cout << "\n\n";

	//testing recursive clear
	cout << "Clearing myLL2...\n_________________\n\n";
	myLL2.clear();
	cout << "myLL1 = "; print(myLL1);
	cout << "myLL2 = "; print(myLL2);
	cout << "\n\n";

	//testing recursive copy
	cout << "Copying myLL1 to myLL2...\n_________________________\n\n";
	myLL2 = myLL1;
	cout << "myLL1 = "; print(myLL1);
	cout << "myLL2 = "; print(myLL2);
	cout << "\n\n";

	//testing recursive insert bounds
	cout << "Attempting to insert outside of bounds...\n_________________________________________\n\n";
	myLL1.insert(MAX, MAX);
	cout << "\n\n";

	//testing recursive clear
	cout << "Clearing both lists...\n_________________________\n\n";
	myLL1.clear(); myLL2.clear();
	cout << "myLL1 = "; print(myLL1);
	cout << "myLL2 = "; print(myLL2);
	cout << "\n\nGoodbye!!";

	return 0;
}

void print(LinkedList<int> LL) {
	//testing recursive print
	cout << LL.getLength() << " nodes\n" << LL << endl;
}
