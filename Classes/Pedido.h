#ifndef AED_PROJ1_PEDIDO_H
#define AED_PROJ1_PEDIDO_H


#include "UCTurma.h"

class Pedido {
private:
    int n_;
    pair<string,string> adding_ = make_pair("","");
    pair<string,string> removing_ = make_pair("","");
    short option_; // 1 = add, 2 = remove, 3 = swap
public:
    Pedido(int n, short option, const pair<string,string>& adding = make_pair("",""), const pair<string,string>& removing = make_pair("",""));
    short getOption() const;
    pair<string,string> getAdding() const;
    pair<string,string> getRemoving() const;
    int getCode() const;
};


#endif //AED_PROJ1_PEDIDO_H
