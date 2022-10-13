#include <iostream>
#include <fstream>
#include <sstream>

#include "Student.h"
#include "UC.h"
#include "Turma.h"
#include "Class.h"

using namespace std;

void readData() {
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
        string ClassCode, UcCode, Weekday, StartHour, Duration, Type;
        float StartHourFloat, DurationFloat;
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
    }*/
}

int main() {
    readData();
}
