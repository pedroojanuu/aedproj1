#include <iostream>

#include "Classes/GestaoHor.h"

using namespace std;

void makePedido(GestaoHor& gestaoHor) {
    int option;
    cout << "Selecionar opcao (premir ENTER):\n"
            "1 - Inscrever estudante em turma\n"
            "2 - Remover estudante de turma\n"
            "3 - Trocar estudante de turma numa dada UC\n"
            "0 - Menu anterior" << endl;
    cin >> option; cout << '\n';
    switch (option) {
        case 1:
        case 2:
        case 3:
        default:
            cout << "Opcao invalida. Por favor, tente novamente." << endl;
        case 0:
            return;
    }
}

/*
void ocupacao(GestaoHor& gestaoHor) {
    UCTurma ucTurma = UCTurma()
}*/

int main() {
    GestaoHor gestaoHor;
    gestaoHor.readUCTurma();
    gestaoHor.readStudents();
    //gestaoHor.print();
    bool exiting = false;
    while (!exiting) {
        cout << "Selecionar opcao (premir ENTER):\n"
                "1 - Consultar horario de estudante\n"
                "2 - Efetuar pedido\n"
                "3 - Consultar ocupacao\n"
                "0 - Sair e processar pedidos" << endl;
        int option;
        cin >> option; cout << '\n';
        switch (option) {
            case 0:
                exiting = true;
                break;
            case 1:
                int n; cout << "Introduza o numero mecanografico" << endl; cin >> n;
                gestaoHor.printSchedule(n); break;
            case 2:
                makePedido(gestaoHor); break;
            case 3:
                //ocupacao(gestaoHor); break;
            default:
                cout << "Opcao invalida. Por favor, tente novamente." << endl;
        }
    }
    cout << "Adeus!" << endl;
}
