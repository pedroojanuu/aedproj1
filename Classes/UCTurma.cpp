#include <iostream>
#include "UCTurma.h"

UCTurma::UCTurma(const string& codUC, const string& codTurma) {
    codUC_ = codUC;
    codTurma_ = codTurma;
    size = 0;
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
    cout << codTurma_ << ',' << codUC_ << ',' << size << endl;
    for (int i = 0; i < horarioUCTurma.size(); i++) {
        horarioUCTurma[i].print();
    }
}

bool UCTurma::operator<(const UCTurma& turma) const {
    if (codUC_ == turma.codUC_) return codTurma_ < turma.codTurma_;
    return codUC_ < turma.codUC_;
}

void UCTurma::incrementSize() {
    size++;
}

void UCTurma::decrementSize() {
    size--;
}

int UCTurma::getSize() const{
    return size;
}

void UCTurma::loadSlots(GestaoHor& g) const {
    for (Slot slot : horarioUCTurma) {
        pair<string,string> a {codUC_, codTurma_};
        pair<Slot, pair<string,string>> p {slot, a};
        g.addPairSchedule(p);
    }
}
