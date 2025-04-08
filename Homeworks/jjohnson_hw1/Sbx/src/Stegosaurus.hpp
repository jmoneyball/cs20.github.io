/*
 * Stegosaurus.hpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#ifndef STEGOSAURUS_HPP_
#define STEGOSAURUS_HPP_

#include "Dinosaur.hpp"

class Stegosaurus: public Dinosaur {
public:
	Stegosaurus();
	virtual void roar() const;
};

#endif /* STEGOSAURUS_HPP_ */
