#ifndef CS_STUDENT_HPP
#define CS_STUDENT_HPP

#include "Student.hpp"
using namespace std;

class CS_Student: public Student {
private:
	string* favProgLang;
public:
	CS_Student();
	CS_Student(const CS_Student& copyObj);
	CS_Student& operator=(const CS_Student& rightObj);
	~CS_Student();
	void setFavProgLang(string s);
	string getFavProgLang() const;
};

#endif
