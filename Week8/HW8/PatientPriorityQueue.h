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
//    virtual bool enqueue(const ItemType& newEntry) = 0;
//    virtual bool enqueue(const int& newEntry) = 0;
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
//    virtual ItemType peekFront() const = 0;
//    virtual int peekFront() const = 0;
//    int peekFront() const = 0;

//    int size() const = 0;

    /** Destroy this queue and frees its assigned memory. */
    virtual ~PatientPriorityQueue(){ }

}; // end PatientPriorityQueue
#endif //HW8_PATIENTPRIORITYQUEUE_H



