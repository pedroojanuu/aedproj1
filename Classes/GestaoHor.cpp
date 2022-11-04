#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "GestaoHor.h"

using namespace std;

GestaoHor::GestaoHor() {

}

void GestaoHor::printStudents() const {
    cout << "StudentCode | StudentName" << endl;
    for (auto it = roll.begin(); it != roll.end(); it++) {
        it->print();
    }
}

void GestaoHor::readUCTurma() {
    ifstream in("classes.csv");
    vector<UCTurma> aux;

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
        startHourFloat = stof(startHour);
        getline(iss, duration, ',');
        durationFloat = stof(duration);
        getline(iss, type);
        Slot slot = Slot(weekday, startHourFloat, durationFloat, type);

        if (aux.empty() || aux.back().getUC() != ucCode) {
            UCTurma ucTurma = UCTurma(ucCode, classCode);
            ucTurma.addSlot(slot);
            aux.push_back(ucTurma);
        } else {
            int i = aux.size() - 1;
            while (i != -1 && aux.at(i).getUC() == ucCode) {
                if (aux.at(i).getTurma() == classCode) {
                    aux.at(i).addSlot(slot);
                    break;
                }
                i--;
            }
            if (i == -1 || aux.at(i).getUC() != ucCode) {
                UCTurma ucTurma = UCTurma(ucCode, classCode);
                ucTurma.addSlot(slot);
                aux.push_back(ucTurma);
            }
        }
    }
    aulas = set<UCTurma>(aux.begin(), aux.end());
}

void GestaoHor::readStudents() {
    vector<Student> temp;
    ifstream in("students_classes.csv");
    string line;
    getline(in, line);


    while (getline(in, line)) {
        string StudentCode, StudentName, UcCode, ClassCode;
        int StudentCodeInt;
        istringstream iss(line);
        getline(iss, StudentCode, ',');
        getline(iss, StudentName, ',');
        getline(iss, UcCode, ',');
        getline(iss, ClassCode, ',');
        StudentCodeInt = stoi(StudentCode);
        UCTurma ucTurma = UCTurma(UcCode, ClassCode);

        if (temp.empty() || temp.back().getCode() != StudentCodeInt) {
            Student student = Student(StudentCodeInt, StudentName);
            student.addTurma(ucTurma);
            temp.push_back(student);
        } else {
            temp.back().addTurma(ucTurma);
        }
        auto pos = aulas.find(ucTurma);
        if (pos != aulas.end()) {
            UCTurma sub = *pos;
            aulas.erase(pos);
            sub.incrementSize();
            aulas.insert(sub);
        }
    }
    estudantes = set<Student>(temp.begin(), temp.end());
}

bool GestaoHor::removeTurmaStudent(int n, const UCTurma &turma) {
    auto posTurma = aulas.find(turma);
    if (posTurma == aulas.end()) {
        return false;
    }
    auto posStudent = estudantes.find(Student(n,""));
    if (posStudent == estudantes.end()) {
        return false;
    }
    UCTurma sub = *posTurma;
    sub.decrementSize();
    aulas.erase(posTurma);
    aulas.insert(sub);
    Student tmp = *posStudent;
    if(!tmp.removeTurma(turma)) return false;
    estudantes.erase(posStudent);
    estudantes.insert(tmp);
    return true;
}

bool GestaoHor::addTurmaStudent(int n, const UCTurma &turma) {
    auto posTurma = aulas.find(turma);
    if (posTurma == aulas.end() || posTurma->getSize() >= 30) {
        return false;
    }
    for(auto itr = posTurma; itr != aulas.end() && itr->getUC() == turma.getUC(); itr++) {
        if (posTurma->getSize()+1 - itr->getSize() >= 4) {
            return false;
        }
    }
    for(auto itr = posTurma; itr != --aulas.begin() && itr->getUC() == turma.getUC(); itr--) {
        if (posTurma->getSize()+1 - itr->getSize() >= 4) {
            return false;
        }
    }
    Student student = Student(n, "");
    auto posStudent = estudantes.find(student);
    if (posStudent == estudantes.end()) {
        return false;
    }
    Student tmp = *posStudent;
    tmp.addTurma(turma);
    tmp.loadSchedule(*this);
    if (!isScheduleValid()) return false;
    UCTurma add = *posTurma;
    add.incrementSize();
    aulas.erase(posTurma);
    aulas.insert(add);
    estudantes.erase(posStudent);
    estudantes.insert(tmp);
    return true;
}

bool GestaoHor::swapTurmaStudent(int n, const UCTurma &removing, const UCTurma &adding) {
    auto removingitr = aulas.find(removing);
    auto addingitr = aulas.find(adding);
    if (removingitr == aulas.end() || addingitr == aulas.end() || addingitr->getSize() >= 30) {
        return false;
    }
    for(auto itr = addingitr; itr != aulas.end() && itr->getUC() == addingitr->getUC(); itr++) {
        if (addingitr->getSize()+1 - itr->getSize() >= 4) {
            return false;
        }
    }
    for(auto itr = addingitr; itr != --aulas.begin() && itr->getUC() == addingitr->getUC(); itr--) {
        if (addingitr->getSize()+1 - itr->getSize() >= 4) {
            return false;
        }
    }
    auto posStudent = estudantes.find(Student(n,""));
    if (posStudent == estudantes.end()) {
        return false;
    }
    Student tmp = *posStudent;
    if(!tmp.removeTurma(removing)) return false;
    tmp.addTurma(adding);
    tmp.loadSchedule(*this);
    if(!isScheduleValid()) return false;
    UCTurma sub = *removingitr;
    sub.decrementSize();
    aulas.erase(removingitr);
    aulas.insert(sub);
    UCTurma add = *addingitr;
    add.incrementSize();
    aulas.erase(removingitr);
    aulas.insert(add);
    estudantes.erase(posStudent);
    estudantes.insert(tmp);
    return true;
}

void GestaoHor::addPairSchedule(const pair<Slot,pair<string,string>>& uc) {
    horario.push_back(uc);
}

void GestaoHor::printSchedule(int n) {
    Student student = Student(n, "");
    auto pos = estudantes.find(student);
    if (pos == estudantes.end()) {cout << "Estudante nao encontrad@.\n\n"; return;}
    student = *pos;
    vector<pair<Slot,pair<string,string>>> h;
    horario = h;
    student.loadSchedule(*this);
    sort(horario.begin(), horario.end());
    cout << "\nHorario de " << student.getName() << "\n\n";
    for (pair<Slot,pair<string,string>> pair : horario) {
        cout << pair.second.first << ':' << pair.second.second << ':';
        pair.first.print();
    }
    cout << '\n';
}

const _Rb_tree_const_iterator<UCTurma> GestaoHor::findUC(const UCTurma &ucTurma) const {
    auto pos = aulas.find(ucTurma);
    return pos;
}

void GestaoHor::printOccupation(const UCTurma& ucTurma) const {
    const _Rb_tree_const_iterator<UCTurma> uc = findUC(ucTurma);
    if (uc == aulas.end()) {
        cout << "Turma nao encontrada." << endl;
        return;
    }
    cout << "A turma " << uc->getTurma() << " da UC " << uc->getUC() << " tem " << uc->getSize() << " estudantes inscrit@s." << endl;
}

bool GestaoHor::isScheduleValid() const {
    for (size_t i = 0; i < horario.size()-1; i++) {
        for (size_t j = i+1; j < horario.size(); j++) {
            if (horario[i].first.getDay() != horario[j].first.getDay()) continue;
            if (horario[i].first.getType() == "T" || horario[j].first.getType() == "T") continue;
            if (horario[i].first.getHour() == horario[j].first.getHour()) return false;
            if (horario[i].first.getHour() < horario[j].first.getHour() && horario[j].first.getHour() < horario[i].first.getHour()+horario[i].first.getDuration()) return false;
        }
    }
    return true;
}

bool GestaoHor::processPedido(bool def) {
    Pedido pedido = pedidos.front();
    pedidos.pop();
    bool r;
    switch (pedido.getOption()) {
        case 1:
            r = addTurmaStudent(pedido.getCode(),UCTurma(pedido.getAdding().first,pedido.getAdding().second));
            break;
        case 2:
            r = removeTurmaStudent(pedido.getCode(), UCTurma(pedido.getRemoving().first,pedido.getRemoving().second));
            break;
        case 3:
            r = swapTurmaStudent(pedido.getCode(),UCTurma(pedido.getRemoving().first,pedido.getRemoving().second),
                                 UCTurma(pedido.getAdding().first,pedido.getAdding().second));
            break;
        default:
            r = false;
    }
    if (!def && r && pedido.getOption() != 2) {
        Student student = Student(pedido.getCode(), "");
        auto s = estudantes.find(student);
        student = *s;
        fstream fout;
        fout.open("../changes.csv", ios::out | ios::app);
        int code = pedido.getCode();
        string name = student.getName();
        string uc = pedido.getAdding().first;
        string turma = pedido.getAdding().second;
        fout << code << ',' << name << ',' << uc << ',' << turma << '\n';
        fout.close();
    }
    return r;
}

void GestaoHor::addPedido(const Pedido &pedido) {
    pedidos.push(pedido);
    cout << "O seu pedido foi registado com o numero " << pedidos.size() << "." << endl;
    cout << '\n';
}

bool GestaoHor::pedidosEmpty() const{
    return pedidos.empty();
}

void GestaoHor::write() const {
    ofstream ofs;
    ofs.open("students_classes.csv", ofstream::out | ofstream::trunc);
    ofs.close();
    ofs.open("students_classes.csv", ofstream::out | ofstream::app);
    ofs << "StudentCode,StudentName,UcCode,ClassCode\n";
    for (const Student & student : estudantes) {
        for ( const UCTurma & ucTurma : student.getTurmas()) {
            ofs << student.getCode() << ',' << student.getName() << ','
                << ucTurma.getUC() << ',' << ucTurma.getTurma() << '\n';
        }
    }
}

int GestaoHor::showStudentsByYear(char year) const{
    int n = 0;
    cout << "StudentCode | StudentName\n";
    for (const Student & student : roll) {
        for (const UCTurma & ucTurma : student.getTurmas()) {
            if (ucTurma.getTurma()[0] == year) {
                cout << student.getCode() << " | " << student.getName() << '\n';
                n++;
                break;
            }
        }
    }
    return n;
}

int GestaoHor::showStudentsByClass(const UCTurma & turma) const{
    int n = 0;
    cout << "StudentCode | StudentName\n";
    for (const Student & student : roll) {
        for (const UCTurma & t : student.getTurmas()) {
            if (t.getUC() == turma.getUC() && t.getTurma() == turma.getTurma()) {
                cout << student.getCode() << " | " << student.getName() << '\n';
                n++;
                break;
            }
        }
    }
    return n;
}

int GestaoHor::showStudentsByUC(string UC) const{
    int n = 0;
    cout << "StudentCode | StudentName\n";
    for (const Student & student : roll) {
        for (UCTurma t : student.getTurmas()) {
            if (t.getUC() == UC) {
                cout << student.getCode() << " | " << student.getName() << '\n';
                n++;
                break;
            }
        }
    }
    return n;
}

void GestaoHor::alphabeticOrder() {
    roll = vector<Student>(estudantes.begin(),estudantes.end());
    sort(roll.begin(),roll.end(),[](Student const &a, Student const &b){
        return a.getName() < b.getName();
    });
}

void GestaoHor::numericOrder() {
    roll = vector<Student>(estudantes.begin(),estudantes.end());
    sort(roll.begin(),roll.end());
}

int GestaoHor::studentsSize() const{
    return estudantes.size();
}
