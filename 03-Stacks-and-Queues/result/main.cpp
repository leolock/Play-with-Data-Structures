#include <iostream>
#include "ArrayQueue.h"
#include "LoopQueue.h"
int main() {
	LoopQueue<int> *loopQueue = new LoopQueue<int>(5);
	for(int i=0;i<10;++i){
		loopQueue->enqueue(i);
		loopQueue->print();
	}
    
    return 0;
}
