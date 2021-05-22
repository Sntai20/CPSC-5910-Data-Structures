#ifndef LECTURE_PRIORITYQUEUEINTERFACE_H
#define LECTURE_PRIORITYQUEUEINTERFACE_H

template <class ItemType>
class PriorityQueueInterface {
public:
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const ItemType& newEntry) = 0;
    virtual bool dequeue() = 0;

    /** @pre  The priority queue is not empty. */
    virtual ItemType peekFront() const = 0;
};
#endif //LECTURE_PRIORITYQUEUEINTERFACE_H
