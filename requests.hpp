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
        int* id_employees;
        int size_employees;
    public: 
    // Конструктор и Деконструктор
        Requests() : id_application(0), task_description(nullptr), id_employees(nullptr), size_employees(0){}
        ~Requests();
        Requests(int id_application_, char* task_description_, int* id_employees_, int size_employees_);
        Requests(const Requests &r) ;
    /// Перегрузка оперторов
        bool operator < (Requests& b) ;
        void operator= (const Requests& b) ;
    //set get
        int getIdApplication() ;
        char* getTaskDesciption();
        std::pair<int, int*> getIdEmployees() ;
        void setIdApplication(int id_application_);
        void setTaskDescription(char* task_description_);
        void setIdEmployees(int size_employees_, int* id_employees_) ;
        void setAll(int id_application_, char* task_description_, int* id_employees_, int size_employees_);
};

ostream& operator << (ostream& os, Requests& a);
istream& operator >> (istream& in, Requests& a);