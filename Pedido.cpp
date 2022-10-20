#include "Pedido.h"

Pedido::Pedido(const Student &pedinte, const vector<UCTurma> &a_remover, const vector<UCTurma> &a_adicionar) {
    pedinte_ = pedinte;
    a_remover_ = a_remover;
    a_adicionar_ = a_adicionar;
}
