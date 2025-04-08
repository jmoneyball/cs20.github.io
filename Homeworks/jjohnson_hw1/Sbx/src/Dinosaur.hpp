/*
 * Dinosaur.h
 *
 *  Created on: Feb 4, 2021
 *      Author: Jordan
 */

#ifndef DINOSAUR_H_
#define DINOSAUR_H_

#include <iostream>
using namespace std;

class Dinosaur {
private:
	string* name;
	string* attack;
	char* token;
	int* x;
	int* y;
	bool* alive;
public:
	//constructor
	Dinosaur(int, int);
	//destructor
	virtual ~Dinosaur();
	//operator overloading
	bool operator==(const Dinosaur&) const;
	//accessors
	string getName() const;
	string getAttack() const;
	char getToken() const;
	int getX() const;
	int getY() const;
	bool isAlive() const;
	//mutators
	void setName(string);
	void setAttack(string);
	void setToken(char);
	void updateX(int);
	void updateY(int);
	void setDead();
	//other methods
	virtual void roar() const = 0;
};

#endif /* DINOSAUR_H_ */
