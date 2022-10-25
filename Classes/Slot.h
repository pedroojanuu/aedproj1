#ifndef AED_PROJ1_SLOT_H
#define AED_PROJ1_SLOT_H

#include <string>

using namespace std;

class Slot {
public:
    Slot(const string& dia, float horaInicio, float duracao, const string& tipo);
    void print() const;
private:
    string dia_, tipo_;
    float horaInicio_, duracao_;
};


#endif //AED_PROJ1_SLOT_H
