#include <iostream>
#include <cassert>

template<typename T>
class Array{
public:
    Array(int capacity){
        data = new T[capacity];
        size = 0;
        this -> capacity = capacity;
    }
private:
    T *data;
    int size;
    int capacity;
    
};