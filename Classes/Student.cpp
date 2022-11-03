#include "Student.h"

#include <iostream>
/*
Student::Student(int code) {
    code_ = code;
    vector<UCTurma> v;
    turmas = v;
}*/

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
        cout << "       " << turma.getUC() << ',' << turma.getTurma() << endl;
    }
}

Student& Student::operator=(const Student& student) {
    name_ = student.name_;
    code_ = student.code_;
    for(UCTurma turma : student.turmas) {
        turmas.push_back(turma);
    }
    return *this;
}

void Student::removeTurma(const UCTurma &turma) {
    vector<UCTurma>::iterator itr;
    for (itr = turmas.begin(); itr != turmas.end(); itr++)
        if (itr->getTurma() == turma.getTurma() && itr->getUC() == turma.getUC()) {
            break;
        }
    turmas.erase(itr);
}

void Student::loadSchedule(GestaoHor& g) const {
    for (UCTurma ucTurma : turmas) {
        g.findUC(ucTurma)->loadSlots(g);
    }
}

vector<UCTurma> Student::getTurmas() const {
    return turmas;
}
