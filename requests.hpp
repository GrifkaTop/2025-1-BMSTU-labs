#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <utility>


using namespace std;

class Requests{
    private:
        int id_application; // значение уникально
        char* task_description;
        int id_employee;
    public: 
    // Конструктор и Деконструктор
        Requests() : id_application(0), 
                    task_description(nullptr), 
                    id_employee(0) {}
        ~Requests();
        Requests(int id_application_, char* task_description_, int id_employee);
        Requests(const Requests &r) ;
    /// Перегрузка оперторов
        bool operator < (Requests& b) ;
        Requests& operator= (const Requests& b) ;
    //set get
        int getIdApplication() const;
        char* getTaskDesciption() const;
        int getIdEmployee() const;
        void setIdApplication(const int id_application_);
        void setTaskDescription(const char* task_description_);
        void setIdEmployee(const int id_employee_) ;
        void setAll(const int id_application_, const char* task_description_, const int id_employee_);
};

ostream& operator << (ostream& os, const Requests& r);
istream& operator >> (istream& in, Requests& r);