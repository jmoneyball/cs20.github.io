#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Student {
    protected:
        string* name;
        int* age;

    public:
        // default constructor
        Student();

        // destructor
        ~Student();

        // mutators
        void setName(string);
        void setAge(int);

        // accessors
        string getName() const;
        int getAge() const;
};

#endif
