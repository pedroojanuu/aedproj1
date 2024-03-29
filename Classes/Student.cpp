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
    cout << code_ << " | " << name_ << endl;
}

Student& Student::operator=(const Student& student) {
    name_ = student.name_;
    code_ = student.code_;
    turmas.clear();
    for(const UCTurma & turma : student.turmas) {
        turmas.push_back(turma);
    }
    return *this;
}

bool Student::removeTurma(const UCTurma &turma) {
    vector<UCTurma>::iterator itr;
    for (itr = turmas.begin(); itr != turmas.end(); itr++)
        if (itr->getTurma() == turma.getTurma() && itr->getUC() == turma.getUC()) {
            break;
        }
    if (itr == turmas.end()) return false;
    turmas.erase(itr);
    return true;
}

void Student::loadSchedule(GestaoHor& g) const {
    for (const UCTurma & ucTurma : turmas) {
        g.findUC(ucTurma)->loadSlots(g);
    }
}

vector<UCTurma> Student::getTurmas() const {
    return turmas;
}
