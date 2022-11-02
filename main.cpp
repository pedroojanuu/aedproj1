#include <iostream>

#include "Classes/GestaoHor.h"

using namespace std;

void makePedido(GestaoHor& gestaoHor) {
    int option;
    cout << "O seu pedido sera colocado numa fila e processado no fecho do programa (opcao 0 do menu principal). "
            "Recebera informacao sobre cada pedido, indicando se o mesmo foi aceite ou nao.\n\n"
            "Selecionar opcao (premir ENTER):\n"
            "1 - Inscrever estudante em turma\n"
            "2 - Remover estudante de turma\n"
            "3 - Trocar estudante de turma numa dada UC\n"
            "0 - Menu anterior" << endl;
    cin >> option; cout << '\n';
    int n;
    switch (option) {
        case 1:
            cout << "Introduza o numero de estudante." << endl; cin >> n; cout << '\n';
        case 2:
            cout << "Introduza o numero de estudante." << endl; cin >> n; cout << '\n';
        case 3:
            cout << "Introduza o numero de estudante." << endl; cin >> n; cout << '\n';
        default:
            cout << "Opcao invalida. Por favor, tente novamente." << endl;
        case 0:
            return;
    }
}

void ocupacao(GestaoHor& gestaoHor) {
    string codUC, codTurma;
    cout << "Introduza o codigo da UC (no formato L.EICXXX)" << endl;
    cin >> codUC;
    cout << "Introduza o codigo da turma (no formato XLEICXXX)" << endl;
    cin >> codTurma; cout << '\n';
    gestaoHor.printOccupation(UCTurma(codUC, codTurma));
    cout << '\n';
}

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
                ocupacao(gestaoHor); break;
            default:
                cout << "Opcao invalida. Por favor, tente novamente." << endl;
        }
    }
    cout << "Adeus!" << endl;
}
