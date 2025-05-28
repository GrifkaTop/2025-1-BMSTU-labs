#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>

using namespace std;

template <typename T>
void print(const std::list<T>& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
template <typename T>
void print(const std::vector<T>& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
template <typename T, typename U>
void print(const std::map<T, U>& container) {
    for (const auto& elem : container) {
        std::cout << elem.first << ' ' << elem.second << " ";
    }
    std::cout << "\n";
}


//4
void task4(std::list<int>& lst) {
    for (auto& elem : lst) {
        elem *= 2;
    }
}

//4
void umnogeenie(vector<int> &vec){
    for (int i = 0; i < 5; i++) vec[i]*=2;
}


//5
class Complex {
private:
    double real_;
    double imag_;

public:
    Complex(double real = 0.0, double imag = 0.0) : real_(real), imag_(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real_ + other.real_, imag_ + other.imag_);
    }

    Complex& operator+=(const Complex& other) {
        real_ += other.real_;
        imag_ += other.imag_;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    // Вывод вещественной части
    if (c.real_ == static_cast<int>(c.real_)) {
        os << static_cast<int>(c.real_);
    } else {
        os << c.real_;
    }

    // Вывод мнимой части
    if (c.imag_ >= 0) {
        os << " + i * ";
    } else {
        os << " - i * ";
    }

    double imag_abs = std::abs(c.imag_);
    if (imag_abs == static_cast<int>(imag_abs)) {
        os << static_cast<int>(imag_abs);
    } else {
        os << imag_abs;
    }

    return os;
}

//7
class Rectangle {
    double a;  // ширина
    double b;  // длина
   public:
    Rectangle() : a(0), b(0) {}
    Rectangle(double a, double bi) : a(a), b(b) {}
    double area() const {
        return a * b;
    }
    double getA(){
        return a;
    }
    double getB(){
        return b;
    }
    bool operator<(const Rectangle& other) const {
        double thisArea = area();
        double otherArea = other.area();
        if (thisArea != otherArea) 
            return thisArea < otherArea;
        if (a != other.a)
            return a < other.a;
        return b < other.b;
    }

    bool operator==(const Rectangle& other) const {
        return a == other.a && b == other.b;
    }
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect){
        os << rect.a << " " << rect.b;
        return os;
    }
  };

int main() {
    std::mt19937 gen(std::time(nullptr));
    std::uniform_int_distribution<int> dist(0, 100);
    {
        /*1 Пользователь вводит 3 слова в 3-х разных переменных. Образовать новую последовательность символов, 
        состоящую из первых букв каждого слова (через пробел).*/
        cout << '\n';
        string a, b, c;
        cin >> a >> b >> c;
        cout << a[0] +' ' + b[0]+ ' ' + c[0];
        cout << '\n';
    }
    {
        /*2 В предложении, вводимом с клавиатуры в одну переменную, поменять местами первое и последнее слова 
        (не использовать find и использование функции substr()).*/
        cout << '\n';
        string s;
        getline(cin, s);
        int id = 0, id2 = s.size()-1;
        while (id < s.size() || s[id] != ' '){
            id++;
        }
        while (id2 >= 0|| s[id2] != ' '){
            id2--;
        }
        cout << s.substr(id2+1, s.size()) + s.substr(id, id2 - id) + s.substr(0, id-1);
        cout << '\n';
    }
    {
        /*3 Дан текстовый файл. Запишите в другой файл содержимое исходного файла, в начале каждой строки добавив e-mail:.*/
        std::ifstream ci ("input.txt");
        std::ofstream co ("output.txt");
        string s;
        while (getline(ci, s)){
            co << "email: " << s;
        }
    }
    {
        /*4 Создать вектор из 5-ти целых случайных чисел (00 - 100100). Распечатать. 
        Удвоить каждое число в векторе. Распечатать. Удалить из вектора элемент с индексом 2 и снова распечатать вектор. 
        Переделать программу: удвоение сделать с помощью функции и печатать вектор с помощью функции.*/
        vector<int> vec(5);
        for (int i = 0; i < 5; i++){
            vec[i] = dist(gen);
        }
        print(vec);
        umnogeenie(vec);
        print(vec);
        vec.erase(vec.begin() + 2);
        print(vec);
    }
    {
        /*5 Составить описание класса Complex для представления комплексных чисел с возможностью задания вещественной и мнимой частей числами типа double. В программе создать вектор из объектов класса Complex (6 элементов): (-1.2, 6.3), (4.0, 0.7), (7.2, -0.8), (5.3, 3.0), (-4.9, 6.6), (-9.3, 0.2).

        Распечатать вектор в виде:

        -1.2 + i * 6.3
        4.1 + i * 0.7
        7.2 - i * 0.8
        5.3 + i * 3
        -4.9 + i * 6.6
        -9.3 + i * 0.2

        Сложите все числа (у комплексных чисел отдельно складываются действительные и мнимые части) и результирующее число выведите на экран.*/
        std::vector<Complex> vec = {
            Complex(-1.2, 6.3),
            Complex(4.0, 0.7),
            Complex(7.2, -0.8),
            Complex(5.3, 3.0),
            Complex(-4.9, 6.6),
            Complex(-9.3, 0.2)
        };

        for (const Complex& c : vec) {
            std::cout << c << std::endl;
        }

        Complex sum;
        for (const Complex& c : vec) {
            sum += c;
        }

        std::cout << sum << std::endl;
    }



    
    {
        /*6 Создать контейнер из 5-ти целых случайных чисел (00 - 100100). Распечатать. Удвоить каждое число в контейнере. 
        Распечатать. Удалить из контейнера элемент с индексом 2 и снова распечатать контейнер. Переделать программу: 
        удвоение сделать с помощью функции и печатать контейнер с помощью функции.*/
        std::cout << "\n===== Task 4 =====\n";
        std::list<int> lst;
        for (int i = 0; i < 5; ++i) {
            lst.push_back(dist(gen));
        }
        
        print(lst);
        
        task4(lst);
        print(lst);
        if (lst.size() > 2) {
            auto it = lst.begin();
            std::advance(it, 2);
            lst.erase(it);
        }
        print(lst);
    }
    {
        /*7 Ниже представлен пример класса Rectangle (прямоугольник). Напишите программу для хранения объектов типа Rectangle в list 
        (подсказка: не забудьте для класса Rectangle определить операторы < и ==):

        Создать список объектов типа Rectangle с помощью контейнера list в main() и сразу занести в него информацию о 6 объектах: 
        (1.2, 6.3), (4.0, 0.7), (7.2, 0.8), (5.3, 3.0), (4.9, 6.6), (9.3, 0.2).
        Вывести список на экран таким образом, чтобы размеры каждого прямоугольника выводились в отдельной строке. Выведите на экран размеры прямоугольника, 
        у которого наибольшая площадь. Напишите функцию вывода списка на экран.*/

        std::list<Rectangle> rectangles = {
        Rectangle(1.2, 6.3),
        Rectangle(4.0, 0.7),
        Rectangle(7.2, 0.8),
        Rectangle(5.3, 3.0),
        Rectangle(4.9, 6.6),
        Rectangle(9.3, 0.2)
        };

        std::cout << "List of rectangles:\n";
        print(rectangles);

        auto maxIt = std::max_element(rectangles.begin(), rectangles.end());
        if (maxIt != rectangles.end()) {
            std::cout << "\nRectangle with the largest area:\n";
            std::cout << maxIt->getA() << " " << maxIt->getB() << std::endl;
        }


    }
    {
        /*8Создайте отображение map<string, int> и занесите в него пары "one" - 100, "two" - 200, "three" - 300, ..., "six" - 600. 
        Выведите содержимое отображения на экран. Удалить пары с ключами "five" и "six" и снова распечатайте отображение.*/
        map<string, int> numbers = {
            {"one", 100}, {"two", 200}, {"three", 300},
            {"four", 400}, {"five", 500}, {"six", 600}
        };
        print(numbers);
        numbers.erase("five");
        numbers.erase("six");
        print(numbers);
    }
    {
        /*9 Создайте ассоциативный контейнер для хранения имен абонентов и их телефонных номеров. 
        Имена и номера телефонов должны вводиться пользователем. После окончания ввода распечатать имена и телефонные номера абонентов в виде строк: 
        имя абонента – его номер. Выполнить поиск номера по имени абонента, которое введет пользователь. 
        Удалите найденный номер и имя абонента из отображения. Снова распечатайте отображение. Переделать программу: печатать отображение с помощью функции.*/
        map<string, string> phonebook;
        string name, phone;

        cout << "Введите имена и номера телефонов (для завершения введите 'end' в качестве имени):" << endl;
        while (true) {
            cout << "Имя: ";
            getline(cin, name);
            if (name == "end") break;
            
            cout << "Номер: ";
            getline(cin, phone);
            
            phonebook[name] = phone;
        }

        cout << "\nТелефонная книга:" << endl;
        print(phonebook);

        cout << "\nВведите имя для поиска и удаления: ";
        getline(cin, name);
        
        auto it = phonebook.find(name);
        if (it != phonebook.end()) {
            phonebook.erase(it);
            cout << "Абонент '" << name << "' удален." << endl;
        } else {
            cout << "Абонент '" << name << "' не найден!" << endl;
        }

        cout << "\nОбновленная телефонная книга:" << endl;
        print(phonebook);
    }
    
    return 0;
}