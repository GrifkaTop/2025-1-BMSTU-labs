#include <iostream>
#include <iomanip>
#include <string>
#include <ostream>

using namespace std;

class Person{
    public:
        //int id;

        char name[30];
        char surename[30];
        Equipment *equipment{};
    private:
        Person(char* name_, char* surname_){
            strcpy(name, name_);
            strcpy(surename, surname_);
        } 

};

class Equipment{
    private:
        char name[30];
        int count = 0;
        double price = 0;
    public:
        Equipment(){

        }
        Equipment(char* name_, int count_, double price_){
            strcpy(name, name_);
            count = count_;
            price = price_;
        }

        /*
        istream& operator >> (ostream& in){
            return in >> name >> count >> price;
        } */


        void setName(char* name_){
            strcpy(name, name_);
        }
        char* getName() { return name; }
        void setCount(int count_){ count = count_; }
        int getCount() { return count; }
        void setPrice(int price_){ price = price_; }
        double getPrice() { return price; }

        friend ostream &operator << (ostream& os, const Equipment &e){
            return os <<  e.name << ' ' << e.count << ' ' << e.price << '\n';
        }

};



int main(){
    //1
    Equipment e2 {};
    cout << e2;
    e2.setCount(1);
    cout << e2;
    //2
    int count;
    double price;
    char* name;
    cin >> name >> count >> price;
    Equipment e1 {name, count, price};
    cout << e1;
    e1.setCount(1);
    cout << e1;
    //3 - 4
    Equipment *e4 = new Equipment;
    cout << e4;
    e4->setCount(3);
    cout << e4;
}