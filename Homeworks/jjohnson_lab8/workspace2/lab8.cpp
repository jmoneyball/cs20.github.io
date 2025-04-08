#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
* Function prototypes
*******************************************************************************/

unsigned fact(unsigned, unsigned = 1);
unsigned fib(unsigned, unsigned = 0, unsigned = 1);
unsigned mult(unsigned, unsigned, unsigned = 0);
unsigned power(unsigned, unsigned, unsigned = 1);
unsigned product(unsigned, unsigned, unsigned = 1);

/*******************************************************************************
* int main()
*   Starting point of the program.
*
* Output:
*   An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;

    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
*   THE FUNCTIONS BELOW ARE NOT TAIL RECURSIVE!!!
*   TODO: make them all tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n, unsigned total) {
	//tail recursive
	if(n == 0) return total;
	return fact(n - 1, total * n);

//	//not tail recursive
//    // base cases (combined)
//    if (n <= 1) {
//        return 1;
//    }
//
//    // recursive case
//    unsigned res = fact(n - 1);
//    return res * n;
}

unsigned fib(unsigned n, unsigned a, unsigned b) {
	//tail recursive
	// base case 1
	if (n == 0) return 0;
	// base case 2
	else if (n == 1) return b;
	//recursive case
	return fib(n - 1, b, a + b);

//	//not tail recursive
//    // base case 1
//    if (n == 0) {
//        return 0;
//    }
//
//    // base case 2
//    else if (n == 1) {
//        return 1;
//    }
//
//    // recursive case
//    return fib(n - 1) + fib(n - 2);
}

unsigned mult(unsigned x, unsigned y, unsigned total) {
	//tail recursive
	if(y == 0) return total;
	else if(x == 0 || y == 0) return 0;
	return mult(x, y - 1, total + x);

	//not tail recursive
//    // base case
//    if (y == 0) {
//        return 0;
//    }
//
//    // recursive case
//    unsigned res = mult(x, y - 1);
//    return res + x;
}

unsigned power(unsigned x, unsigned y, unsigned total) {
	//tail recursive
	if(y == 0) return total;
	return power(x, y - 1, total * x);

	//not tail recursive
    // base case
//    if (y == 0) {
//        return 1;
//    }
//
//    // recursive case
//    unsigned res = power(x, y - 1);
//    return res * x;
}

unsigned product(unsigned x, unsigned y, unsigned total) {
	//tail recursive
	if(x == y) return total * x;
	else if(x == 0 || y == 0) return 0;
	return product(x + 1, y, total * x);

//    // base case
//    if (x == y) {
//        return x;
//    }
//
//    // recursive case
//    unsigned p = product(x + 1, y);
//    return p * x;
}
