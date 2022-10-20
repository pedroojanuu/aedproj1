#include "Slot.h"

using namespace std;

Slot::Slot(const string& dia, float horaInicio, float duracao, const string& tipo) {
    dia_ = dia;
    horaInicio_ = horaInicio;
    duracao_ = duracao;
    tipo_ = tipo;
}
