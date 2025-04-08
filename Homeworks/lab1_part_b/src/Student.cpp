#include "Student.hpp"

Student :: Student() {
	name = new string("");
	age = new int(0);
	cout << "Student object created!\n";
}

Student :: ~Student() {
	delete name;
	delete age;
	cout << "Student object destroyed!\n";
}

void Student :: setName(string s) {
	*name = s;
}

void Student :: setAge(int i) {
	*age = i;
}

string Student :: getName() const {
	return *name;
}

int Student :: getAge() const {
	return *age;
}
