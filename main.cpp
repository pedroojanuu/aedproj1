#include <iostream>
#include <fstream>

#include "Classes/GestaoHor.h"

using namespace std;

/**
 * @file
 * vfivhvhjkvyubvf
 */

bool is_number(const string& s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void makePedido(GestaoHor& gestaoHor) {
    int option;
    cout << "O seu pedido sera colocado numa fila e processado no fecho do programa (opcao 0 do menu principal). "
            "Recebera informacao se o seu pedido nao for aceite.\n\n"
            "Selecionar opcao (premir ENTER):\n"
            "1 - Inscrever estudante em turma\n"
            "2 - Remover estudante de turma\n"
            "3 - Trocar estudante de turma numa dada UC\n"
            "0 - Menu anterior" << endl;
    cin >> option; cout << '\n';
    string n;
    string uc, adding, removing;
    switch (option) {
        case 1:
            cout << "Introduza o numero mecanografico" << endl; cin >> n; cout << '\n';
            if(n.length() != 9 || !is_number(n)) {
                cout << "Numero invalido. Por favor, tente novamente." << endl;
                return;
            }
            cout << "Introduza o codigo da UC a que deseja adicionar (no formato L.EICXXX)" << endl; cin >> uc; cout << '\n';
            if (uc.length() != 8 || uc.substr(0,5) != "L.EIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o codigo da Turma a que deseja adicionar (no formato XLEICXX)" << endl; cin >> adding; cout << '\n';
            if (adding.length() != 7 || adding.substr(1,4) != "LEIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            gestaoHor.addPedido(Pedido(stoi(n), 1, make_pair(uc,adding)));
            break;
        case 2:
            if(n.length() != 9 || !is_number(n)) {
                cout << "Numero invalido. Por favor, tente novamente." << endl;
                return;
            }
            cout << "Introduza o codigo da UC de que deseja remover (no formato L.EICXXX)" << endl; cin >> uc; cout << '\n';
            if (uc.length() != 8 || uc.substr(0,5) != "L.EIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o codigo da Turma de que deseja remover (no formato XLEICXX)" << endl; cin >> removing; cout << '\n';
            if (removing.length() != 7 || removing.substr(1,4) != "LEIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            gestaoHor.addPedido(Pedido(stoi(n), 2,make_pair("","") ,make_pair(uc,removing)));
            break;
        case 3:
            cout << "Introduza o numero mecanografico" << endl; cin >> n; cout << '\n';
            if(n.length() != 9 || !is_number(n)) {
                cout << "Numero invalido. Por favor, tente novamente." << endl;
                return;
            }
            cout << "Introduza o codigo da UC que deseja substituir (no formato L.EICXXX)" << endl; cin >> uc; cout << '\n';
            if (uc.length() != 8 || uc.substr(0,5) != "L.EIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o codigo da Turma a que deseja adicionar (no formato XLEICXX)" << endl; cin >> adding; cout << '\n';
            if (adding.length() != 7 || adding.substr(1,4) != "LEIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o codigo da Turma de que deseja remover (no formato XLEICXX)" << endl; cin >> removing; cout << '\n';
            if (removing.length() != 7 || removing.substr(1,4) != "LEIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            gestaoHor.addPedido(Pedido(stoi(n), 3,make_pair(uc,adding) ,make_pair(uc,removing)));
            break;
        default:
            cout << "Opcao invalida. Por favor, tente novamente." << endl; cout << '\n';
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
            cout << " nao foram processados. Por favor, tente novamente.";
            cout << endl << '\n';
        } else {
            cout << "O pedido " << wrongRequests[0] << " nao foi processado. Por favor, tente novamente." << endl;
            cout << '\n';
        }
    }
}

void ocupacao(GestaoHor& gestaoHor) {
    string codUC, codTurma;
    cout << "Introduza o codigo da UC (no formato L.EICXXX)" << endl;
    cin >> codUC; cout << '\n';
    if (codUC.substr(0,5) != "L.EIC") {
        cout << "Codigo invalido. Por favor, tente novamente." << endl;
        cout << '\n';
        return;
    }
    cout << "Introduza o codigo da turma (no formato XLEICXX)" << endl;
    cin >> codTurma; cout << '\n';
    if (codTurma.substr(1,4) != "LEIC") {
        cout << "Codigo invalido. Por favor, tente novamente." << endl;
        cout << '\n';
        return;
    }
    gestaoHor.printOccupation(UCTurma(codUC, codTurma));
    cout << '\n';
}

void listagens(GestaoHor & gestaoHor) {
    int order;
    cout << "Listagem de estudantes com ordem e filtro\n"
            "Selecionar opcao (remir ENTER):\n"
            "1 - Ordenar por numero de estudante\n"
            "2 - Ordenar alfabeticamente\n"
            "0 - Menu anterior" << endl;
    cin >> order; cout << '\n';
    if (!order) return;
    if((order-1)) {
        gestaoHor.alphabeticOrder();
    } else {
        gestaoHor.numericOrder();
    }
    int option;
    cout << "Selecionar opcao (premir ENTER):\n"
            "1 - Todos os estudantes\n"
            "2 - Estudantes por ano\n"
            "3 - Estudantes por UC\n"
            "4 - Estudantes por turma de UC\n"
            "0 - Menu anterior" << endl;
    cin >> option; cout << '\n';
    int n;
    string year;
    string uc;
    string classCode;
    switch (option) {
        case 1:
            gestaoHor.printStudents(); cout << '\n';
            cout << "Existem " << gestaoHor.studentsSize() << " estudantes no total." << endl;
            break;
        case 2:
            cout << "Introduza o ano pretendido:\n";
            cin >> year;
            if (year.length()>1 || year[0] < '0' || year[0] > '3') {
                cout << "\nAno invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            n = gestaoHor.showStudentsByYear(year[0]); cout << '\n';
            cout << "Existem " << n << " estudantes inscritos no " << year << "º ano." << endl;
            break;
        case 3:
            cout << "Introduza o codigo da UC (no formato L.EICXXX)\n";
            cin >> uc; cout << '\n';
            if (uc.length() != 8 || uc.substr(0,5) != "L.EIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            n = gestaoHor.showStudentsByUC(uc); cout << '\n';
            cout << "Existem " << n <<  " estudantes inscritos nesta UC\n";
            break;
        case 4:
            cout << "Introduza o codigo da UC (no formato L.EICXXX)\n";
            cin >> uc; cout << '\n';
            if (uc.length() != 8 || uc.substr(0,5) != "L.EIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            cout << "Introduza o codigo da turma (no formato XLEICXX)\n";
            cin >> classCode; cout << '\n';
            if (classCode.length() != 7 || classCode.substr(1,4) != "LEIC") {
                cout << "Codigo invalido. Por favor, tente novamente." << endl;
                cout << '\n';
                return;
            }
            n = gestaoHor.showStudentsByClass(UCTurma(uc,classCode));
            cout << "Existem " << n << " estudantes inscritos nesta turma.\n";
            break;
        case 0:
            return;
        default:
            cout << "Opcao invalida. Por favor, tente novamente." << endl; cout << '\n';
    }
}

int main() {
    ofstream fout;
    fout.open("../changes.csv", ofstream::out | ofstream::trunc);
    fout << "StudentCode,StudentName,UcCode,ClassCode\n";
    fout.close();
    GestaoHor gestaoHor;
    gestaoHor.readUCTurma();
    gestaoHor.readStudents();
    bool exiting = false;
    while (!exiting) {
        cout << "\nSelecionar opcao (premir ENTER):\n"
                "1 - Consultar horario de estudante\n"
                "2 - Efetuar pedido de alteracao\n"
                "3 - Consultar ocupacao de uma dada turma de uma dada UC\n"
                "4 - Mostrar listagens\n"
                "0 - Sair e processar pedidos" << endl;
        int option;
        cin >> option; cout << '\n';
        string n;
        switch (option) {
            case 0:
                exiting = true;
                int def; cout << "Selecionar opcao (premir ENTER):\n"
                                 "1 - Guardar alteracoes num ficheiro a parte (changes.csv)\n"
                                 "2 - Tornar alteracoes definitivas\n"
                                 "0 - Verificar viabilidade das alteracoes e descarta-las\n";
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
                    default:
                        cout << "Opcao invalida. Por favor, tente novamente." << endl;
                }
                break;
            case 1:
                cout << "Introduza o numero mecanografico" << endl; cin >> n;
                cout << '\n';
                if(n.length() != 9 || !is_number(n)) {
                    cout << "Numero invalido. Por favor, tente novamente." << endl;
                    break;
                }
                gestaoHor.printSchedule(stoi(n)); break;
            case 2:
                makePedido(gestaoHor); break;
            case 3:
                ocupacao(gestaoHor); break;
            case 4:
                listagens(gestaoHor); break;
            default:
                cout << "Opcao invalida. Por favor, tente novamente." << endl;
        }
    }
    cout << "Adeus!" << endl;
}
