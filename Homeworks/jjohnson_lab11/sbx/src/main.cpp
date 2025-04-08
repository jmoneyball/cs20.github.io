#include "ArrayQueue.hpp"

int main() {
	ArrayQueue<int> q(9), q2(9);
	cout << "Creating queues q and q2 with a maxSize of 9...\n\n";

	cout << "Populating q...\n";
	for(int i = 1; i < 10; i++) {
		cout << "Adding " << i << " to q...\n";
		q.enqueue(i);
	}
	cout << endl;
	cout << "q Length -> " << q.getLength() << endl;
	cout << "q Front -> " << q.front() << endl;
	cout << "q Back -> " << q.back() << endl;
	cout << endl;

	cout << "Attempting to add to q when it is full...\n";
	q.enqueue(1);
	cout << endl;

	cout << "Removing two items from q...\n";
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

	cout << "Clearing q...\n";
	q.clear();
	cout << "q Length -> " << q.getLength() << endl;
	cout << "q Front -> " << q.front() << endl;
	cout << "q Back -> " << q.back() << endl;
	cout << endl;

	cout << "Attempting to remove from q when it is empty...\n";
	q.dequeue();
	cout << endl;

	cout << "Adding two values to q2...\n";
	q2.enqueue(57);
	q2.enqueue(712);
	cout << "q2 Length -> " << q2.getLength() << endl;
	cout << "q2 Front -> " << q2.front() << endl;
	cout << "q2 Back -> " << q2.back() << endl;
	cout << endl;

	cout << "Emptying the q2...\n";
	while(!q2.isEmpty()){
		cout << q2.front() << endl;
		q2.dequeue();
	}

	cout << "\nProgram ending...";
	return (0);
}
