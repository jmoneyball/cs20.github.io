#include "LinkedStack.hpp"
#include <string>

int postfixParser(string);

int main() {
    // test #1
    // 6 + 3
    cout << postfixParser("6 3 +") << endl;
    cout << "Answer should be 9" << endl;
    cout << endl;

    // test #2
    // 4 - 7
    cout << postfixParser("4 7 -") << endl;
    cout << "Answer should be -3" << endl;
    cout << endl;

    // test #3
    // 0 * 5
    cout << postfixParser("0 5 *") << endl;
    cout << "Answer should be 0" << endl;
    cout << endl;

    // test #4
    // 9 / 2
    cout << postfixParser("9 2 /") << endl;
    cout << "Answer should be 4" << endl;
    cout << endl;

    // test #5
    // 1 / 0
    cout << postfixParser("1 0 /") << endl;
    cout << "Should display an error message and return 0" << endl;
    cout << endl;

    // test #6
    // 10 + 3
    cout << postfixParser("10 3 +") << endl;
    cout << "Answer should be 13" << endl;
    cout << endl;

    // test #7
    // 6 + 3
    cout << postfixParser("6 3 +") << endl;
    cout << "Answer should be 9" << endl;
    cout << endl;

    // test #8
    // 10 - 3 * 4
    cout << postfixParser("18 3 4 * -") << endl;
    cout << "Answer should be 6" << endl;
    cout << endl;

    // test #9
    // 11 * 2 / 2
    cout << postfixParser("11 2 * 2 /") << endl;
    cout << "Answer should be 11" << endl;
    cout << endl;

    // test #10
    // (2 - 7) * 3
    cout << postfixParser("2 7 - 3 *") << endl;
    cout << "Answer should be -15" << endl;
    cout << endl;

    // test #11
    // (13 - 8) * (6 + 4)
    cout << postfixParser("13 8 - 6 4 + *") << endl;
    cout << "Answer should be 50" << endl;
    cout << endl;

    // test #12
    // ((5 + 14) * (9 - 6 / 4)) + 10
    cout << postfixParser("5 14 + 9 6 4 / - * 10 +") << endl;
    cout << "Answer should be 162" << endl;
    cout << endl;

    return 0;
}

int postfixParser(string expression) {
	//declarations
	LinkedStack<string> stack;
	int a, b;

	//iterates thru string
	for(long long unsigned i = 0; i < expression.length(); i++) {
		//resets token
		string token = "";

		//if i is a whitespace, skip
		if(isspace(expression[i]))
			continue;
		//if i is a number
		else if(isdigit(expression[i])) {
			token = expression[i];

			//if i is part of a 2 digit number
			if(isdigit(expression[i-1])) //skip if previous digit was parsed
				continue;
			else if(isdigit(expression[i+1])) //combine current and next digit
				token += expression[i+1];
		}
		//if i is a symbol
		else {
			//pop top 2 numbers
			b = stoi(stack.top());
			stack.pop();
			a = stoi(stack.top());
			stack.pop();

			//addition
			if(expression[i] == '+') {
				cout << a << " + " << b << endl;
				token = to_string(a + b);
			}
			//subtraction
			else if(expression[i] == '-') {
				cout << a << " - " << b << endl;
				token = to_string(a - b);
			}
			//multiplication
			else if(expression[i] == '*') {
				cout << a << " * " << b << endl;
				token = to_string(a * b);
			}
			//division
			else if(expression[i] == '/') {
				//handles division by zero
				cout << a << " / " << b << endl;
				if (b == 0)	{
					cerr << "Error... cannot divide by a zero" << endl;
					cout << "= ";
					return 0;
				}
				token = to_string(a / b);
			}
		}
		//pushes number(s) onto stack
		stack.push(token);
	}
	//returns final answer as an integer
	cout << "= ";
	return stoi(stack.top());
}
