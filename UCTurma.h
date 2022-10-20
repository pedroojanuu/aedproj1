#ifndef AED_PROJ1_UCTURMA_H
#define AED_PROJ1_UCTURMA_H

#include <string>
#include <vector>
#include "Slot.h"

using namespace std;

class UCTurma {
public:
    UCTurma(const string& codUC, const string& codTurma);
private:
    string codUC_, codTurma_;
    vector<Slot> horarioUCTurma;
};

#endif //AED_PROJ1_UCTURMA_H
