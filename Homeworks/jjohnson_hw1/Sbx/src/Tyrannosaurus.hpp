/*
 * Tyrannosaurus.hpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#ifndef TYRANNOSAURUS_HPP_
#define TYRANNOSAURUS_HPP_

#include "Dinosaur.hpp"

class Tyrannosaurus: public Dinosaur {
public:
	Tyrannosaurus();
	virtual void roar() const;
};

#endif /* TYRANNOSAURUS_HPP_ */
