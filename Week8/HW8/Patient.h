/**
 * Created by Antonio Santana on 6/8/2021
 * Patient.h
 *
 * The underscore in the variable names is used to differentiate private variables.
 * To compare two _patientVectors, use the Patient values.  Private variable _nextPatientNumber
 * is used to keep track of the last patient inserted into the heap, so that as _patientsVector
 * arrive, they will get assigned proper _arrivalOrder (start numbering at 1)
 */

#ifndef HW8_PATIENT_H
#define HW8_PATIENT_H

#include <string>


using namespace std;

class Patient {
private:
    /** Private variable name (patient's full name) */
    string _name;

    /** Private variable priorityCode (patient's assigned priority) */
    string _priorityCode;

    /** Private variable arrivalOrder (assigned arrival number) */
    int _arrivalOrder = 1;
    /**
     * I'm not sure if this _compareCode is really needed as a private
     * and if the compare code could be made into a method instead.
     */


public:
    /** Default Constructor. */
    Patient(string name, string priorityCode, int arrivalOrder)
    {
        this->_name = name;
        this->_priorityCode = priorityCode;
        this->_arrivalOrder = arrivalOrder;
    }

    string getName() const
    {
        return _name;
    };

    string getPriority() const
    {
        return _priorityCode;
    };

    int getArrivalOrder()
    {
        return _arrivalOrder;
    }


    /** Overload the compare greater than operator.  */
    bool operator>(const Patient& leftHandSide) const;

    /** Overload the compare less than operator.  */
    bool operator<(const Patient& rightHandSide) const;

    string to_string()
    {
        return (_name + "pri = " + this->_priorityCode + ". arrive: " +
               std::to_string(_arrivalOrder));
    }
};

/** Compare patients to determine where they should be placed in the patient priority queue. The patient at
 * the front of the priority queue is the one with the highest priority. Patient 1 > patient 2 means that
 * patient 1 is a higher priority than patient 2. Compare patients based on priority code. If two patients have the
 * same priority code, compare patients by the arrival order.
*/
bool Patient::operator>(const Patient& r) const {

    // If 2 patients have the same priority code, sort based on arrival order.
    // The patient that arrived first has a smaller value for arrivalOrder and
    // a higher priority in the priority queue.
    if(_priorityCode == r._priorityCode) {
        if (_arrivalOrder < r._arrivalOrder) {
            return true;
        } else {
            return false;
        }
    } else {
        // If 2 patients have different priority codes, the patients are compared by priority code as follows:
        // immediate > emergency > urgent > minimal.
        if (_priorityCode == "immediate") {
            return true;
        }
        else if (_priorityCode == "emergency" && r._priorityCode == "immediate") {
            return false;
        }
        else if (_priorityCode == "emergency" && (r._priorityCode == "urgent" || r._priorityCode == "minimal")) {
            return true;
        }
        else if (_priorityCode == "urgent" && (r._priorityCode == "immediate" || r._priorityCode == "emergency")) {
            return false;
        }
        else if (_priorityCode == "urgent" && r._priorityCode == "minimal") {
            return true;
        }

        else {    // priority code of current patient is minimal.
            return false;
        }
    }
}

/** se of > operator in addition to the < operator implemented above. Use same
 * logic as for < operator to compare patients using the > operator. */
bool Patient::operator<(const Patient& r) const {
    // If 2 patients have the same priority code, sort by arrival order.
    if (_priorityCode == r._priorityCode)
    {
        if (_arrivalOrder > r._arrivalOrder)
        {
            return true;
        } else {
            return false;
        }
    } else {
        // If 2 patients have different priority codes, the patients are compared by priority code as follows:
        // immediate > emergency > urgent > minimal.
        if (_priorityCode == "immediate")
        {
            return false;
        } else if (_priorityCode == "emergency" && r._priorityCode == "immediate")
        {
            return true;
        } else if (_priorityCode == "emergency" && (r._priorityCode == "urgent" || r._priorityCode == "minimal"))
        {
            return false;
        } else if (_priorityCode == "urgent" && (r._priorityCode == "immediate" || r._priorityCode == "emergency"))
        {
            return true;
        } else if (_priorityCode == "urgent" && r._priorityCode == "minimal")
        {
            return false;
        } else {
            return true;
        }
    }
}
#endif //HW8_PATIENT_H
