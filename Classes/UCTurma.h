#ifndef AED_PROJ1_UCTURMA_H
#define AED_PROJ1_UCTURMA_H

#include <string>
#include <vector>
#include "Slot.h"
#include "Student.h"

using namespace std;

class GestaoHor;

/**
 * @class UCTurma class implements A class for an association between a class (\a Turma) and a course (\a UC), with
 * information regarding its many occurrences (Slots) and the number of enrolled students.
 */
class UCTurma {
public:
    UCTurma(const string& codUC, const string& codTurma); /*!< A constructor that receives a \b string with the name of
 * the course (UC) and another \b string which is the code of the class (Turma). */
    string getUC() const; /*!< Returns the course code (UC code).\n Complexity: O(1). */
    string getTurma() const; /*!< Returns the class code (Turma code).\n Complexity: O(1). */
    void addSlot (const Slot& slot); /*!< Adds a slot (an occurrence) to the instance's occurrences.\n Complexity: O(1). */
    void print() const; /*!< Prints the course's code (UC), its class code (Turma) and its slots (occurrences), using the Slot class
 * method print().
 * \n Complexity: O(n), with \a n being the size of the private member \a horarioUCTurma (the number of occurrences). */
    bool operator<(const UCTurma& turma) const; /*!< Overload of operator < (less than). Compares the code of UC
 * lexicographically. If the UC is the same, compares the class codes.\n Complexity: O(1). */
    void incrementSize(); /*!< Increments the size (number of enrolled students) by 1.\n Complexity: O(1). */
    void decrementSize(); /*!< Decrements the size (number of enrolled students) by 1.\n Complexity: O(1). */
    int getSize() const; /*!< Returns the size (number of enrolled students).\n Complexity: O(1). */
    /*UCTurma& operator=(const UCTurma& turma); /*!< Overload of operator = (assignment). Returns an object
 * of class UCTurma with the same values as the one in which the method is called.\n Complexity: O( */
    void loadSlots(GestaoHor& g) const; /*!< Loads the slots (class occurrences) into a given GestaoHor object.\n
 * Complexity: O(n), being \a n the number of slots. */
private:
    string codUC_; /*!< \b String for the course's code (UC code). */
    string codTurma_; /*!< \b String for the class's code (Turma code). */
    vector<Slot> horarioUCTurma; /*!< A \b vector<Slot> with the occurrences of the instance. */
    int size; /*!< An \b integer that indicates the number of enrolled students. */
};


#endif //AED_PROJ1_UCTURMA_H
