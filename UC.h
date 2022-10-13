#ifndef UNTITLED_UC_H
#define UNTITLED_UC_H

#include <vector>
#include <string>

#include "Student.h"


class UC {
public:
    UC(const std::string& code);
private:
    std::string code_;
    std::vector<Student> students_;
};


#endif //UNTITLED_UC_H