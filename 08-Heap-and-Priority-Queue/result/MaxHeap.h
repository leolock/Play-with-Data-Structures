#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "Array.h"

template<typename T>
class MaxHeap{
private:
    Array<T> *data;

    int leftChild(int index){
        return 2*index + 1;
    }
    int rightChild(int index){
        return 2*index + 2;
    }
    void shiftUp(int k){
        while(k>0 && data->get(parent(k)) < data->get(k)){
            data->swap(k, parent(k));
            k = parent(k);
        }
    }
    void shiftDown(int k){
        while(leftChild(k) < data->getSize()){
            // i更新为二叉树中最大的节点
            int i = leftChild(k);
            // 右子节点较大的情况 
            if(i+1 < data->getSize() && data->get(i+1) > data->get(i)){
                i = rightChild(k);
            }
            // 根节点较大的情况
            if(data->get(i) < data->get(k)){
                break;
            }
            data->swap(i, k);
            k = i;
        }
    }
public:
    class NoParent{
    };
    class Empty{
    };
    MaxHeap(int capacity){
        data = new Array<T>(capacity);
    }
    MaxHeap(){
        data = new Array<T>();
    }
    MaxHeap(T arr[], int n){
        data = new Array<T>(arr, n);
        for(int i=parent(n-1);i>=0;--i){
            shiftDown(i);
        }
    }
    int size(){
        return data->getSize();
    }
    bool isEmpty(){
        return data->isEmpty();
    }

    // 返回索引代表的节点的父节点的索引
    int parent(int index){
        if(index == 0){
            throw NoParent();
        }
        return (index-1)/2;
    }
    void add(T e){
        data->addLast(e);
        shiftUp(data->getSize()-1);
    }

    T findMax(){
        if(data->isEmpty()){
            throw Empty();
        }
        return data->get(0);
    }
    T extractMax(){
        T ret = findMax();
        data->swap(0, data->getSize() - 1);
        data->removeLast();
        shiftDown(0);
        return ret;
    }
    T replace(T e){
        T ret = findMax();
        data->set(0, e);
        shiftDown(0);
        return ret;
    }
    void print(){
        data->toPrint();
    }
};

#endif // MAXHEAP_H