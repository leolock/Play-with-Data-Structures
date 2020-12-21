#include <iostream>
#include "Array.h"
#include "Student.h"

int main() {
    // Student s("Alice", 98);
    Array<Student> *array = new Array<Student>(20);
    array->addLast(Student("Alice",100));
    array->addLast(Student("Bob", 66));
    array->addLast(Student("Chalie", 88));
    array->print();
    // std::cout << s;
    array = nullptr;
    delete array;
    return 0;
}

