#ifndef AED_PROJ1_GESTAOHOR_H
#define AED_PROJ1_GESTAOHOR_H

/*! \mainpage Projeto 1 AED
* This is a tender for the first practical assignment of the
* course Algoritmos e Estruturas de Dados of the Licenciatura em Engenharia
* Informática e Computação of the Faculty of Engineering of the University of Porto
* and the Faculty of Sciences of the University of Porto.
* It was made by the students João das Neves Fernandes (202108867)
* (up202108867@edu.fe.up.pt) and
* Pedro Simão Januário Vieira (202108768) (up202108768@edu.fe.up.pt), both belonging to Group No. 10, from class 2LEIC01.\n \n
 * It supports showing the schedule of students, various listings and processing requests of changes to the
 * schedules.
*/

#include "Student.h"
#include "Pedido.h"
#include <set>
#include <queue>

using namespace std;

class Student;
class UCTurma;
class Pedido;

/**
 * @class GestaoHor class implements A class for managing students' schedules,
 * containing all students, classes and their schedules.\n
 * It is the "center" of operations of the program.
 */

class GestaoHor {
public:
    GestaoHor(); /*!< A default constructor. */
    void readStudents(); /*!< Reads and saves all students from an existing csv file in private member \a estudantes.
 * \n Complexity: O(n log(n)), with \a n being the number of lines of csv file. */
    void readUCTurma(); /*!< Reads and saves all classes and their respective schedule from an existing csv file in private member \a turmas.
 * \n Complexity: O(n²), with \a n being the number of lines of csv file. */
    void printStudents() const; /*!< Prints all students' codes and names.
 * \n Complexity: O(n), with \a n being the size of the private member \a estudantes (total number of students)*/
    bool removeTurmaStudent(int n, const UCTurma& turma); /*!< Searches for the student with code \a n and removes
 * the desired class from their \a turmas field, calling Student::removeTurma(), and decrements the size
 * (occupation) of the class, calling UCTurma::decrementSize().\n Returns \b false if the provided student
 * code does not belong to any student, the same for the class, \b true otherwise.\n Complexity: O(n), being \a n
 * the number of classes the student is enrolled in. */
    bool addTurmaStudent(int n, const UCTurma& turma); /*!< Searches for the student with code \a n and tries to add
 * the desired class to their \a turmas field, calling Student::addTurma(), and increments the size
 * (occupation) of the class, calling UCTurma::incrementSize().\n Returns \b false if the provided student
 * code does not belong to any student, the same for the class, if the change unbalances the classes' occupation in the
 * desired UC or if the student's schedule is not compatible with the change, \b true otherwise.\n Complexity: O(n²), being \a n the number of classes the student is enrolled in. */
    bool swapTurmaStudent(int n, const UCTurma& removing, const UCTurma& adding); /*!< Searches for the student with code \a n and removes
 * the desired class from their \a turmas field, calling Student::removeTurma(), and decrements the size
 * (occupation) of the class, calling UCTurma::decrementSize(). Tries to add
 * the desired class to their \a turmas field, calling Student::addTurma(), and increments the size
 * (occupation) of the class, calling UCTurma::incrementSize().\n Returns \b false if the provided student
 * code does not belong to any student, the same for the classes, if the change unbalances the classes' occupation in the
 * desired UC or if the student's schedule is not compatible with the change, \b true otherwise.
 * \n Complexity: O(n²), being \a n the number of classes the student is enrolled in. */
    void addPairSchedule(const pair<Slot,pair<string,string>>& uc); /*!< Since the schedule the program works on in a
 * given moment is loaded into the field \a horario, the purpose of this method is to load a pair, being its first member
 * a Slot (occurrence of a class) and its second member another pair containing two strings indicating the class that the
 * slot is regarding.\n Complexity: O(1). */
    void printSchedule(int n); /*!< Loads the schedule of a desired student (by their code). Prints an error message if
 * they're not found.\n Complexity: O(n²), being \a n the number of classes the student is enrolled in. */
    void printOccupation(const UCTurma& ucTurma) const; /*!< Prints the occupation (number of enrolled students)
 * of a desired class.\n Complexity: O(log n), being \a n the total number of classes (size of field \a aulas). */
    const _Rb_tree_const_iterator<UCTurma> findUC(const UCTurma& ucTurma) const; /*!< Returns a pointer to a desired class.
 * \n Complexity: O(log n). */
    bool isScheduleValid() const; /*!< Returns whether the currently loaded schedule is valid (the are no overlapping TP or PL slots) or not.
 * \n Complexity: O(n²), being \a n the number of slots of the schedule. */
    void addPedido(const Pedido& pedido); /*!< Adds a request to the requests queue.\n Complexity: O(1). */
    bool processPedido(bool def); /*!< Processes the first request on the queue and returns whether it can be accepted or not.\n
 * Complexity: O(n), being \a n the number of classes the student is enrolled in. O(log n) if the request is to only
 * remove a student from a class, being \a n the number of total students. */
    bool pedidosEmpty() const; /*!< Returns whether the requests queue is empty or not.\n Complexity: O(1). */
    void write() const; /*!< Writes the changes made processing the requests definitely.\n
 * Complexity: O(n²), being \a n the total number of existing students. */
    int showStudentsByYear(char year) const; /*!< Prints all the students' codes and names enrolled in UCs of a given year
 * and returns that total.\n Complexity: O(n²), being \a n the total number of existing students. */
    int showStudentsByClass(const UCTurma &turma) const; /*!< Prints all the students' codes and names enrolled in
 * a given class of a given UC and returns that total.\n Complexity: O(n²), being \a n the total number of existing students. */
    int showStudentsByUC(string UC) const; /*!< Prints all the students' codes and names enrolled in a given UC
 * and returns that total.\n Complexity: O(n²), being \a n the total number of existing students. */
    void alphabeticOrder(); /*!< Loads all the students into the vector \a roll and sorts it in alphabetical order
 * (comparing the students' names lexicographically).\n Complexity: O(n log(n)), being \a n the total number of
 * existing students. */
    void numericOrder(); /*!< Loads all the students into the vector \a roll and sorts it in numeric order
 * (comparing the students' codes).\n Complexity: O(n log(n)), being \a n the total number of existing students. */
    int studentsSize() const; /*!< Returns the total number of existing students (size of \a estudantes).\n
 * Complexity: O(1). */
private:
    set<Student> estudantes; /*!< A set (binary search tree) that, after calling the readStudents() method,
 * contains all the existing students, sorted according to Student::operator<. */
    set<UCTurma> aulas; /*!< A set (binary search tree) that, after calling the readStudents() and readUCTurma() methods,
 * contains all the existing classes (UCTurma), sorted according to UCTurma::operator<. */
    vector<Student> roll; /*!< A working vector, useful to have students sorted in different ways. */
    vector<pair<Slot,pair<string,string>>> horario; /*!< A working vector that serves as the currently loaded schedule,
 * of a given student. */
    queue<Pedido> pedidos; /*!< A queue to store the client's requests to be processed at the end of the day
 * (when the program is closed). */
};


#endif //AED_PROJ1_GESTAOHOR_H
