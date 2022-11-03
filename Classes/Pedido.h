#ifndef AED_PROJ1_PEDIDO_H
#define AED_PROJ1_PEDIDO_H


#include "UCTurma.h"

/**
 * @class Pedido class implements A Class that represents a request to be made to the schedule management system.\n
 * A request (Pedido) can be a request to remove or add a student from/to a class in a given UC or a request to
 * swap a given student between two classes in a given UC.
 */

class Pedido {
private:
    int n_; /*!< An \b integer that is the unique code of student the request is about. */
    pair<string,string> adding_ = make_pair("",""); /*!< A pair of two strings that represent the UCTurma
 * the client may want to add the student to (can be empty), being the first string the UC code and the second string
 * the class code. */
    pair<string,string> removing_ = make_pair("",""); /*!< A pair of two strings that represent the UCTurma
 * the client may want to remove the student from (can be empty), being the first string the UC code and the second string
 * the class code. */
    short option_; /*!< A \b short \b int with the purpose of indicating whether the client wants to add a
 * student to a class in a UC, to remove them from it, or to swap them between classes in a UC. */
public:
    Pedido(int n, short option, const pair<string,string>& adding = make_pair("",""), const pair<string,string>& removing = make_pair("","")); /*!<
 * Constructor that receives an \b integer indicating the code of the student the request is about,
 * a \b short \b int indicating if the request is to add to a class, to remove from a class or to swap them between two
 * classes in a given UC. */
    int getCode() const; /*!< Returns the code of the student the request is about.\n Complexity. O(1). */
    short getOption() const; /*!< Returns the \b option field.\n Complexity: O(1). */
    pair<string,string> getAdding() const; /*!< Returns the pair of strings representing the \b UCTurma the client wants
 * to add the student to.\n Complexity: O(1). */
    pair<string,string> getRemoving() const; /*!< Returns the pair of strings representing the \b UCTurma the client wants
 * to remove the student from.\n Complexity: O(1). */
};


#endif //AED_PROJ1_PEDIDO_H
