#include <iostream>

#include "Classes/GestaoHor.h"
#include <fstream>

using namespace std;


void makePedido(GestaoHor& gestaoHor) {
    int option;
    cout << "O seu pedido será colocado numa fila e processado no fecho do programa (opção 0 do menu principal). "
            "Receberá informação se o seu pedido não for aceite.\n\n"
            "Selecionar opção (premir ENTER):\n"
            "1 - Inscrever estudante em turma\n"
            "2 - Remover estudante de turma\n"
            "3 - Trocar estudante de turma numa dada UC\n"
            "0 - Menu anterior" << endl;
    cin >> option; cout << '\n';
    int n;
    string uc, adding, removing;
    switch (option) {
        case 1:
            cout << "Introduza o número de estudante" << endl; cin >> n; cout << '\n';
            if(to_string(n).length() != 9) {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da UC que deseja adicionar (no formato L.EICXXX)" << endl; cin >> uc; cout << '\n';
            if (uc.substr(0,5) != "L.EIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da Turma que deseja adicionar (no formato XLEICXXX)" << endl; cin >> adding; cout << '\n';
            if (adding.substr(1,4) != "LEIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            gestaoHor.addPedido(Pedido(n, 1, make_pair(uc,adding)));
            break;
        case 2:
            cout << "Introduza o número de estudante" << endl; cin >> n; cout << '\n';
            if(to_string(n).length() != 9) {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da UC que deseja remover (no formato L.EICXXX)" << endl; cin >> uc; cout << '\n';
            if (uc.substr(0,5) != "L.EIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da Turma que deseja remover (no formato XLEICXXX)" << endl; cin >> removing; cout << '\n';
            if (removing.substr(1,4) != "LEIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            gestaoHor.addPedido(Pedido(n, 2,make_pair("","") ,make_pair(uc,removing)));
            break;
        case 3:
            cout << "Introduza o número de estudante" << endl; cin >> n; cout << '\n';
            if(to_string(n).length() != 9) {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da UC que deseja adicionar (no formato L.EICXXX)" << endl; cin >> uc; cout << '\n';
            if (uc.substr(0,5) != "L.EIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da Turma que deseja adicionar (no formato XLEICXXX)" << endl; cin >> adding; cout << '\n';
            if (adding.substr(1,4) != "LEIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da UC que deseja remover (no formato L.EICXXX)" << endl; cin >> uc; cout << '\n';
            if (uc.substr(0,5) != "L.EIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o código da Turma que deseja remover (no formato XLEICXXX)" << endl; cin >> removing; cout << '\n';
            if (removing.substr(1,4) != "LEIC") {
                cout << "Código inválido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            gestaoHor.addPedido(Pedido(n, 3,make_pair(uc,adding) ,make_pair(uc,removing)));
            break;
        default:
            cout << "Opção inválida. Por favor, tente novamente." << endl; cout << '\n';
        case 0:
            return;
    }
}

void readPedidos(GestaoHor& gestaoHor, bool def) {
    if(gestaoHor.pedidosEmpty()) return;
    int counter = 0;
    vector<int> wrongRequests;
    while(!gestaoHor.pedidosEmpty()) {
        counter ++;
        if(!gestaoHor.processPedido(def)) {
            wrongRequests.push_back(counter);
        }
    }
    if (!wrongRequests.empty()) {
        if (wrongRequests.size() > 1) {
            cout << "Os pedidos ";
            for (int i = 0; i < wrongRequests.size() - 2; i++) {
                cout << wrongRequests[i] << ", ";
            }
            cout << wrongRequests[wrongRequests.size() - 2] << " e " << wrongRequests[wrongRequests.size() - 1];
            cout << " não foram processados. Por favor, tente novamente.";
            cout << endl << '\n';
        } else {
            cout << "O pedido " << wrongRequests[0] << " não foi processado. Por favor, tente novamente." << endl;
            cout << '\n';
        }
    }
}

void ocupacao(GestaoHor& gestaoHor) {
    string codUC, codTurma;
    cout << "Introduza o código da UC (no formato L.EICXXX)" << endl;
    cin >> codUC; cout << '\n';
    if (codUC.substr(0,5) != "L.EIC") {
        cout << "Código inválido. Por favor, tente novamente." << endl;
        cout << '\n';
        return;
    }
    cout << "Introduza o código da turma (no formato XLEICXXX)" << endl;
    cin >> codTurma; cout << '\n';
    if (codTurma.substr(1,4) != "LEIC") {
        cout << "Código inválido. Por favor, tente novamente." << endl;
        cout << '\n';
        return;
    }
    gestaoHor.printOccupation(UCTurma(codUC, codTurma));
    cout << '\n';
}

int main() {
    ofstream fout;
    fout.open("../changes.csv", ofstream::out | ofstream::trunc);
    fout.close();
    GestaoHor gestaoHor;
    gestaoHor.readUCTurma();
    gestaoHor.readStudents();
    bool exiting = false;
    while (!exiting) {
        cout << "Selecionar opção (premir ENTER):\n"
                "1 - Consultar horário de estudante\n"
                "2 - Efetuar pedido\n"
                "3 - Consultar ocupação\n"
                "0 - Sair e processar pedidos" << endl;
        int option;
        cin >> option; cout << '\n';
        switch (option) {
            case 0:
                exiting = true;
                int def; cout << "Selecionar opcao (premir ENTER):\n"
                                 "1 - Guardar alteracoes num ficheiro a parte\n"
                                 "2 - Tornar alteracoes definitivas\n"
                                 "0 - Descartar alteracoes\n";
                cin >> def; cout << '\n';
                switch (def) {
                    case 0:
                        readPedidos(gestaoHor,true);
                        break;
                    case 1:
                        readPedidos(gestaoHor, false);
                        break;
                    case 2:
                        readPedidos(gestaoHor, true);
                        gestaoHor.write();
                        break;
                }
                break;
            case 1:
                int n; cout << "Introduza o número mecanográfico" << endl; cin >> n;
                cout << '\n';
                gestaoHor.printSchedule(n); break;
            case 2:
                makePedido(gestaoHor); break;
            case 3:
                ocupacao(gestaoHor); break;
            default:
                cout << "Opção inválida. Por favor, tente novamente." << endl;
        }
    }
    cout << "Adeus!" << endl;
}
