#include "Student.h"

Student::Student() {
    studentCode_ = 0;
    studentName_ = nullptr;
}

Student::Student(int code, const std::string& name) {
    studentCode_ = code;
    studentName_ = name;
}

int Student::getCode() const {
    return studentCode_;
}

bool Student::operator<(const Student &s) {
    return studentCode_ < s.getCode();
}

void Student::addTurma(const UCTurma & turma) {
    turmas.push_back(turma);
}