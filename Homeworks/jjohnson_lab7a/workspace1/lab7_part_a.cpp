#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/*******************************************************************************
* Function prototype
*******************************************************************************/

template <typename T>
T findMaxRecTail(const T[], const int, int = 0);

/*******************************************************************************
* int main()
*   Starting point of the program.
*
* Output:
*   An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE) << endl
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}

/*******************************************************************************
* T findMaxRecTail(const T arr[], const int SIZE, int i)
*   Determine the maximum element in the array using a recursive tail approach.
*
* Inputs:
*   arr  - a constant array of type T
*   SIZE - a constant integer that holds the size of the `arr` parameter
*   i    - an integer that represents the current position of the "head"
*          of `arr` (has a default value of 0)
*
* Output:
*   The maximum element in `arr` starting at position `i`
*
* Analysis:
*   Analyzing the number of comparison and arithmetic operators.
*   Let n = SIZE
*
*   Assume n > 0
*
*   <INSERT ANALYSIS HERE>
*   T(0) = 1
*   T(1) = 1 + T(0) + 2n
* 		 = 2 + 2n
*   T(2) = 1 + T(1) + 2n
*   	 = 3 + 4n
*   ...
*   T(n) = O(n)
*******************************************************************************/

template <typename T>
T findMaxRecTail(const T arr[], const int SIZE, int i) {
	//declarations
	T head = arr[i];
	T max;
	//base case
	if(i == SIZE)
		return head;
	//recursive case
	else {
		max = findMaxRecTail(arr, SIZE, (i+1));
		if(max < head)
			max = head;
	}
	return max;
}
