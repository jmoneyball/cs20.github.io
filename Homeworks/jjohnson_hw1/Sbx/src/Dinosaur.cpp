/*
 * Dinosaur.cpp
 *
 *  Created on: Feb 4, 2021
 *      Author: Jordan
 */

#include "Dinosaur.hpp"

//constructor
Dinosaur::Dinosaur(int a, int b) {
	name = new string(" ");
	attack = new string(" ");
	token = new char(' ');
	x = new int(a);
	y = new int(b);
	alive = new bool(true);
}

//destructor
Dinosaur::~Dinosaur() {
	delete name;
	delete attack;
	delete token;
	delete x;
	delete y;
	delete alive;
}

//operator overloading
bool Dinosaur::operator==(const Dinosaur& otherObj) const {
	if(*x == *otherObj.x and *y == *otherObj.y) return true;
	else{return false;}
}

//accessors
string Dinosaur::getName() const {
	return *name;
}
string Dinosaur::getAttack() const {
	return *attack;
}
char Dinosaur::getToken() const {
	return *token;
}
int Dinosaur::getX() const {
	return *x;
}
int Dinosaur::getY() const {
	return *y;
}
bool Dinosaur::isAlive() const {
	return *alive;
}

//mutators
void Dinosaur::setName(string n) {
	*name = n;
}
void Dinosaur::setAttack(string a) {
	*attack = a;
}
void Dinosaur::setToken(char t) {
	*token = t;
}
void Dinosaur::updateX(int i) {
	if((*x + i) < 0) *x = 0;
	else if((*x + i) > 5) *x = 5;
	else (*x += i);

}
void Dinosaur::updateY(int i) {
	if((*y + i) < 0) *y = 0;
	else if((*y + i) > 5) *y = 5;
	else (*y += i);
}
void Dinosaur::setDead() {
	*alive = false;
}
