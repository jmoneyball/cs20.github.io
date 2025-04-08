/*============================
 *           Student
 *============================
 *- name: string*
 *- age: int*
 *============================
 *+ Student()
 *+ ~Student()
 *+ setName(s: string): void
 *+ setage(i: int): void
 *+ getName() const: string
 *+ getAge() const: int
 *============================
 */

//preprocessor directives
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
private:
	string* name;
	int* age;
public:
	Student();
	~Student();
	void setName(string s);
	void setAge(int i);
	string getName() const;
	int getAge() const;
};

#endif
