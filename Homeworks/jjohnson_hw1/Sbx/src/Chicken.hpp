/*
 * Chicken.hpp
 *
 *  Created on: Feb 6, 2021
 *      Author: Jordan
 */

#ifndef CHICKEN_HPP_
#define CHICKEN_HPP_

#include "Dinosaur.hpp"

class Chicken: public Dinosaur {
public:
	Chicken();
	virtual void roar() const;
};

#endif /* CHICKEN_HPP_ */
