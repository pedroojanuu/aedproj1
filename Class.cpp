#include "Class.h"

Class::Class(const Turma &turma, const UC &uc, const std::string &day, int startHour, int duration,
             const std::string &type) {
    turma_ = turma;
    uc_ = uc;
    day_ = day;
    startHour_ = startHour;
    duration_ = duration;
    type_ = type;
}
