#ifndef AED_PROJ1_PEDIDO_H
#define AED_PROJ1_PEDIDO_H

#include "Student.h"

using namespace std;

class Pedido {
public:
    Pedido(const Student& pedinte, const vector<UCTurma>& a_remover, const vector<UCTurma>& a_adicionar);
private:
    Student pedinte_;
    vector<UCTurma> a_remover_;
    vector<UCTurma> a_adicionar_;
};


#endif //AED_PROJ1_PEDIDO_H
