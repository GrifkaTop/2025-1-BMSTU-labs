#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

const int ACCURACY = 4  ;

class Fraction{
    private:
        int numerator; //числитель
        int denominator; //знаменатель
    public:
        Fraction() : numerator(0), denominator(1){};
        Fraction(int numerator_, int denomtator_) : numerator(numerator_), denominator(denomtator_) {};
        Fraction(int numerator_) : denominator(1), numerator(numerator_) {};
        Fraction (double a);
        Fraction (char* string);

        void setNumerator(int a);
        void setDenominator(int a);
        int getNumerator() const;
        int getDenominator() const;
        Fraction operator+ (const Fraction& f) const;
        Fraction& operator+= (const Fraction& f) ;
        Fraction operator+ (int a) const;
        Fraction& operator+= (int a) ;
        friend Fraction operator+ (const Fraction& l, const Fraction& r) ;
        void shorten();
        void print();

        friend std::ostream& operator << (ostream& os, Fraction& a);
        friend std::istream& operator >> (istream& in, Fraction& a);
};

int gcd (int a, int b);
int lcm (int a, int b);
