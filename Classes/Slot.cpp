#include "Slot.h"
#include <iostream>

using namespace std;

Slot::Slot(const string& dia, float horaInicio, float duracao, const string& tipo) {
    dia_ = dia;
    horaInicio_ = horaInicio;
    duracao_ = duracao;
    tipo_ = tipo;
}

void Slot::print() const {
    cout << "       " << dia_ << ',' << tipo_ << ',' << duracao_ << ',' << horaInicio_ << endl;
}

bool Slot::operator<(const Slot &slot) const {
    if (dia_ == slot.dia_) {
        if (horaInicio_ == slot.horaInicio_) return duracao_ < slot.duracao_;
        return horaInicio_ < slot.horaInicio_;
    }
    if (dia_ == "Monday") return (slot.dia_ == "Tuesday" || slot.dia_ == "Wednesday" || slot.dia_ == "Thursday" || slot.dia_ == "Friday" || slot.dia_ == "Saturday");
    if (dia_ == "Tuesday") return (slot.dia_ == "Wednesday" || slot.dia_ == "Thursday" || slot.dia_ == "Friday" || slot.dia_ == "Saturday");
    if (dia_ == "Wednesday") return (slot.dia_ == "Thursday" || slot.dia_ == "Friday" || slot.dia_ == "Saturday");
    if (dia_ == "Thursday") return (slot.dia_ == "Friday" || slot.dia_ == "Saturday");
    return slot.dia_ == "Saturday";
}

string Slot::getDay() const {
    return dia_;
}

string Slot::getType() const {
    return tipo_;
}

float Slot::getHour() const {
    return horaInicio_;
}

float Slot::getDuration() const {
    return duracao_;
}
