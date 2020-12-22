#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
#include "Array.h"
#include "Queue.h"
template<typename T>
class ArrayQueue: public Queue{
public:
    ArrayQueue(){
        array = new Array<T>();
    }
private:
    Array<T> *array;
};

#endif // ARRAYQUEUE_H