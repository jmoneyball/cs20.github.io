#include "LinkedQueue.hpp"

int main() {
	LinkedQueue<int> q, q2;
	cout << "Creating queues q and q2...\n\n";

	for(int i = 1; i <= 10; i++) {
		cout << "Adding " << i << " to queue q...\n";
		q.enqueue(i);
	}
	cout << "q Length -> " << q.getLength() << endl;
	cout << "q Front -> " << q.front() << endl;
	cout << "q Back -> " << q.back() << endl;
	cout << endl;

	cout << "Removing two items from queue q...\n";
	q.dequeue();
	q.dequeue();
	cout << "q Length -> " << q.getLength() << endl;
	cout << "q Front -> " << q.front() << endl;
	cout << "q Back -> " << q.back() << endl;
	cout << endl;

	cout << "Copying q to q2...\n";
	q2 = q;
	cout << "q2 Length -> " << q2.getLength() << endl;
	cout << "q2 Front -> " << q2.front() << endl;
	cout << "q2 Back -> " << q2.back() << endl;
	cout << endl;

	cout << "Adding 3 numbers to queue q2...\n";
	q2.enqueue(72);
	q2.enqueue(-1);
	q2.enqueue(243);
	cout << "q2 Length -> " << q2.getLength() << endl;
	cout << "q2 Front -> " << q2.front() << endl;
	cout << "q2 Back -> " << q2.back() << endl;
	cout << endl;

	cout << "Clearing both queues...\n";
	q.clear();
	q2.clear();
	cout << "q Length -> " << q.getLength() << endl;
	cout << "q Front -> " << q.front() << endl;
	cout << "q Back -> " << q.back() << endl;
	cout << endl;
	cout << "q2 Length -> " << q.getLength() << endl;
	cout << "q2 Front -> " << q.front() << endl;
	cout << "q2 Back -> " << q.back() << endl;
	cout << endl;

	return (0);
}
