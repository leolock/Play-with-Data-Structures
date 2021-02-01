#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Queue.h"
#include "MaxHeap.h"

template<typename T>
class PriorityQueue : public Queue<T>{
private:
    MaxHeap<T> *maxHeap;
public:
    PriorityQueue(){
        maxHeap = new MaxHeap<T>();
    }

    int getSize(){
        return maxHeap->size();
    }

    bool isEmpty(){
        return maxHeap->isEmpty();
    }

    T getfront(){
        return maxHeap->findMax();
    }
    void enqueue(T e){
        maxHeap->add(e);
    }
    T dequeue(){
        maxHeap->extractMax();
    }
    void print() {
		std::cout << "Queue: size = " << maxHeap->size() << std::endl;
        std::cout << "front ";
        maxHeap->print();
        std::cout << " tail" << std::endl;
	}
};

#endif // PRIORITYQUEUE_H