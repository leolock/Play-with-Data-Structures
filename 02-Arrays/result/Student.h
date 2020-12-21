#include <ostream>
#include <string>

class Student{
public:
    Student(std::string name ="", int score = 0){
        this->name = name;
        this->score = score;
    }
    friend std::ostream & operator<<(std::ostream &out, Student &student){
        out << "name: " <<student.name << "," <<"score: " << student.score;
        return out;
    }
private:
    std::string name;
    int score;
};