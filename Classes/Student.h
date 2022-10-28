#ifndef AED_PROJ1_STUDENT_H
#define AED_PROJ1_STUDENT_H

#include <string>

#include "UCTurma.h"

using namespace std;

/**
 * @class Student A class for Student, containing their name, unique code and a vector with the classes they're in.
 */
class Student {
public:
    Student(int code, const string& name); /*!< A constructor that receives an \b int code and a \b string name. */
    int getCode() const; /*!< Returns the student's code. */
    string getName() const; /*!< Returns the student's name. */
    bool operator<(const Student& s) const; /*!< Overload of operator < (less than). Since each student's code is unique, it
 * only compares  */
    void addTurma(const UCTurma& turma);
    void print() const;
    Student& operator=(const Student& student);
    void removeTurma(const UCTurma& turma);
private:
    int code_;
    string name_;
    vector<UCTurma> turmas;
};


#endif //AED_PROJ1_STUDENT_H
