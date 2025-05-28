#include <iostream>
#include "polynomal.hpp"

int main() {
    Term a(-1, -3);
    Term b(10, 3);

    Polynomial p1;
    std::cin >> p1;
    std::cout << p1 << '\n';
    Polynomial p2;
    std::cin >> p2;
    std::cout << p2 << '\n';
    Polynomial p3 = (p1+p2);
    Polynomial p4 = (p1 - p2);
    Polynomial p5 = (p1*p2);
    std::cout << p3 << '\n' << p4 << '\n' << p5 ;

/*
    Polynomial p5;
    std::cin >> p5;
    std::cout << p5 << '\n';

    Polynomial p6 = (p5 + p5);
    std::cout << p6 << '\n';*/

    return 0;
}