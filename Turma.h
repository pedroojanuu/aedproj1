#ifndef UNTITLED_TURMA_H
#define UNTITLED_TURMA_H

#include <string>
#include <vector>

#include "Student.h"
#include "UC.h"

class Turma {
public:
    Turma(const std::string &code, const UC &uc);
private:
    std::string code_;
    UC uc_;
    static int capacity_; // qual o valor máximo??
    //std::vector<Student> students_;
};

#endif //UNTITLED_TURMA_H
