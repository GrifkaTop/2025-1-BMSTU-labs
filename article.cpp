#include "article.hpp"

Article::Article(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    std::cout << "Article(\"" << name << "\")" << std::endl;
}

Article::~Article() {
    std::cout << "~Article(\"" << name << "\")" << std::endl;
    delete[] name;
}

Product::Product(const char* name, const char* date) : Article(name) {
    production_date = new char[strlen(date) + 1];
    strcpy(production_date, date);
    std::cout << "Product(\"" << name << "\", " << date << ")" << std::endl;
}

Product::~Product() {
    delete[] production_date;
    std::cout << "~Product(\"" << name << "\")" << std::endl;
}

void Product::show() const {
    std::cout << "Product: " << name 
              << ", Production date: " << production_date << std::endl;
}

Dairy::Dairy(const char* name, const char* date, int expiry) 
    : Product(name, date), expiry_days(expiry) {
    std::cout << "Dairy(\"" << name << "\", " << date << ", " << expiry << " days)" << std::endl;
}

Dairy::~Dairy() {
    std::cout << "~Dairy(\"" << name << "\")" << std::endl;
}

void Dairy::show() const {
    std::cout << "Dairy product: " << name 
              << ", Production date: " << production_date
              << ", Expires in " << expiry_days << " days" << std::endl;
}

Toy::Toy(const char* name, int age) : Article(name), recommended_age(age) {
    std::cout << "Toy(\"" << name << "\", age: " << age << "+)" << std::endl;
}

Toy::~Toy() {
    std::cout << "~Toy(\"" << name << "\")" << std::endl;
}

void Toy::show() const {
    std::cout << "Toy: " << name 
              << ", Recommended age: " << recommended_age << "+" << std::endl;
}

Bear::Bear(const char* name, int age, const char* color) 
    : Toy(name, age) {
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    std::cout << "Bear(\"" << name << "\", " << age << "+, " << color << ")" << std::endl;
}

Bear::~Bear() {
    delete[] color;
    std::cout << "~Bear(\"" << name << "\")" << std::endl;
}

void Bear::show() const {
    std::cout << "Toy bear: " << name 
              << ", Recommended age: " << recommended_age << "+"
              << ", Color: " << color << std::endl;
}