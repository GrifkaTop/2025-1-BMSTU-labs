#include <iostream>
#include "database.hpp"
#include "planet.hpp"
#include "requests.hpp"
using namespace std;


void printMenu(){
    cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - добавление \t\t 5 - вывод базы на экран " << endl;
    cout << "2 - удаление \t\t 6 -вывод базы в файл " << endl;
    cout << "3 - корректировка \t 7 - ввод базы из файла" << endl;
    cout << "4 - сортировка\t\t 8 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 8" << endl;
    cout << " =====================================================\n";
}

template<typename T> void menuCase(Database<T>& db){
    while(true) {
        printMenu();
        //db.print();
        int n;
        cin >> n;
        T a;
        int id;
        switch (n)
        {
        case 1:
            
            cout << "Введите данные: ";
            cin >> a;
            cout << endl;
            db.push(a);
            
            break;
        case 2:
            
            cout << "Введите id: ";
            cin >> id;
            if (id >= db.size || id < 0){
                cout << "Такого нет\n";
                break;
            }
            db.del(id);
            cout << endl;
            
            break; 
        case 3:
            
            cout << "Введите id: ";
            cin >> id;
            cout << endl;
            if (id >= db.size || id < 0){
                cout << "Такого нет\n";
                break;
            }
            db.change(id);
            
            break;
        case 4:
            db.srt();
            break;
        case 5:
            db.Database<T>::print();
            break;
        case 6:
            db.Database<T>::writeFile((char*) "/home/grifka/2025-1 BMSTU labs/2025-1-BMSTU-labs/1.txt");
            break;
        case 7:
            db.Database<T>::readFile((char*) "/home/grifka/2025-1 BMSTU labs/2025-1-BMSTU-labs/base.txt");
            break;
        default:
            break;
        }
    }
}



int main(){
    int a;
    cin >> a;
    if (a == 1){
        Database<Planet> db1;
        menuCase<Planet>(db1);
    }
    else {
        Database<Requests>db2;
        menuCase<Requests>(db2);
    }
    return 0;
}
