#include "Student.h"

#include <iostream>

Student::Student(int code, const std::string &name) {
    code_ = code;
    name_ = name;
    vector<UCTurma> v;
    turmas = v;
}

int Student::getCode() const {
    return code_;
}

string Student::getName() const {
    return name_;
}

bool Student::operator<(const Student& s) const {
    return (code_ < s.getCode());
}

void Student::addTurma(const UCTurma& turma) {
    turmas.push_back(turma);
}

void Student::print() const {
    cout << code_ << ',' << name_ << endl;
    for (UCTurma turma : turmas) {
        cout << "       ";
        turma.print();
    }
}
