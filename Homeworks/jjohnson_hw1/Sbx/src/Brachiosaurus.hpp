/*
 * Brachiosaurus.hpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#ifndef BRACHIOSAURUS_HPP_
#define BRACHIOSAURUS_HPP_

#include "Dinosaur.hpp"

class Brachiosaurus: public Dinosaur {
public:
	Brachiosaurus();
	virtual void roar() const;
};

#endif /* BRACHIOSAURUS_HPP_ */
