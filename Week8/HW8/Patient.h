/*
 * Created by Antonio Santana on 6/8/2021
 * Patient.h
 *
 */

#ifndef HW8_PATIENT_H
#define HW8_PATIENT_H

#include <string>
#include "PatientPriorityQueue.h"

class Patient {
    /** Private variable name (patient's full name) */
    std::string name;

    /** Private variable priorityCode (patient's assigned priority) */
    int priorityCode;

    /** Private variable arrivalOrder (assigned arrival number) */
//    int arrivalOrder;
public:
    Patient(std::string Name, std::string PriorityCode){

        /** Private variable name (patient's full name) */
        Name = name;

        /** Private variable priorityCode (patient's assigned priority) */
        PriorityCode = priorityCode;

        /** Private variable arrivalOrder (assigned arrival number) */
//        ArrivalOrder =  arrivalOrder;
}

    /** Adds the patient to the waiting room. */
//    void addPatientCmd(std::string line, PatientPriorityQueue &priQueue);

    /** Displays the next patient in the waiting room that will be called. */

//    /** to_string function that returns the string representation of the object. */
    std::string to_string();

    // TODO overloaded operators in order to properly add, peek, and remove patients from the waiting room.
    //  How do you compare two patients? In other words, define what it means to be sorted.
    //  Document any assumptions you make. For example: Jane Smith { pri=urgent, arrive=3 }
    //  constructor(s) and any other required functions needed to make the class work.

    /** Destroy this patient and frees it assigned memory. */
//    virtual ~Patient(){ }

};
#endif //HW8_PATIENT_H
