#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "GestaoHor.h"

using namespace std;

GestaoHor::GestaoHor() {

}

void GestaoHor::print() const {
    for (auto it = aulas.begin(); it != aulas.end(); it++) {
        it->print();
    }
    for (auto it = estudantes.begin(); it != estudantes.end(); it++) {
        it->print();
    }
}

//leitura de classes.csv/classes_per_uc.csv
void GestaoHor::readUCTurma() {
    ifstream in("classes.csv");
    vector<UCTurma> aux;

    string line;
    getline(in, line);

    while (getline(in, line)) {
        string classCode, ucCode, weekday, startHour, duration, type;
        float startHourFloat, durationFloat;
        istringstream iss(line);
        getline(iss, classCode, ',');
        getline(iss, ucCode, ',');
        getline(iss, weekday, ',');
        getline(iss, startHour, ',');
        istringstream sh(startHour);
        sh >> startHourFloat;
        getline(iss, duration, ',');
        istringstream du(duration);
        du >> durationFloat;
        getline(iss, type);
        Slot slot = Slot(weekday, startHourFloat, durationFloat, type);

        if (aux.empty() || aux.back().getUC() != ucCode) {
            UCTurma ucTurma = UCTurma(ucCode, classCode);
            ucTurma.addSlot(slot);
            aux.push_back(ucTurma);
        } else {
            int i = aux.size() - 1;
            while (i != -1 && aux.at(i).getUC() == ucCode) {
                if (aux.at(i).getTurma() == classCode) {
                    aux.at(i).addSlot(slot);
                    break;
                }
                i--;
            }
            if (i == -1 || aux.at(i).getUC() != ucCode) {
                UCTurma ucTurma = UCTurma(ucCode, classCode);
                ucTurma.addSlot(slot);
                aux.push_back(ucTurma);
            }
        }
    }
    aulas = set<UCTurma>(aux.begin(), aux.end());
}

// leitura de students_classes.csv
void GestaoHor::readStudents() {
    ifstream in("students_classes.csv");
    string line;
    getline(in, line);

    vector<Student> temp;

    while (getline(in, line)) {
        string StudentCode, StudentName, UcCode, ClassCode;
        int StudentCodeInt;
        istringstream iss(line);
        getline(iss, StudentCode, ',');
        getline(iss, StudentName, ',');
        getline(iss, UcCode, ',');
        getline(iss, ClassCode, ',');
        istringstream sc(StudentCode);
        sc >> StudentCodeInt;
        UCTurma ucTurma = UCTurma(UcCode, ClassCode);

        if (temp.empty() || temp.back().getCode() != StudentCodeInt) {
            Student student = Student(StudentCodeInt, StudentName);
            student.addTurma(ucTurma);
            temp.push_back(student);
        } else {
            temp.back().addTurma(ucTurma);
        }
        auto pos = aulas.find(ucTurma);
        UCTurma sub = *pos;
        sub.incrementSize();
        aulas.erase(pos);
        aulas.insert(sub);
    }
    estudantes = set<Student>(temp.begin(), temp.end());
    //copy(temp.begin(),temp.end(),inserter(estudantes,estudantes.end()));
}

bool GestaoHor::removeTurmaStudent(const Student &student, const UCTurma &turma) {
    auto posTurma = aulas.find(turma);
    if (posTurma == aulas.end()) {
        return false;
    }
    UCTurma sub = *posTurma;
    sub.decrementSize();
    aulas.erase(posTurma);
    aulas.insert(sub);
    auto posStudent = estudantes.find(student);
    if (posStudent == estudantes.end()) {
        return false;
    }
    Student tmp = *posStudent;
    tmp.removeTurma(turma);
    estudantes.erase(posStudent);
    estudantes.insert(tmp);
    return true;
}
bool GestaoHor::addTurmaStudent(const Student &student, const UCTurma &turma) {
    auto posTurma = aulas.find(turma);
    if (posTurma == aulas.end() || posTurma->getSize() >= 30) {
        return false;
    }
    UCTurma sub = *posTurma;
    sub.incrementSize();
    aulas.erase(posTurma);
    aulas.insert(sub);auto posStudent = estudantes.find(student);
    if (posStudent == estudantes.end()) {
        return false;
    }
    Student tmp = *posStudent;
    tmp.addTurma(turma);
    estudantes.erase(posStudent);
    estudantes.insert(tmp);
    return true;
}
