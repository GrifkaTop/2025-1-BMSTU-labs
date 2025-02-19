#include <iostream>
#include "mymath.h"
#include "cat.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;
    cat::cat();
    return 0;
}
