#include <iostream>
#include <string>
#include "MyStack.hpp"
#include <cmath>

using namespace std;


void func(int x, MyStack<int> &a){
    for (int i = 2; i <= sqrt(x); ){
        if (x % i == 0){
            a.push(i);
            x/=i;
        }
        else{
            i++; 
        }
    }
    if (x != 1){
        a.push(x);
    }
}

template<typename T> void reversee(MyStack<T> &a){
    MyStack<int> c;
    while(!a.empty()){
        c.push((int) a.top_inf());
        a.pop();
    }
    a = c;
}

template<typename T> void print(MyStack<T> &a){
    if (!a.empty()){
        cout << a.top_inf() << ' ';
        a.pop();
    }
    while (!a.empty()) {
        cout << "* " << a.top_inf() << ' ' ;
        a.pop();
    }
    cout << '\n';
}

void func2(int x){
    if (x <= 1) {
        cout << "непопался\n";
        return;
    }
    MyStack<int> a;
    func(x, a);
    MyStack<int> b = a;
    reversee(a);
    cout << x << ':' << ' ';
    print<int>(a);
    cout << x << ':' << ' ';
    print<int>(b);
}






int tests_passed = 0;  // счетчик успешных тестов

void print_test_result(bool condition, const std::string& test_name) {
    if (condition) {
        std::cout << "[OK] " << test_name << "\n";
        tests_passed++;
    } else {
        std::cout << "[FAIL] " << test_name << "\n";
    }
}

int main() {
    /*
    // Тест 1: Проверка пустого стека
    {
        MyStack<int> stack;
        print_test_result(stack.empty() == true, "Test 1: Empty stack");
    }

    // Тест 2: Добавление и извлечение одного элемента
    {
        MyStack<int> stack;
        bool check = true;
        
        stack.push(10);
        check = check && (stack.empty() == false);
        check = check && (stack.top_inf() == 10);
        
        stack.pop();
        check = check && (stack.empty() == true);
        
        print_test_result(check, "Test 2: Single element");
    }

    // Тест 3: Несколько элементов (порядок LIFO)
    {
        MyStack<std::string> stack;
        bool check = true;
        
        stack.push("first");
        stack.push("second");
        stack.push("third");
        
        check = check && (stack.top_inf() == "third"); stack.pop();
        check = check && (stack.top_inf() == "second"); stack.pop();
        check = check && (stack.top_inf() == "first"); stack.pop();
        check = check && (stack.empty() == true);
        
        print_test_result(check, "Test 3: LIFO order");
    }

    // Тест 4: Попытка извлечения из пустого стека
    {
        MyStack<double> stack;
        bool check = true;
        
        check = check && (stack.pop() == false);  // Нельзя извлечь из пустого стека
        print_test_result(check, "Test 4: Pop from empty stack");
    }

    // Тест 5: Нагрузочный тест (100 элементов)
    {
        MyStack<int> stack;
        bool check = true;
        
        for(int i = 0; i < 100; i++) stack.push(i);
        for(int i = 99; i >= 0; i--) {
            check = check && (stack.top_inf() == i);
            stack.pop();
        }
        check = check && stack.empty();
        
        print_test_result(check, "Test 5: Stress test (100 elements)");
    }

    // Тест 6: Разные типы данных
    {
        bool check = true;
        
        MyStack<char> char_stack;
        char_stack.push('X');
        check = check && (char_stack.top_inf() == 'X');
        
        MyStack<double> double_stack;
        double_stack.push(3.1415);
        check = check && (double_stack.top_inf() == 3.1415);
        
        print_test_result(check, "Test 6: Different data types");
    }
    // Тест 7: Конструктор копирования
{
    MyStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    MyStack<int> copy(original);  // используем конструктор копирования
    
    bool check = true;
    check = check && (copy.top_inf() == 3); copy.pop();
    check = check && (copy.top_inf() == 2); copy.pop();
    check = check && (copy.top_inf() == 1); copy.pop();
    check = check && copy.empty();
    
    // Проверяем, что оригинал не изменился
    check = check && (original.top_inf() == 3);
    
    print_test_result(check, "Test 7: Copy constructor");
}

// Тест 8: Оператор присваивания
{
    MyStack<int> source;
    source.push(10);
    source.push(20);

    MyStack<int> target;
    target.push(999);  // старые данные должны быть удалены
    
    target = source;  // используем оператор присваивания
    
    bool check = true;
    check = check && (target.top_inf() == 20); target.pop();
    check = check && (target.top_inf() == 10); target.pop();
    check = check && target.empty();
    
    // Проверяем самоприсваивание
    source = source;
    check = check && (source.top_inf() == 20);
    
    print_test_result(check, "Test 8: Assignment operator");
} */
    MyStack<char> source;
    auto c = source;
    source.push('a');
    source.push('b');
    source.push('c');
    source.print(); cout << '\n';
    c = source;
    auto k(source);
    c.print(); cout << '\n';
    k.print(); cout << '\n';
    int a = 0;
    cin >> a;
    func2(a);
    
    return 0;
}
