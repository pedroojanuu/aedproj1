#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include "UCTurma.h"

using namespace std;

class Student {
public:
    Student();
    Student(int code, const string& name);
    int getCode() const;
    bool operator < (const Student& s);
    void addTurma(const UCTurma & turma);
private:
    int studentCode_;
    string studentName_;
    vector<UCTurma> turmas;
};


#endif //UNTITLED_STUDENT_H
