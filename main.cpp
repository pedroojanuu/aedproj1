#include <iostream>

#include "Classes/GestaoHor.h"

using namespace std;

int main() {
    cout << "A ler dados..." << endl;
    GestaoHor gestaoHor;
    gestaoHor.readUCTurma();
    gestaoHor.readStudents();
    gestaoHor.print();
    cout << "Dados lidos." << endl;
}
