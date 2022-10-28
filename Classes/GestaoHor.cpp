#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "GestaoHor.h"

using namespace std;

GestaoHor::GestaoHor() {

}

void GestaoHor::print() const {
    for (int i = 0; i < aulas.size(); i++) {
        aulas[i].print();
    }
    for (auto it = estudantes.begin(); it != estudantes.end(); it++) {
        it->print();
    }
}

//leitura de classes.csv/classes_per_uc.csv
void GestaoHor::readUCTurma() {
    ifstream in("classes.csv");


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

        if (aulas.empty() || aulas.back().getUC() != ucCode) {
            UCTurma ucTurma = UCTurma(ucCode, classCode);
            ucTurma.addSlot(slot);
            aulas.push_back(ucTurma);
        } else {
            int i = aulas.size() - 1;
            while (i != -1 && aulas.at(i).getUC() == ucCode) {
                if (aulas.at(i).getTurma() == classCode) {
                    aulas.at(i).addSlot(slot);
                    break;
                }
                i--;
            }
            if (i == -1 || aulas.at(i).getUC() != ucCode) {
                UCTurma ucTurma = UCTurma(ucCode, classCode);
                ucTurma.addSlot(slot);
                aulas.push_back(ucTurma);
            }
        }
    }
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
    }
    estudantes = set<Student>(temp.begin(), temp.end());
}

void GestaoHor::removeTurmaStudent(const Student &student, const UCTurma &turma) {
    auto pos = estudantes.find(student);
    Student tmp = *pos;
    tmp.removeTurma(turma);
}
