#include "CS_Student.hpp"

/*******************************************************************************
* Function Prototypes
*******************************************************************************/

void getInput(CS_Student[], const int);
void display(const CS_Student[], const int);
void forceCopyAndAssign(CS_Student);

/*******************************************************************************
* int main()
*   Starting point of the program. Creates an array of `CS_Student` objects.
*
* Output:
*   An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // variables
    const int SIZE = 2;
    CS_Student objArray[SIZE];

    // get input from the user
    getInput(objArray, SIZE);

    // for each object, force it to copy and assign
    for (int i = 0; i < SIZE; i++) {
        forceCopyAndAssign(objArray[i]);
    }

    // display the modified information back to the user
    display(objArray, SIZE);

    // terminate
    return 0;
}

/*******************************************************************************
* void getInput(CS_Student objArray[], const int SIZE)
*   Uses a `for` loop to prompt the user for the name/age of each student. Store
*   the information in the appropriate object.
*
* Inputs:
*   objArray - an array of CS_Student objects
*   SIZE     - a constant integer that represents the size of the array
*
* Output:
*   N/A
*******************************************************************************/

void getInput(CS_Student objArray[], const int SIZE) {
    // temporary variables
    int    t = 0;
    string s = "", p = "";

    // for each student
    for (int i = 0; i < SIZE; i++) {
        // prompt and store the name of the current student
        cout << "Enter the name for student #" << i + 1 << ": ";
        getline(cin, s);

        // prompt and store for the age of the current student
        cout << "Enter the age for student #" << i + 1 << ": ";
        cin >> t;

        // need to ignore the newline for the next iteration
        cin.ignore();

        // prompt and store the favorite programming language
        // of the current student
        cout << "Enter the favorite programming language for student #"
             << i + 1 << ": ";
        getline(cin, p);

        // store the data from the user into the current object in the array
        objArray[i].setName(s);
        objArray[i].setAge(t);
        objArray[i].setFavProgLang(p);
    }
}

/*******************************************************************************
* void display(const CS_Student objArray[], const int SIZE)
*   Uses a `while` loop to display the information about the students stored in
*   the object array.
*
* Inputs:
*   objArray - an array of CS_Student objects
*   SIZE     - a constant integer that represents the size of the array
*
* Output:
*   N/A
*******************************************************************************/

void display(const CS_Student objArray[], const int SIZE) {
    // counter variable
    int i = 0;

    // iterate through each student
    while (i < SIZE) {
        // display the student's information
        cout << "CS_Student #" << i + 1 << endl;
        cout << "\tName: " << objArray[i].getName() << endl;
        cout << "\tAge: " << objArray[i].getAge() << endl;
        cout << "\tFavorite Programming Language: "
             << objArray[i].getFavProgLang() << endl << endl;

        // update the counter
        i++;
    }
}

/*******************************************************************************
* void forceCopyAndAssign(CS_Student obj)
*   Will force the copy constructor to be called on `obj`, the default
*   constructor for `temp`, the assignment operator overload for `temp`, and
*   then the destructor for both `temp` and `obj`.
*
* Inputs:
*   obj - a `CS_Student` object
*
* Output:
*   N/A
*******************************************************************************/

void forceCopyAndAssign(CS_Student obj) {
    CS_Student temp;
    temp = obj;
}
