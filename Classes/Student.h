#ifndef AED_PROJ1_STUDENT_H
#define AED_PROJ1_STUDENT_H

#include <string>

#include "UCTurma.h"

using namespace std;

class Student {
public:
    Student(int code, const string& name);
    int getCode() const;
    bool operator<(const Student& s) const ;
    void addTurma(const UCTurma& turma);
    void print() const;
private:
    int code_;
    string name_;
    vector<UCTurma> turmas;
};


#endif //AED_PROJ1_STUDENT_H
