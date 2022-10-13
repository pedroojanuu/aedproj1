#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H

#include <string>

#include "Turma.h"

class Class {
public:
    Class(const Turma& turma, const UC& uc, const std::string& day, int startHour, int duration, const std::string& type);
private:
    Turma turma_;
    UC uc_;
    std::string day_;
    float startHour_;
    float duration_;
    std::string type_;
};

#endif //UNTITLED_CLASS_H
