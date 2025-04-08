/*
 * Stegosaurus.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#include "Stegosaurus.hpp"

Stegosaurus::Stegosaurus()
: Dinosaur(0,5) {
	return;
}

void Stegosaurus::roar() const {
	cout << "GRRRRRRRRRRRRRR!" << endl;
}
