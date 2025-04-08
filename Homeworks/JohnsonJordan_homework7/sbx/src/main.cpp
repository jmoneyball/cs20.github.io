#include "MaxHeap.hpp"

const int SIZE1 = 10;

int main() {

	int values1[] = {6, 2, 9, 8, 1 ,0, 4, 5, 3, 7};
	int values2[] = {32, 58, 2, 15, 84, 10, 49, 71, 104, 2};
	MaxHeap<int>* heap = new MaxHeap<int>(SIZE1);

	cout << "=== MAX HEAP TESTING ===\n"
		 << "Original values: ";
	for(int i = 0; i < SIZE1; i++) cout << values1[i] << " ";
	cout << endl << endl;

	cout << "--- INSERTING ---\n";
	cout << "Generating heap using sift up insert:\n";
	heap->insert(values1, SIZE1);
	heap->printTree();
	cout << "\nReplacing heap using sift down insert:\n";
	heap->insert(values2, SIZE1);
	heap->printTree();
	cout << "\nAttempting to sift up insert into a full heap:\n";
	heap->insert(0);

	cout << "\n\n--- FINDING ---\n";
	cout << "Attempting to find 2 in the heap:\n";
	cout << "2 was found at index " << heap->find(2) << endl;
	cout << "\nAttempting to find a value that is not in the heap:\n";
	heap->find(SIZE1);


	cout << "\n\n--- REMOVING ---\n";
	cout << "Removing " << heap->getValue(SIZE1/2 - 1) << " from the middle of the heap:\n";
	heap->remove(SIZE1/2 - 1);
	heap->printTree();
	cout << "\nAttempting to remove an element that doesn't exist:\n";
	heap->remove(SIZE1);
	cout << "\nRemoving root until one element is left:\n";
	while(heap->numNodes() != 1) heap->removeRoot();
	heap->printBuffer();
	cout << "\nAttempting to remove the last element with removeRoot():\n";
	heap->removeRoot();
	cout << "\nAttempting to remove the last element with remove():\n";
	heap->remove(0);

	cout << "\n\n--- HEAPSORT ---\n"
		 << "Original values:\n";
	for(int i = 0; i < SIZE1; i++) cout << values2[i] << " ";
	cout << endl << endl;
	heap->heapsort(values2, SIZE1);








	return(0);
}
