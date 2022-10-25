#include <iostream>
#include <fstream>
#include <sstream>

#include "GestaoHor.h"

using namespace std;

GestaoHor::GestaoHor() {

}

/*
void readStudents() {
    ifstream in1("classes.csv");
    ifstream in2("classes_per_uc.csv");
    ifstream in3("students_classes.csv");

    vector<Student> students;
    vector<UC> ucs;
    vector<Turma> turmas;
    vector<Class> classes;

    string line;
    getline(in1, line);

    while (getline(in1, line)) {

        istringstream iss(line);
        getline(iss, ClassCode, ',');
        getline(iss, UcCode, ',');
        getline(iss, Weekday, ',');
        getline(iss, StartHour, ',');
        istringstream ss (StartHour);
        ss >> StartHourFloat;
        getline(iss, Duration, ',');
        ss.str(Duration);
        ss >> DurationFloat;

        classes.push_back(Class(ClassCode, UcCode, Weekday, StartHourFloat, DurationFloat, Type));
    }
}*/

void GestaoHor::print() {
    for (int i = 0; i < aulas.size(); i++) {
        aulas[i].print();
    }
}

//leitura de classes.csv
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
