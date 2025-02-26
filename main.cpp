#include <iostream>
#include "database.hpp"

using namespace std;


void printMenu(){
    cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - добавление \t\t 5 - вывод базы на экран " << endl;
    cout << "2 - удаление \t\t 6 -вывод базы в файл " << endl;
    cout << "3 - корректировка \t\t 7 - ввод базы из файл" << endl;
    cout << "4 - сортировка\t\t 8 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 8" << endl;
    cout << " =====================================================\n";
}

template<typename T> void menuCase(Database<T>& db){
    while(true) {
        printMenu();
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            {
            cout << "Введите данные: ";
            T a;
            cin >> a;
            cout  << endl;
            db.push(a);
            }
            break;
        case 2:
            {
            cout << "Введите id: ";
            int id;
            cin >> id;
            db.del(id);
            cout << endl;
            }
            break; 
        case 3:
            {
            cout << "Введите id: ";
            int id;
            cin >> id;
            cout << endl;
            cout << "Введите данные: ";
            T a;
            cin >> a;
            cout << endl;
            db.change(id, a);
            }
            break;
        case 4:
            
            db.Database<T>::srt();
            break;
        case 5:
            db.Database<T>::print();
            break;
        case 6:
            db.Database<T>::writeFile();
            break;
        case 7:
            db.Database<T>::readFile();
            break;
        default:
            return;
        }
    }
}



int main(){
    Database<Planet> db1;
    menuCase<Planet>(db1);
}