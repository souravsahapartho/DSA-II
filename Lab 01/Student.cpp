#include<iostream>
using namespace std;

class Student{
    string name;
    int id;
    double cgpa;
public:

    /*Student(string n, int id, double c){
        //constructor body
        this->name = n;
        this->id = id;
        cgpa = c;
    }*/
    //member initializer list
    Student(string n, int id, double c) : name(n), id(id), cgpa(c) {
    }

    void display(){
        cout << "name:" << name << " id:" << id << " cgpa:" <<cgpa << endl;
    }

    void updateCgpa(double new_cgpa){
        if(new_cgpa <= 4)
           cgpa = new_cgpa;
        else cout<< "cgpa update failed" << endl;
    }

};

int main(){
    Student s1("Mina", 1, 3.4);
    s1.updateCgpa(4.1);
    s1.display();
    Student s2("Abir", 2, 3.6);
    s2.display();
}
