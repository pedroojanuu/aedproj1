#ifndef AED_PROJ1_STUDENT_H
#define AED_PROJ1_STUDENT_H

#include <string>

#include "UCTurma.h"

using namespace std;

class UCTurma;

/**
 * @class Student class implements A class for Student, containing their name, unique code and a vector with the classes they're in.
 */
class Student {
public:
    Student(int code, const string& name); /*!< A constructor that receives an \b int code and a \b string name. */
    int getCode() const; /*!< Returns the student's code.\n Complexity: O(1). */
    string getName() const; /*!< Returns the student's name.\n Complexity: O(1). */
    bool operator<(const Student& s) const; /*!< Overload of operator < (less than). Since each student's code is unique, it
 * only compares their codes.\n Complexity: O(1). */
    void addTurma(const UCTurma& turma); /*!< Adds a class (push back) to the student's classes vector.\n Complexity: O(1). */
    void print() const; /*!< Prints the student's code, name and the classes they're in, using the UCTurma class method print().
 * \n Complexity: O(n), with \a n being the size of the private member \a turmas (the number of classes the student is in). */
    Student& operator=(const Student& student); /*!< Overload of operator = (assignment/copy). Returns a new Student with the
 * same attributes, not a reference.\n Complexity: O(n), since we have to traverse all elements in the \b turmas vector, being n its size. */
    void removeTurma(const UCTurma& turma); /*!< Removes a class from the list of classes the student is in.
 * \n Complexity: O(n), being n the size of the \b turmas vector. */
private:
    int code_; /*!< \b Integer for the student's code. */
    string name_; /*!< \b String for the student's code. */
    vector<UCTurma> turmas; /*!< A \b vector<UCTurma> with the classes the student is in. */
};


#endif //AED_PROJ1_STUDENT_H
