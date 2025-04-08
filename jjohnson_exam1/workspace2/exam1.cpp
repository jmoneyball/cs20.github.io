#include "List.hpp"
#include "LinkedList.hpp"
#include <iomanip>

template <typename T>
bool isMirror(List<T>*);

int main() {
    LinkedList<int>* listy = new LinkedList<int>();

    // empty list
    // true
    cout << boolalpha;
    cout << "Is listy #1 a mirror? The answer is " << isMirror(listy) << endl;

    // 5
    // true
    listy->append(5);
    cout << "Is listy #2 a mirror? The answer is " << isMirror(listy) << endl;

    // 5 --> 7
    // false
    listy->append(7);
    cout << "Is listy #3 a mirror? The answer is " << isMirror(listy) << endl;

    // 5 --> 7 --> 5
    // true
    listy->append(5);
    cout << "Is listy #4 a mirror? The answer is " << isMirror(listy) << endl;

    // 5 --> 7 --> 5 --> 2
    // false
    listy->append(2);
    cout << "Is listy #5 a mirror? The answer is " << isMirror(listy) << endl;

    // 5 --> 7 --> 7 --> 5
    // true
    listy->replace(2, 7);
    listy->replace(3, 5);
    cout << "Is listy #6 a mirror? The answer is " << isMirror(listy) << endl;

    // 5 --> 7 --> 7 --> 5 --> 6
    // false
    listy->append(6);
    cout << "Is listy #7 a mirror? The answer is " << isMirror(listy) << endl;

    // 5 --> 7 --> 6 --> 7 --> 5
    // true
    listy->remove(4);
    listy->insert(2, 6);
    cout << "Is listy #8 a mirror? The answer is " << isMirror(listy) << endl;

    delete listy;
    listy = nullptr;

    return 0;
}

template <typename T>
bool isMirror(List<T>* myList) {
	float half = (float) myList->getLength() / 2;

	//case 1: if there are 0 or 1 elements
	if (myList -> getLength() == 0 || myList -> getLength() == 1)
		return true;
	//case 2: if there are 2 or more elements
	else {
		for(int i = 0; i < half; i++)
			if(myList->getElement(i) != myList->getElement((myList->getLength() - 1) - i))
				return false;
		return true;
	}
}
