#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include "Class.h"

class Student {
public:
    Student(int code, const std::string& name);

private:
    int studentCode_;
    std::string studentName_;
    std::vector<Class> schedule_;
};


#endif //UNTITLED_STUDENT_H
