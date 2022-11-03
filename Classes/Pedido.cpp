#include "Pedido.h"

Pedido::Pedido(int n, short option, const pair<string,string> & adding, const pair<string,string> & removing) {
    n_ = n;
    option_ = option;
    adding_ = adding;
    removing_ = removing;
}

short Pedido::getOption() const {
    return option_;
}

pair<string,string> Pedido::getAdding() const {
    return adding_;
}

pair<string, string> Pedido::getRemoving() const {
    return removing_;
}

int Pedido::getCode() const {
    return n_;
}
