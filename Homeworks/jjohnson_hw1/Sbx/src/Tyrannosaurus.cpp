/*
 * Tyrannosaurus.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#include "Tyrannosaurus.hpp"

Tyrannosaurus::Tyrannosaurus()
: Dinosaur(0,0) {
	return;
}

void Tyrannosaurus::roar() const {
	cout << "RAWRRRRRRRRRRR!" << endl;
}
