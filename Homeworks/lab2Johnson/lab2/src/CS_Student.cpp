#include "CS_Student.hpp"
using namespace std;

CS_Student :: CS_Student()
: 	favProgLang(new string("")) {
	cout << "CS_Student object created!" << endl;
}

CS_Student :: CS_Student(const CS_Student& copyObj){
	this -> name = copyObj.name;
	this -> age = copyObj.age;
	this -> favProgLang = copyObj.favProgLang;
	cout << "CS_Student object copied!" << endl;
}

CS_Student& CS_Student :: operator=(const CS_Student& rightObj) {
	name = rightObj.name;
	age = rightObj.age;
	favProgLang = rightObj.favProgLang;
	cout << "CS_Student object assigned!" << endl;
	return *this;
}

CS_Student :: ~CS_Student(){
	cout << "CS_Student object destroyed!" << endl;
	delete favProgLang;
}

void CS_Student :: setFavProgLang(string s) {
	*favProgLang = s;
}

string CS_Student :: getFavProgLang() const {
	return *favProgLang;
}
