#include "requests.hpp"

Requests::~Requests() {
    delete[] this->task_description;
}
Requests::Requests(int id_application_, char* task_description_, int id_employee_) {
    this->id_application = id_application_;
    this->task_description = new char[strlen(task_description_)+1];
    strcpy(this->task_description, task_description_);
    this->id_employee = id_employee_;
}

Requests::Requests(const Requests &r) {
    this->id_application = r.id_application;
    this->task_description = new char[strlen(r.task_description)+1];
    strcpy(this->task_description, r.task_description);
    this->id_employee = r.id_employee;
}
/// Перегрузка оперторов
bool Requests::operator < (Requests& r) {
    return this->id_application < r.id_application;
}

Requests& Requests::operator= (const Requests& r) {
    if (this == &r) return *this;
    this->id_application = r.id_application;
    delete[] task_description;
    this->task_description = new char[strlen(r.task_description)+1];
    strcpy(this->task_description, r.task_description);
    this->id_employee = r.id_employee;
    return *this;
}

// get и set
int Requests::getIdApplication()const   {
    return this->id_application;
}
char* Requests::getTaskDesciption() const {
    return this->task_description;
}
int Requests::getIdEmployee() const{
    return this->id_employee;
} 

void Requests::setIdApplication(int id_application_) {
    this->id_application = id_application_;
}
void Requests::setTaskDescription(const char* task_description_) {
    this->task_description = new char[strlen(task_description_)+1];
    strcpy(this->task_description, task_description_);
}
void Requests::setIdEmployee(const int id_employee_) {
    this->id_employee = id_employee_;
}
void Requests::setAll(const int id_application_, const char* task_description_, const int id_employee_) {
    this->id_application = id_application_;
    this->task_description = new char[strlen(task_description_)+1];
    strcpy(this->task_description, task_description_);
    this->id_employee =  id_employee_;
}

ostream& operator << (ostream& os,  const Requests& r) {
    os << r.getIdApplication() << ' ' << r.getTaskDesciption() << ' ' << r.getIdEmployee() << endl;
    return os;
}

istream& operator >> (istream& in, Requests& r) {
    int id_application_;
    char* task_description_ = new char[1000+1];
    int id_employee_;
    in >> id_application_ >> task_description_ >> id_employee_;
    if (in){
        r.setAll(id_application_, task_description_, id_employee_);
    }
    return in;
}

