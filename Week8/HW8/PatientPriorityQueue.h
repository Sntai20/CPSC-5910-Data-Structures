/*
 * Created by Antonio Santana on 6/8/2021
 * PatientPriorityQueue.h
 */

/** @file PatientPriorityQueue.h */
#ifndef HW8_PATIENTPRIORITYQUEUE_H
#define HW8_PATIENTPRIORITYQUEUE_H

#include <vector>
#include "Patient.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class PatientPriorityQueue {
private:
    int _nextPatientNumber;
    int _heapSize = 0;
    void _heapRebuild(int rootIndex);
    vector<Patient> _patientsVector;

public:
    /** Default constructor */
    PatientPriorityQueue();

    /** Adds a new entry to the back of this queue.
     @post  If the operation was successful, newEntry is at the
        back of the queue.
     @param newEntry  The object to be added as a new entry.
     @return  True if the addition is successful or false if not. */
    void add(Patient &newPatient);

    /** Returns the front of this queue.
     @pre  The queue is not empty.
     @post  The front of the queue has been returned, and the
        queue is unchanged.
     @return  The front of the queue. */
    Patient peek();

    /** Removes the front of this queue.
     @post  If the operation was successful, the front of the queue
        has been removed.
     @return  True if the removal is successful or false if not. */
    Patient remove();

    /** Returns the size of this queue.
     @pre  The queue is not empty.
     @post  The queue size has been returned, and the
        queue is unchanged.
     @return  The size of the queue. */
    int size();

    /** Returns the PatientPriorityQueue in a string format.
     @pre  The queue is not empty.
     @post  The queue strings have been returned, and the
        queue is unchanged.
     @return  The queue in a string format. */
    string to_string();

    /** Destroy this queue and frees its assigned memory. */
    virtual ~PatientPriorityQueue(){ }
};

/** Default constructor. Creates an empty triage system
 * without _patientsVector. Starting the index at position 1.
 */
PatientPriorityQueue::PatientPriorityQueue()
{
    _nextPatientNumber = 1;
}

/** Adds the patient to the priority queue. Heap order is defined
 * as the order that _patientsVector must be seen, so this function
 * needs to maintain heap order.
 *
 * Patient comes in and gets a priority code assigned. To maintain the
 * head order, this method must insert the patient into the _patientsVector
 * in the correct order. The order is determined by the _priorityCode. Ideally
 * the _priorityCode would correspond to the index position, then when more
 * patients are added the _arrivalOrder could be used to determine which
 * position the patients should be in.
     @post  If the operation was successful, newEntry is at the
        back of the queue.
     @param newEntry  The object to be added as a new entry.
     @return  True if the addition is successful or false if not. */
void PatientPriorityQueue::add(Patient &newPatient)
{
    _patientsVector.push_back(newPatient);
    int newDataIndex = _heapSize;
    bool inPlace = false;
    while ((newDataIndex > 0) && !inPlace)
    {
        int parentIndex = (newDataIndex - 1) / 2;
        if (_patientsVector.at(newDataIndex) > _patientsVector.at(parentIndex))
        {
            Patient temp = _patientsVector.at(newDataIndex);
            _patientsVector.at(newDataIndex) = _patientsVector.at(parentIndex);
            _patientsVector.at(parentIndex) = temp;
            newDataIndex = parentIndex;
        } else
            inPlace = true;
    }
    _heapSize++; // Increment the number
}

Patient PatientPriorityQueue::peek()
{
    return _patientsVector.at(_nextPatientNumber);
}

Patient PatientPriorityQueue::remove()
{
    Patient nextPatient = _patientsVector.at(0);
    _patientsVector.at(0) = _patientsVector.at(_heapSize - 1);
    _heapSize--;
    _heapRebuild(0);
    return nextPatient;
}

int PatientPriorityQueue::size()
{
    return _heapSize;
}

string PatientPriorityQueue::to_string()
{
    stringstream line;
    for( int i = 0; i < _heapSize; i++){
        line <<std::setw(5)<<_patientsVector.at(i).getArrivalOrder() + 1;
        line<<std::setw(17)<<_patientsVector.at(i).getPriority();
        line<<std::setw(22)<<_patientsVector.at(i).getName();
        line<<"\n";

    }
    return line.str();

}

void PatientPriorityQueue::_heapRebuild(int rootIndex)
{
    if (2 * rootIndex + 1 < _heapSize) // the root is not a leaf (that is, it has a left child)
    {
        int largerChildIndex = 2 * rootIndex + 1; // left child index
        if (largerChildIndex + 1 < _heapSize) // the root has a right child
        {
            int rightChildIndex = largerChildIndex + 1;
            if(_patientsVector.at(rightChildIndex) > _patientsVector.at(largerChildIndex))
                largerChildIndex = rightChildIndex;
        }

        if (_patientsVector.at(rootIndex) < _patientsVector.at(largerChildIndex))
        {
            Patient temp = _patientsVector.at(rootIndex);
            _patientsVector.at(rootIndex) = _patientsVector.at(largerChildIndex);
            _patientsVector.at(largerChildIndex) = temp;
            _heapRebuild(largerChildIndex);
        }
    }
}
#endif //HW8_PATIENTPRIORITYQUEUE_H



