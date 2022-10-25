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