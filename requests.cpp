#include "requests.hpp"

Requests::~Requests() {
    delete[] this->task_description;
    delete[] this->id_employees;
}
Requests::Requests(int id_application_, char* task_description_, int* id_employees_, int size_employees_) {
    this->id_application = id_application_;
    this->task_description = new char[strlen(task_description_)+1];
    strcpy(this->task_description, task_description_);
    this->id_employees = new int[size_employees_];
    for (int i = 0; i < size_employees_; i++) {
        id_employees[i] = id_employees_[i];
    }
}

Requests::Requests(const Requests &r) {
    this->id_application = r.id_application;
    this->task_description = new char[strlen(r.task_description)+1];
    strcpy(this->task_description, r.task_description);
    this->id_employees = new int[r.size_employees];
    for (int i = 0; i < r.size_employees; i++) {
        id_employees[i] = r.id_employees[i];
    }
}
/// Перегрузка оперторов
bool Requests::operator < (Requests& r) {
    return this->id_application < r.id_application;
}

void Requests::operator= (const Requests& r) {
    this->id_application = r.id_application;
    this->task_description = new char[strlen(r.task_description)+1];
    strcpy(this->task_description, r.task_description);
    this->id_employees = new int[r.size_employees];
    for (int i = 0; i < r.size_employees; i++) {
        id_employees[i] = r.id_employees[i];
    }
}

// get и set
int Requests::getIdApplication() {
    return this->id_application;
}
char* Requests::getTaskDesciption() {
    return this->task_description;
}
std::pair<int, int*> Requests::getIdEmployees() {
    return {this->size_employees, this->id_employees};
} 

void Requests::setIdApplication(int id_application_) {
    this->id_application = id_application_;
}
void Requests::setTaskDescription(char* task_description_) {
    this->task_description = new char[strlen(task_description_)+1];
    strcpy(this->task_description, task_description_);
}
void Requests::setIdEmployees(int size_employees_, int* id_employees_) {
    this->id_employees = new int[size_employees_];
    for (int i = 0; i < size_employees_; i++) {
        id_employees[i] = id_employees_[i];
    }
}
void Requests::setAll(int id_application_, char* task_description_, int* id_employees_, int size_employees_) {
    this->id_application = id_application_;
    this->task_description = new char[strlen(task_description_)+1];
    strcpy(this->task_description, task_description_);
    this->id_employees = new int[size_employees_];
    for (int i = 0; i < size_employees_; i++) {
        id_employees[i] = id_employees_[i];
    }
}

ostream& operator << (ostream& os, Requests& r) {
    pair<int, int*> a = r.getIdEmployees();
    os << r.getIdApplication() << ' ' << r.getTaskDesciption() << ' ' << a.first << '\n';
    for (int i = 0; i < a.first; i++){
        os << a.second[i] << ' ';
    }
    return os;
}

istream& operator >> (istream& in, Requests& a) {
    int id_application_;
    char* task_description_;
    int* id_employees_;
    int size_employees_;
    in >> id_application_ >> task_description_ >> size_employees_;
    id_employees_ = new int[size_employees_];
    for (int i = 0; i < size_employees_; i++){
        in >> id_employees_[i];
    }
    if (in){
        a.setAll(id_application_, task_description_, id_employees_, size_employees_);
    }
    return in;
}

