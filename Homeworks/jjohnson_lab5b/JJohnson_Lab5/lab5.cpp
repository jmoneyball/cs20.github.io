#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
***** FUNCTION PROTOTYPES
*******************************************************************************/

unsigned product(unsigned, unsigned);
unsigned productRec(unsigned, unsigned);
unsigned count(string, char);
unsigned countRec(string, char, unsigned = 0);

/*******************************************************************************
***** STARTING POINT
*******************************************************************************/

int main() {
    // testing `product`
    cout << "Testing the `product` functions . . .\n";
    cout << "Iterative #1: " << product(1, 5) << endl;
    cout << "Recursive #1: " << productRec(1, 5) << endl;
    cout << "Iterative #2: " << product(3, 7) << endl;
    cout << "Recursive #2: " << productRec(3, 7) << endl;
    cout << "Iterative #3: " << product(15, 15) << endl;
    cout << "Recursive #3: " << productRec(15, 15) << endl;

    // testing `count`
    cout << endl;
    cout << "Testing the `count` functions . . .\n";
    cout << "Iterative #1: " << count("Hey there!", 'e') << endl;
    cout << "Recursive #1: " << countRec("Hey there!", 'e') << endl;
    cout << "Iterative #2: " << count("Oh recursion is fun :)", 'O') << endl;
    cout << "Recursive #2: " << countRec("Oh recursion is fun :)", 'O') << endl;
    cout << "Iterative #3: " << count("A sudden nightmare", 'x') << endl;
    cout << "Recursive #3: " << countRec("A sudden nightmare", 'x') << endl;

    // terminate
    return 0;
}

/*******************************************************************************
***** FUNCTION DEFINITIONS
*******************************************************************************/

/*******************************************************************************
*   Analyzing all basic operations.
*   Input size n is y - x (number of integers separating the two inputs).
*
*   Assume that x <= y.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/

unsigned product(unsigned x, unsigned y) {
    unsigned product = 1;
	for(unsigned i = x; i <= y; i ++) product *= i;
	return product;
}

/*******************************************************************************
*   Analyzing all basic operations.
*   Input size n is y - x (number of integers separating the two inputs).
*
*   Assume that x <= y.
*
*   Asymptotic analysis:
*       T(n) = O(n^2)
*******************************************************************************/

unsigned productRec(unsigned x, unsigned y) {
	unsigned product = 1;
	if(x <= y) return product *= (x * productRec(x + 1, y));
	return product;
}

/*******************************************************************************
*   Analyzing the number of relational operations.
*   Input size n is the length of the string input
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/

unsigned count(string msg, char letter) {
    unsigned count = 0;
    for(long long unsigned int i = 0; i <= msg.size(); i++)
    	if(msg[i] == letter) count++;
    return count;
}

/*******************************************************************************
*   Analyzing the number of relational operations.
*   Input size n is the length of the string input
*
*   Asymptotic analysis:
*       T(n) = O(n^2)
*******************************************************************************/

unsigned countRec(string msg, char letter, unsigned i) {
    unsigned count = 0;
    if(i < msg.size()) {
    	if(msg[i] == letter) count++;
    	return count += countRec(msg, letter, i + 1);
    }
    return count;
}
