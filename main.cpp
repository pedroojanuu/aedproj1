#include <iostream>

#include "Classes/GestaoHor.h"

using namespace std;

int main() {
    GestaoHor gestaoHor;
    gestaoHor.readUCTurma();
    gestaoHor.readStudents();
    //gestaoHor.print();
    int n;
    cin >> n;
    gestaoHor.printSchedule(n);
}
