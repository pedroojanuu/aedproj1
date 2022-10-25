#include <iostream>
#include "UCTurma.h"

UCTurma::UCTurma(const string& codUC, const string& codTurma) {
    codUC_ = codUC;
    codTurma_ = codTurma;
}

string UCTurma::getUC() const {
    return codUC_;
}

string UCTurma::getTurma() const {
    return codTurma_;
}

void UCTurma::addSlot(const Slot &slot) {
    horarioUCTurma.push_back(slot);
}

void UCTurma::print() const {
    cout << codTurma_ << ',' << codUC_ << endl;
    for (int i = 0; i < horarioUCTurma.size(); i++) {
        horarioUCTurma[i].print();
    }
}
