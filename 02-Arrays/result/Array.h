#include <iostream>
#include <cassert>

template<typename T>
class Array {
public:
    // 构造函数，传入数组的容量capacity构造Array
    Array(int capacity) {
        data = new T[capacity];
        size = 0;
        this->capacity = capacity;
    }

    // 无参数的构造函数，默认数组的容量capacity=10
    Array() {
        data = new T[10];
        size = 0;
        capacity = 10;
    }

    // 获取数组的容量
    int getCapacity() {
        return capacity;
    }

    // 获取数组中的元素个数
    int getSize() {
        return size;
    }

    // 返回数组是否为空
    bool isEmpty() {
        return size == 0;
    }

    void add(int index, T e){
        assert(index >= 0 && index <= size );
        if(size == capacity){
            resize(2 * capacity);
        }
        for(int i=size-1;i>=index;--i){
            data[i+1] = data[i];
        }
        data[index] = e;
        size++;
    }

    void addFirst(T e){
        add(0, e);
    }

    void addLast(T e){
        add(size, e);
    }

    T get(int index){
        assert(index >= 0 && index < size);
        return data[index];
    }

    void set(int index, T e){
        assert(index >= 0 && index < size);
        data[index] = e;
    }

    bool contains(T e){
        assert(size > 0);
        for(int i=0;i<size;++i){
            if(data[i] == e) return true;
        }
        return false;
    }

    int find(T e){
        assert(size > 0);
        for(int i=0;i<size;i++){
            if(data[i] == e) return i;
        }
        return -1;
    }

    T remove(int index){
        assert(size > 0 && index >= 0 && index<size);
        T ret = data[index];
        for(int i=index+1;i<size;++i){
            data[i-1] = data[i];
        }
        size--;
        if(size == capacity/2 && capacity/2 != 0){
            resize(capacity/2);
        }
        return ret;
    }

    T removeFirst(){
        return remove(0);
    }

    int removeLast(){
        return remove(size-1);
    }
    // 删除第一个出现的元素
    void removeElement(T e){
        int index = find(e);
        if(index != -1) remove(index);
    }

    void print(){
        assert(size > 0);
        std::cout << "Array: size = "<< size << ",capacity = " << getCapacity() << std::endl;
        std::cout << "[";
        for(int i = 0; i<size; ++i){
            std::cout <<data[i];
            if(i != size-1) std::cout << ","<<std::endl;
        }
        std::cout << "]";
        std::cout << std::endl;
    }
private:
    T *data;
    int size;
    int capacity;

    void resize(int newCapacity){
        T *newData = new T[newCapacity];
        for(int i=0;i<size;++i){
            newData[i] = data[i];
        }
        data = newData;
        capacity = newCapacity;
        newData = nullptr;
        delete []newData;
    }
};
