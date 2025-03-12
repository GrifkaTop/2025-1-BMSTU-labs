/*Задание: Описать класс по варианту.
 Worker: Фамилия и инициалы – char*, Должность-– char*, Зарплата – double.
Написать программу, в которой:
- продемонстрировать все случаи использования конструктора копирования;
- перегрузить оператор присваивания;
- включить в класс методы set для полей-указателей класса;
- перегрузить оператор вывода объекта в консоль.
Продемонстрировать использование.

Описание класса:
    • Поля в классе закрытые !
    • Наличие в классе конструктора копии !
    • Наличие в классе оператора присваивания!
    • Наличие в классе методов set для полей-указателей класса!
    • Наличие перегрузки оператора вывода объекта в консоль !
    • Наличие деструктора!
Демонстрация использования:
    • Создание нового объекта на основе существующего, использование оператора присваивания!
    • Вызов функции с параметром-объектом, переданным по значению !
    • Вызов функции, которая возвращает объект !
    • Использование метода set для полей-указателей класса, 
    вывода объекта в консоль*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

class Worker{
    private:
    char* name;
    char* post;
    double salary;
    public:
    //costructor 
    Worker();
    ~Worker(){
        delete[] name;
        delete[] post;
    }
    Worker(char* name_, char* post_, double salary_) {
        this->name = name_;
        this->post = post_;
        this->salary = salary_;
    }
    Worker(const Worker & a){
        this->name = a.name;
        this->post = a.post;
        this->salary = a.salary;
    }

    //get set
    char* getName() {return this->name;}
    char* getPost() {return this->post;}
    double getSalary() {return this->salary;}

    void setName(char* name_){
        this->name = new char[strlen(name_)];
        strcpy(this->name, name_);
    }
    void setPost(char* post_){
        this->post = new char[strlen(post_)];
        strcpy(this->post, post_);
    }
    void setSalary(double salary_) {this->salary = salary_;}

    // Операторы
    void operator= (const Worker& b){
        this->name =new char[strlen(b.name)];
        strcpy(this->name, b.name);
        this->post =new char[strlen(b.post)];
        strcpy(this->post, b.post);
        this->salary = b.salary;
    }



};

std::ostream& operator << (std::ostream& os, Worker& a) {
    return os << a.getName() << ' ' << a.getPost() << ' ' << a.getSalary() << std::endl;
}

std::istream& operator >> (std::istream& in, Worker& a) {
    char* name_;
    char* post_;
    double salary_;
    in >> name_ >> post_ >> salary_;
    if (in){
        a.setName(name_);
        a.setPost(post_);
        a.setSalary(salary_);
    }
    return in;
}


Worker func(Worker a){
    return a;
}
void func2(Worker b){
    std::cout << b.getName();
}

int main(){
    Worker a = {(char*) "aboba", (char*) "abobaaa", (double) 1.2};
    Worker b = a;
    func(b);
    func2(b);

}