#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
* Function prototype
*******************************************************************************/

void towerHanoi(int, string, string, string, int&);

/*******************************************************************************
* int main()
*   Starting point of the program.
*
* Output:
*   An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}

/*******************************************************************************
* void towerHanoi(int numDisks, string source, string buffer,
*                 string target, int& numMoves)
*   Solve the Tower of Hanoi problem using a recursive approach.
*
* Inputs:
*   numDisks - an integer that represents the number of disks
*   source   - a string that names the source rod
*   buffer   - a string that names the buffer rod
*   target   - a string that names the target rod
*   numMoves - a reference integer that holds the number of moves made so far
*
* Output:
*   N/A
*
* Analysis:
*   Analyzing the number of "moves".
*   Let n = numDisks
*
*   T(1) = 1
*   T(2) = 2*T(1) + 1
*   T(3) = 2*T(2) + 1
*   ...
*   T(n) = 2n + 1
*   	 = O(n)
*******************************************************************************/

void towerHanoi(int numDisks, string source, string buffer, string target, int& numMoves) {
	numMoves++;
	//base case
	if(numDisks == 1)
		cout << "Moving disk 1 from " << source << " to " << target << endl;
	//recursive case
	else {
		towerHanoi(numDisks - 1, source, target, buffer, numMoves);
		cout << "Moving disk " << numDisks << " from " << source << " to " << target << endl;
		towerHanoi(numDisks - 1, buffer, source, target, numMoves);
	}
}
