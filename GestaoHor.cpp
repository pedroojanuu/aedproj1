#include <iostream>
#include <fstream>
#include <sstream>

#include "GestaoHor.h"

using namespace std;

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
}

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
        istringstream ss(startHour);
        ss >> startHourFloat;
        getline(iss, duration, ',');
        ss.str(duration);
        ss >> durationFloat;
        Slot slot = Slot(weekday, startHourFloat, durationFloat, type);

        if (aulas.back().getUC() != ucCode || aulas.empty()) {
            UCTurma ucTurma = UCTurma(ucCode, classCode);
            ucTurma.addSlot(slot);
            aulas.push_back(ucTurma);
        } else {
            int i;
            for (i = aulas.size() - 1; aulas.at(i).getUC() == ucCode || i != -1; i--) {
                if (aulas.at(i).getTurma() == classCode) {
                    aulas.at(i).addSlot(slot);
                    break;
                }
            }
            if (aulas.at(i).getUC() != ucCode || i == -1) {
                UCTurma ucTurma = UCTurma(ucCode, classCode);
                ucTurma.addSlot(slot);
                aulas.push_back(ucTurma);
            }
        }
    }
}
