#include "Pedido.h"

Pedido::Pedido(int n, short option, const pair<string,string> & adding, const pair<string,string> & removing) {
    n_ = n;
    option_ = option;
    adding_ = adding;
    removing_ = removing;
}

short Pedido::getOption() {
    return option_;
}

pair<string,string> Pedido::getAdding() {
    return adding_;
}

pair<string, string> Pedido::getRemoving() {
    return removing_;
}
