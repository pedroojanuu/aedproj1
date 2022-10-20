#include "Student.h"

Student::Student() {
    studentCode_ = 0;
    studentName_ = nullptr;
}

Student::Student(int code, const std::string& name) {
    studentCode_ = code;
    studentName_ = name;
}
