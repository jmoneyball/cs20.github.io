#include "Deque.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // create an array of values
    const int MAX_SIZE = 10;
    int randomVals[MAX_SIZE] = {
        92, 31, 10, 88, 25, 41, 2, 78, 6, 13
    };

    // create a deque of integers
    Deque<int> dequeA;

    // attempt to display the front and back
    try {
        cout << dequeA.front() << endl;
    } catch (...) { }
    try {
        cout << dequeA.back() << endl;
    } catch (...) { }

    // insert just one element to deque A
    dequeA.enqueue(-5);

    // display its length, front, and back
    cout << "deque A length: " << dequeA.getLength() << endl;
    cout << "deque A front: " << dequeA.front() << endl;
    cout << "deque A back: " << dequeA.back() << endl;

    // now remove the single element from deque A
    dequeA.dequeue();

    // display its length, front, and back
    cout << "deque A length: " << dequeA.getLength() << endl;
    try {
        cout << dequeA.front() << endl;
    } catch (...) { }
    try {
        cout << dequeA.back() << endl;
    } catch (...) { }

    // populate deque A by enqueueing values to the back
    for (int i = 0; i < MAX_SIZE / 2; i++) {
        dequeA.enqueue(randomVals[i]);
    }

    // display its length, front, and back
    cout << "deque A length: " << dequeA.getLength() << endl;
    cout << "deque A front: " << dequeA.front() << endl;
    cout << "deque A back: " << dequeA.back() << endl;

    // populate deque A by enqueueing values to the front
    for (int i = MAX_SIZE / 2; i < MAX_SIZE; i++) {
        dequeA.enqueueFront(randomVals[i]);
    }

    // make a copy of deque A using the copy constructor
    Deque<int> dequeB = dequeA;

    // loop to dequeue from the front of deque A and print
    cout << "deque A contains: ";
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << dequeA.front() << ' ';
        dequeA.dequeue();
    }
    cout << endl;

    // deque A should now be empty
    if (dequeA.isEmpty()) {
        cout << "deque A is now empty\n";
    }
    else {
        cout << "deque A is not empty [ERROR]\n";
    }

    // display deque B length, front, and back
    cout << "deque B length: " << dequeB.getLength() << endl;
    cout << "deque B front: " << dequeB.front() << endl;
    cout << "deque B back: " << dequeB.back() << endl;

    // make a copy of deque B using the assignment overload
    Deque<int> dequeC;
    dequeC = dequeB;

    // loop to dequeue from the back of deque B and print in reverse order
    cout << "deque B contains: ";
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << dequeB.back() << ' ';
        dequeB.dequeueBack();
    }
    cout << endl;

    // display deque C length, front, and back
    cout << "deque C length: " << dequeC.getLength() << endl;
    cout << "deque C front: " << dequeC.front() << endl;
    cout << "deque C back: " << dequeC.back() << endl;

    // terminate
    return 0;
}
