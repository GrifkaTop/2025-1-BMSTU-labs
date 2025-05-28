#include "article.hpp"

Article::Article(const std::string& name) : name(name) {
    std::cout << "Article(\"" << name << "\")" << std::endl;
}
Article::~Article() {
    std::cout << "~Article(\"" << name << "\")" << std::endl;
}

Product::Product(const std::string& name) : Article(name) {
    std::cout << "Product(\"" << name << "\")" << std::endl;
}
Product::~Product() {
    std::cout << "~Product(\"" << name << "\")" << std::endl;
}
void Product::show() const {
    std::cout << "Product: " << name << std::endl;
}

Dairy::Dairy(const std::string& name) : Product(name) {
    std::cout << "Dairy(\"" << name << "\")" << std::endl;
}
Dairy::~Dairy() {
    std::cout << "~Dairy(\"" << name << "\")" << std::endl;
}
void Dairy::show() const {
    std::cout << "Dairy product: " << name << std::endl;
}

Toy::Toy(const std::string& name) : Article(name) {
    std::cout << "Toy(\"" << name << "\")" << std::endl;
}
Toy::~Toy() {
    std::cout << "~Toy(\"" << name << "\")" << std::endl;
}
void Toy::show() const {
    std::cout << "Toy: " << name << std::endl;
}

Bear::Bear(const std::string& name) : Toy(name) {
    std::cout << "Bear(\"" << name << "\")" << std::endl;
}
Bear::~Bear() {
    std::cout << "~Bear(\"" << name << "\")" << std::endl;
}
void Bear::show() const {
    std::cout << "Toy bear: " << name << std::endl;
}