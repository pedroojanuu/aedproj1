#ifndef AED_PROJ1_GESTAOHOR_H
#define AED_PROJ1_GESTAOHOR_H

#include "Student.h"
#include "Pedido.h"
#include <set>
#include <queue>

using namespace std;

class GestaoHor {
public:
    GestaoHor();
    // void readUC();
    void readStudents();
    void readUCTurma();
    void print() const;
private:
    vector<Student> estudantes;
    vector<UCTurma> aulas;
    vector<UCTurma> horario;
    queue<Pedido> pedidos;
};


#endif //AED_PROJ1_GESTAOHOR_H
