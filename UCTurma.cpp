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
