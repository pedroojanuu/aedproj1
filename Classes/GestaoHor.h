#ifndef AED_PROJ1_GESTAOHOR_H
#define AED_PROJ1_GESTAOHOR_H

/*! \mainpage Projeto 1 AED
* This is a tender for the first practical assignment of the
* course Algoritmos e Estruturas de Dados of the Licenciatura em Engenharia
* Informática e Computação of the Faculty of Engineering of the University of Porto
* and the Faculty of Sciences of the University of Porto.
* It was made by the students João das Neves Fernandes (202108867)
* (up202108867@edu.fe.up.pt) and
* Pedro Simão Januário Vieira (202108768) (up202108768@edu.fe.up.pt), both belonging to Group No. 10, from class 2LEIC01.
*/

#include "Student.h"
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
    void print() const;
    bool removeTurmaStudent(const Student& student, const UCTurma& turma);
    bool addTurmaStudent(const Student& student, const UCTurma& turma);
    bool swapTurmaStudent(const Student& student, const UCTurma& removing, const UCTurma& adding);
    void addPairSchedule(const pair<Slot,string>& uc);
    void printSchedule(int n);
    const _Rb_tree_const_iterator<UCTurma> findUC(const UCTurma& ucTurma) const;
private:
    set<Student> estudantes;
    set<UCTurma> aulas;
    vector<pair<Slot,string>> horario;
    //queue<Pedido> pedidos;
};


#endif //AED_PROJ1_GESTAOHOR_H
