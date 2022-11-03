#ifndef AED_PROJ1_SLOT_H
#define AED_PROJ1_SLOT_H

#include <string>

using namespace std;

/**
 * @class Slot class implements A class for a slot of a lesson, i.e. an occurrence of any kind (T, TP, PL) of a class.
 */
class Slot {
public:
    Slot(const string& dia, float horaInicio, float duracao, const string& tipo); /*!< A constructor that receives
 * a \b string being the day of the week of the occurrence, a \b float that is the hour of the occurrence, a \b float that is its duration
 * and a \b string indicating the type of the occurrence (T, TP, PL). */
    void print() const; /*!< Prints the slot's weekday, type, hour and duration.\n Complexity: O(1). */
    bool operator<(const Slot& slot) const; /*!< Overload of operator < (less than). Returns if the Slot occurs
 * before (in time) the other given slot.\n Complexity: O(1). */
    string getDay() const; /*!< Returns the slot's day.\n Complexity: O(1). */
    string getType() const; /*!< Returns the slot's type (T, TP, PL).\n Complexity: O(1). */
    float getHour() const; /*!< Returns the slot's starting hour.\n Complexity: O(1). */
    float getDuration() const; /*!< Returns the slot's duration.\n Complexity: O(1). */
private:
    string dia_; /*!< A \b string indicating the day of the week of the lesson.*/
    string tipo_; /*!< A \b string indicating the kind of the lesson.*/
    float horaInicio_; /*!< \b Float indicating when the lesson begins (the starting hour). */
    float duracao_; /*!< \b Float indicating how long (in hours) the lesson lasts. */
};


#endif //AED_PROJ1_SLOT_H
