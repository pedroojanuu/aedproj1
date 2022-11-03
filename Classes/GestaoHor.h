#ifndef AED_PROJ1_GESTAOHOR_H
#define AED_PROJ1_GESTAOHOR_H


#include "Student.h"
#include "Pedido.h"
#include <set>
#include <queue>

using namespace std;

class Student;
class UCTurma;
class Pedido;

class GestaoHor {
public:
    GestaoHor();
    void readStudents();
    void readUCTurma();
    void printStudents() const;
    bool removeTurmaStudent(int n, const UCTurma& turma);
    bool addTurmaStudent(int n, const UCTurma& turma);
    bool swapTurmaStudent(int n, const UCTurma& removing, const UCTurma& adding);
    void addPairSchedule(const pair<Slot,pair<string,string>>& uc);
    void printSchedule(int n);
    void printOccupation(const UCTurma& ucTurma) const;
    const _Rb_tree_const_iterator<UCTurma> findUC(const UCTurma& ucTurma) const;
    bool isScheduleValid() const;
    void addPedido(const Pedido& pedido);
    bool processPedido(bool def);
    bool pedidosEmpty() const;
    void write() const;
    int showStudentsByYear(char year) const;
    int showStudentsByClass(const UCTurma &turma) const;
    int showStudentsByUC(string UC) const;
    void alphabeticOrder();
    void numericOrder();
    int studentsSize() const;


private:
    set<Student> estudantes;
    set<UCTurma> aulas;
    vector<Student> temp;
    vector<pair<Slot,pair<string,string>>> horario;
    queue<Pedido> pedidos;

};


#endif //AED_PROJ1_GESTAOHOR_H
