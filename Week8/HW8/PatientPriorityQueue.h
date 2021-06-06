/*
 * Created by Antonio Santana on 6/8/2021
 * PatientPriorityQueue.h
 */

/** @file PatientPriorityQueue.h */
#ifndef HW8_PATIENTPRIORITYQUEUE_H
#define HW8_PATIENTPRIORITYQUEUE_H

#include <vector>
#include "Patient.h"

class PatientPriorityQueue {
private:
    /** Uses an vector<Patient> to store the patients in heap order. */
    std::vector <Patient> patientsVector;

//    /** Private variable nextPatientNumber is used to keep track of the last patient inserted into the heap */
//    int priorityCode{};
//
//    /** Private variable arrivalOrder (assigned arrival number) */
//    int arrivalOrder{};
public:
    /** Default constructor */
    PatientPriorityQueue();

    /** Sees whether this queue is empty.
    @return  True if the queue is empty, or false if not. */
     bool isEmpty();

    /** Adds a new entry to the back of this queue.
     @post  If the operation was successful, newEntry is at the
        back of the queue.
     @param newEntry  The object to be added as a new entry.
     @return  True if the addition is successful or false if not. */
    void enqueue( Patient& newEntry);

    /** Removes the front of this queue.
     @post  If the operation was successful, the front of the queue
        has been removed.
     @return  True if the removal is successful or false if not. */
    bool dequeue();

    /** Returns the front of this queue.
     @pre  The queue is not empty.
     @post  The front of the queue has been returned, and the
        queue is unchanged.
     @return  The front of the queue. */
    Patient peekFront();

    /** Returns the size of this queue.
     @pre  The queue is not empty.
     @post  The queue size has been returned, and the
        queue is unchanged.
     @return  The size of the queue. */
    int size();

    /** Destroy this queue and frees its assigned memory. */
    virtual ~PatientPriorityQueue(){ }

}; // end PatientPriorityQueue

PatientPriorityQueue::PatientPriorityQueue() = default;

bool PatientPriorityQueue::isEmpty() {
    return patientsVector.size() == 0 ;
}

void PatientPriorityQueue::enqueue(Patient &newEntry) {
    patientsVector.push_back(newEntry);
    // TODO Return a bool instead.
}

bool PatientPriorityQueue::dequeue() {
    patientsVector.pop_back();
    // TODO Remove the last element and resize.
    return true;
}

int PatientPriorityQueue::size() {
    return patientsVector.size();
}

Patient PatientPriorityQueue::peekFront() {
    return patientsVector.front();
}

#endif //HW8_PATIENTPRIORITYQUEUE_H



