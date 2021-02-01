#ifndef QUEUE_H
#define QUEUE_H


template<typename T>
class Queue{
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual void enqueue(T e) = 0;
    virtual T dequeue() = 0;
    virtual T getfront() = 0;
};

#endif // QUEUE_H