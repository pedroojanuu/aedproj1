#ifndef AED_PROJ1_PEDIDO_H
#define AED_PROJ1_PEDIDO_H

#include "Student.h"

using namespace std;

/**
 * @class Pedido class implements A class for a request for a change in the schedules, i.e. for when the client wants some
 * student to leave or join some class (UCTurma) or a group of them.
 */
class Pedido {
public:
    Pedido(const Student& pedinte, const vector<UCTurma>& turmas, bool joining); /*!< A constructor that receives a \b Student,
 * a \b vector of classes (UCTurma) the client wants the student to leave or join and a \b boolean that indicates whether the
 * student should join or leave the given classes (\b true if joining, \b false if leaving). */
    Pedido(const Student& pedinte, const vector<UCTurma>& a_remover, const vector<UCTurma>& a_adicionar); /*!< A constructor that
 * receives a \b Student and two \b vectors of classes (UCTurma): one for the classes the client wants the student to join and another
 * for the classes they want them to leave. */
    bool processar_pedido(); /*!< A method that processes the request and makes the desired changes if the conditions for doing so
 * are met. Returns \b true if the request is accepted, \b false otherwise.\n COMPLEXITY: ???????? */
private:
    Student pedinte_; /*!< The Student the request is about. */
    vector<UCTurma> a_remover_; /*!< A vector containing the classes the client wants the student to join (if applicable). */
    vector<UCTurma> a_adicionar_; /*!< A vector containing the classes the client wants the student to leave (if applicable). */
};


#endif //AED_PROJ1_PEDIDO_H
