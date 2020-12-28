#ifndef LOOPQUEUE_H
#define LOOPQUEUE_H

#include "Queue.h"
#include <iostream>
#include <cassert>
#include <memory>

template<typename T>
class LoopQueue : public Queue<T>{
public:
    LoopQueue(){
        data = new T[11];
        front = 0;
        tail = 0;
        capacity = 10;
    }
    LoopQueue(int capacity){
        data = new T[capacity+1];
        front = 0;
        tail = 0;
        this->capacity = capacity;
    }
    ~LoopQueue(){
        delete[] data;
        data = nullptr;
    }

    bool isEmpty(){
        return front == tail;
    }
    int getSize(){
        return (tail-front+capacity) % capacity;
    }
    void enqueue(T e){
        if((tail+1)%capacity == front){
            resize(2*capacity);
        }
        data[tail] = e;
        tail = (tail+1) % capacity;
    }
    T dequeue(){
        assert(front != tail);
        T ret = data[front];
        front = (front+1)%capacity;
        // 向下取整
        if(getSize() == capacity /4 && capacity / 2 != 0){
            resize(capacity / 2);
        }
        return ret;
    }

    T getFront(){
        assert(front != tail);
        return data[front];
    }

    void print(){
        std::cout<<"LoopQueue: size: " << getSize() << ", capacity = " << capacity << std::endl;
        std::cout<< "front [";
        for(int i=front;i!= tail;i = (i+1)%capacity){
            std::cout<< data[i];
            if((i + 1)%capacity != tail){
                std::cout<< ",";
            }
        }
        std::cout<< "] tail"<<std::endl;
    }
private:
    T *data;
    int front, tail;
    int capacity;
    // 改变数组的大小，并将起始位置重置为0
    void resize(int newCapacity){
        T *newData = new T[newCapacity + 1];
        for(int i=0;i<getSize();++i){
            newData[i] = data[(i+front)%capacity];
        }
        front = 0;
        tail = getSize();
        data = newData;
        capacity = newCapacity;

        newData = nullptr;
        delete[] newData;
    }
};

#endif // LOOPQUEUE_H