#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include "UCTurma.h"

using namespace std;

class Student {
public:
    Student();
    Student(int code, const string& name);

private:
    int studentCode_;
    string studentName_;
    vector<UCTurma> turmas;
};


#endif //UNTITLED_STUDENT_H
