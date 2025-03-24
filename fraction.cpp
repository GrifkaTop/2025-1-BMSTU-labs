#include "fraction.hpp"

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

/* ------------------------------------------------*/

Fraction::Fraction(double a){
    this->denominator = pow(10, ACCURACY);
    a *= denominator;
    this->numerator = a;
}

Fraction::Fraction(char* string) {
    while (*string == ' ') {
        string++;
    }
    char* whitespace = strchr(string, ' ');
    char* slash = strchr(string, '/');
    //cout << string << '|' << whitespace << '|' << slash << '\n';
    if (!slash) {
        //cout << "1\n"; 
        numerator = atoi(string);
        denominator = 1;
    } else if (!whitespace || whitespace > slash) {
        //cout << "2\n"; 
        numerator = atoi(string);
        denominator = atoi(slash + 1);
    } else {
        //cout << "3\n"; 
        int integerPart = atoi(string);
        //cout << integerPart << '\n';
        numerator = atoi(whitespace + 1);
        numerator = (integerPart < 0) ? -numerator : numerator;
        denominator = atoi(slash + 1);
        //cout << denominator << ' ';
        numerator += integerPart * denominator;
    }

    if (denominator == 0){
        throw "Ошибка че то не то ввел";
    }
}

/* ------------------------------------------------*/

void Fraction::setNumerator(int a) {
    this->numerator = a;
}
void Fraction::setDenominator(int a) {
    this->denominator = a;
}
int Fraction::getDenominator() const {
    return this->denominator;
}
int Fraction::getNumerator() const {
    return this->numerator;
}

/* ------------------------------------------------*/

Fraction Fraction::operator+ (const Fraction& f) const{
    Fraction c = *this;
    c += f;
    return c;
}

Fraction& Fraction::operator+= (const Fraction& f) {
    int buf_d = lcm(this->denominator, f.denominator);
    this->numerator = this->numerator*(buf_d/f.denominator) + f.numerator*(buf_d/this->denominator);
    this->denominator = buf_d;
    return *this;
}

Fraction Fraction::operator+ (int a) const{
    Fraction c = *this;
    c += a;
    return c;
}

Fraction& Fraction::operator+= (int a) {
    this->numerator += this->denominator*a;
    return *this;
}

Fraction operator+ (const Fraction& l, const Fraction& r)  {
    Fraction c = l;
    c += r;
    return c;
}

/*-------------------------------------------------------*/

void Fraction::shorten () {
    int g = gcd(this->numerator, this->denominator);
    numerator /= g;
    denominator/=g;
    if (denominator < 0){
        denominator *= -1;
        numerator *= -1;
    }
}

void Fraction::print() {
    this->shorten();
    int whole = this->numerator / this->denominator;
    if (whole != 0) {
        cout << whole << ' ';
    }
    int num = this->numerator % this->denominator;
    if (num != 0){
        cout << num << '/' << this->denominator << ' ';
    }
    if (whole == 0 && num == 0) {
        cout << 0;
    }
}

/*******************************************************/

ostream& operator << (ostream& os, Fraction& a) {
    a.shorten();
    int num = a.numerator;
    int den = a.denominator;
    int whole = num / den;
    if (whole != 0) {
        os << whole << ' ';
    }
    num = num % den;
    if (num != 0){
        if (whole < 0) num *= -1;
        os << num << '/' << den << ' ';
    }
    if (whole == 0 && num == 0) {
        os << 0;
    }
    return os;
}


bool checkStr(char* str) {
        if (strlen(str) == 0){
            return false;
        }
    int len_num = 0;

    int count = 0;
    for (int i = 0;i < strlen(str);i++){
        if (str[i] == '-'){
            count ++;
            if (count > 1){
                return false;
            }
        }
        if (isalpha(*str)){
            return false;
        }
        if (isdigit(*str) && (*str != '0' || len_num > 0)){
            len_num++;
        }
        else {
            len_num = 0;
        }

        if (len_num == 10){
            return false;
        }
    }

    return true;
}

istream& operator>>(istream& is, Fraction& fraction) {
    char* str = new char[1024];

    is.getline(str, 1024);

    if (!checkStr(str)) {
        throw  "-_-";
    }
    try{
        fraction = Fraction(str);
    }
    catch(const char* error_message){
        std::cout << error_message << std::endl;
        exit(0);
    }
    delete[] str;

    return is;
}