#include "utils.hpp"
#include "Dinosaur.hpp"
#include <iostream>
using namespace std;

bool isOver(Dinosaur* arr[], const int SIZE) {
	int numAlive = 0;
	for(int i = 0; i < SIZE; i++) {
		if(arr[i]->isAlive())
			numAlive++;
	}
	if(numAlive != 1) return false;
	else{return true;}
}

void victoryMessage(Dinosaur* arr[], const int SIZE) {
	for(int i = 0; i < SIZE; i++) {
		if(arr[i]->isAlive()) {
			cout << arr[i]->getName() << " is the Jurassic Conquest champion!\nAny final words from the winner?\n";
			arr[i]->roar();
		}
	}
}

/*******************************************************************************
********************************************************************************
********************************************************************************
********************************************************************************
*******************************************************************************/

void welcome(Dinosaur* arr[]) {
    cout << "Welcome to Jurassic Conquest!\n";
    cout << "You will be selecting four different champions to compete.\n\n";

    cout << "First up is the Tyrannosaurus!\n";
    userInput(arr[0]);
    cout << endl;

    cout << "Second is the Stegosaurus!\n";
    userInput(arr[1]);
    cout << endl;

    cout << "Third for the group is the Brachiosaurus!\n";
    userInput(arr[2]);
    cout << endl;

    cout << "And the last dinosaur to grace us is . . . the Chicken!!!\n";
    userInput(arr[3]);
    cout << endl << endl;
}

void userInput(Dinosaur* dino) {
    string s = "";
    char   c = '\0';

    cout << "Enter its name: ";
    getline(cin, s);
    dino->setName(s);

    cout << "Enter its attack: ";
    getline(cin, s);
    dino->setAttack(s);

    cout << "Enter its character token: ";
    cin >> c;
    dino->setToken(c);

    cin.ignore();
}

void conquer(Dinosaur* arr[], const int SIZE) {
    while (!isOver(arr, SIZE)) {
        for (int i = 0; i < SIZE; i++) {
            if (rand() % 2 == 0) {
                if (rand() % 2 == 0) {
                    arr[i]->updateX(-2 + rand() % 5);
                }
                else {
                    arr[i]->updateY(-2 + rand() % 5);
                }
            }
        }

        display(arr, SIZE);
        fight(arr, SIZE);
    }
}

void fight(Dinosaur* arr[], const int SIZE) {
    int r = 0;

    for (int i = 0; i < SIZE; i++) {
        if (!arr[i]->isAlive()) {
            continue;
        }

        for (int j = i + 1; j < SIZE; j++) {
            if (!arr[j]->isAlive()) {
                continue;
            }

            if (*arr[i] == *arr[j]) {
                cout << arr[i]->getName() << " roars ";
                arr[i]->roar();

                cout << arr[j]->getName() << " roars ";
                arr[j]->roar();

                r = rand() % 10;
                if (r < 6) {
                    cout << "Nothing happens . . . "
                         << "both competitors live to see another day\n";
                }
                else if (r < 8) {
                    cout << arr[i]->getName() << " uses its attack "
                         << arr[i]->getAttack() << " and defeats "
                         << arr[j]->getName() << endl;
                    arr[j]->setDead();
                }
                else {
                    cout << arr[j]->getName() << " uses its attack "
                         << arr[j]->getAttack() << " and defeats "
                         << arr[i]->getName() << endl;
                    arr[i]->setDead();
                }

                cout << endl;
            }
        }
    }
}

void display(Dinosaur* arr[], const int SIZE) {
    const char FILL     = '-';
    const int  NUM_ROWS = 6,
               NUM_COLS = 6,
               WIDTH    = NUM_COLS * 4 - 1;
          bool flag     = false;

    cout << " " << setfill(FILL) << setw(WIDTH) << "" << endl;

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            cout << "| ";

            for (int k = 0; k < SIZE; k++) {
                if (arr[k]->getX() == i &&
                    arr[k]->getY() == j &&
                    arr[k]->isAlive())
                {
                    cout << arr[k]->getToken();
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                cout << "  ";
            }
            else {
                flag = false;
                cout << " ";
            }
        }

        cout << "|\n";
        cout << " " << setfill(FILL) << setw(WIDTH) << "" << endl;
    }

    cout << endl;
}
