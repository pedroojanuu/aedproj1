#include <iostream>
#include <fstream>

#include "Classes/GestaoHor.h"

/**
 * @file
 * main.cpp contains the code where the program starts running.\n
 * Contains the UI menus and auxiliary functions that are not methods of any class.
 */

using namespace std;


/**
 * Returns whether a string is a number (all of it's characters are digits) or not.\n
 * Complexity: O(n), being \a n the length of the string.
 */
bool is_number(const string& s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/**
 * Receives a GestaoHor object and, providing a part of the UI, verifies if the contents of the request are valid
 * (if the UC and class codes are valid, for example) and calls GestaoHor::addPedido() to load the request.
 */
void makePedido(GestaoHor& gestaoHor) {
    string option;
    cout << "O seu pedido sera colocado numa fila e processado no fecho do programa (opcao 0 do menu principal). "
            "Recebera informacao se o seu pedido nao for aceite.\n\n"
            "Selecionar opcao (premir ENTER):\n"
            "1 - Inscrever estudante em turma\n"
            "2 - Remover estudante de turma\n"
            "3 - Trocar estudante de turma numa dada UC\n"
            "0 - Menu anterior" << endl;
    cin >> option; cout << '\n';
    if(option.length() != 1 || !isdigit(option[0])) {
        cout << "Opcao invalida. Por favor, tente novamente." << endl;
        return;
    }
    string n;
    string uc, adding, removing;
    switch (stoi(option)) {
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
            cout << "Introduza o numero mecanografico" << endl; cin >> n; cout << '\n';
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
            cout << "Introduza o codigo da Turma de que deseja remover (no formato XLEICXX)" << endl; cin >> removing; cout << '\n';
            if (removing.length() != 7 || removing.substr(1,4) != "LEIC") {
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
            gestaoHor.addPedido(Pedido(stoi(n), 3,make_pair(uc,adding) ,make_pair(uc,removing)));
            break;
        default:
            cout << "Opcao invalida. Por favor, tente novamente." << endl; cout << '\n';
        case 0:
            return;
    }
}

/**
 * Receives a GestaoHor object and a boolean (\b true if the user wants to make the changes definitive or process them
 * but discard them, \b false if they want them to be written on a separate file).\n
 * While requests are being processed, the function creates a vector with the indexes of the requests that were not
 * accepted and, implementing part of the UI, informs the user about the requests that could not be accepted.\n
 * Complexity: O(n²), being \a n the number of requests.
 */
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

/**
 * Receives a GestaoHor object and, implementing part of the UI, asks the user for a UC and a class and prints its
 * occupation through GestaoHor::printOccupation(). Verifies if the provided UC and class codes are valid.\n
 * Complexity: O(log n), being \a n the total number of classes (size of field \a aulas of the GestaoHor object).
 */
void ocupacao(GestaoHor& gestaoHor) {
    string codUC, codTurma;
    cout << "Introduza o codigo da UC (no formato L.EICXXX)" << endl;
    cin >> codUC; cout << '\n';
    if (codUC.length() != 8 ||codUC.substr(0,5) != "L.EIC") {
        cout << "Codigo invalido. Por favor, tente novamente." << endl;
        cout << '\n';
        return;
    }
    cout << "Introduza o codigo da turma (no formato XLEICXX)" << endl;
    cin >> codTurma; cout << '\n';
    if (codTurma.length() != 7 ||codTurma.substr(1,4) != "LEIC") {
        cout << "Codigo invalido. Por favor, tente novamente." << endl;
        cout << '\n';
        return;
    }
    gestaoHor.printOccupation(UCTurma(codUC, codTurma));
    cout << '\n';
}

/**
 * Receives a GestaoHor object and, implementing part of the UI, provides various listings and prints them to the user.\n
 * Verifies validity of user inputs.\n
 * Complexity: O(n log(n)), being \a n the number of existing students (field estudantes of GestaoHor object).
 */
void listagens(GestaoHor & gestaoHor) {
    string order;
    cout << "Listagem de estudantes com ordem e filtro\n"
            "Selecionar opcao (remir ENTER):\n"
            "1 - Ordenar por numero de estudante\n"
            "2 - Ordenar alfabeticamente\n"
            "0 - Menu anterior" << endl;
    cin >> order; cout << '\n';
    if(order.length() != 1 || !isdigit(order[0])) {
        cout << "Opcao invalida. Por favor, tente novamente." << endl;
        return;
    }
    if (!stoi(order)) return;
    if((stoi(order) == 2)) {
        gestaoHor.alphabeticOrder();
    } else if (stoi(order) == 1){
        gestaoHor.numericOrder();
    }
    else {
        cout << "Opcao invalida. Por favor, tente novamente." << endl; cout << '\n';
    }
    string option;
    cout << "Selecionar opcao (premir ENTER):\n"
            "1 - Todos os estudantes\n"
            "2 - Estudantes por ano\n"
            "3 - Estudantes por UC\n"
            "4 - Estudantes por turma de UC\n"
            "0 - Menu anterior" << endl;
    cin >> option; cout << '\n';
    if(option.length() != 1 || !isdigit(option[0])) {
        cout << "Opcao invalida. Por favor, tente novamente." << endl;
        return;
    }
    int n;
    string year;
    string uc;
    string classCode;
    switch (stoi(option)) {
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

/**
 * Where the program starts executing. Implements the main menu of the UI, calls GestaoHor::GestaoHor(),
 * GestaoHor::readStudents() and GestaoHor::readUCTurma(), which load all the data into the program.\n
 * Manages the creation of file changes.csv, which has the purpose of saving changes (if the user wnats to).
 */
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
        string option;
        cin >> option; cout << '\n';
        if(option.length() != 1 || !isdigit(option[0])) {
            cout << "Opcao invalida. Por favor, tente novamente." << endl;
            continue;
        }
        string n;
        switch (stoi(option)) {
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
                cout << "Numero invalido. Por favor, tente novamente." << endl;
        }
    }
    cout << "Adeus!" << endl;
}
