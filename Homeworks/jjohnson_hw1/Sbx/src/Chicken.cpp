/*
 * Chicken.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#include "Chicken.hpp"

Chicken::Chicken()
: Dinosaur(5,5) {
	return;
}

void Chicken::roar() const {
	cout << "CLUCK CLUCK!" << endl;
}
