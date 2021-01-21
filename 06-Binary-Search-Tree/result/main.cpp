#include <iostream>
#include "BST.h"
#include "Array.h"

int main() {
    BST<int> bst;
    int n = 1000;
    for(int i=0;i<n;++i){
        bst.add(rand()%10000);
    }

    Array<int> *nums = new Array<int>();
    int index = 0;
    std::cout << bst.getSize() << " ";
    while(!bst.isEmpty()){
        nums->add(index, bst.removeMin());
        index++;
    }
    std::cout << bst.getSize();
    nums->print();
    for(int i=1;i<nums->getSize();++i){
        if(nums->get(i-1) > nums->get(i)){
            std::cout << "error";
            return -1;
        }
    }
    std::cout << "remove min test complete" << std::endl;
    nums = nullptr;
    return 0;
}
