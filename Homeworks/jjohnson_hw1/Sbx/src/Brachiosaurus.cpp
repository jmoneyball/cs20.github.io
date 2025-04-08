/*
 * Brachiosaurus.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#include "Brachiosaurus.hpp"

Brachiosaurus::Brachiosaurus()
: Dinosaur(5,0) {
	return;
}

void Brachiosaurus::roar() const {
	cout << "BRAAAAAAAAAAAAAAAAAA!" << endl;
}
