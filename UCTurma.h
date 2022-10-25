#ifndef AED_PROJ1_UCTURMA_H
#define AED_PROJ1_UCTURMA_H

#include <string>
#include <vector>
#include "Slot.h"

using namespace std;

class UCTurma {
public:
    UCTurma(const string& codUC, const string& codTurma);
    string getUC() const;
    string getTurma() const;
    void addSlot (const Slot& slot);
    void print() const;
private:
    string codUC_, codTurma_;
    vector<Slot> horarioUCTurma;
};

#endif //AED_PROJ1_UCTURMA_H
