#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T> class Database{
    private:
        const int OVERFLOW_DB = 100;
    public:
        int size = 0;
        T *arr;
        Database(){
            arr =nullptr;
        };
        Database(int size_){
            size = size_;
            T* arr = new T[size];
        }
        ~Database(){
            delete[] arr;
        }
        
        int readFile (const char* filename) {
            ifstream fin(filename, ios::in);
            if (!fin) {
                cout << "Heт файла " << filename<< endl;
                return 1;
            }
            int n;
            fin >> n;
            if (n > OVERFLOW_DB) {
                cout << "Переполнение БД. n= " << n << endl;
                return 1;
            }
            size = n;
            arr = new T[size];
            for (int i = 0; i < size; i++) {
                fin >> arr[i];
            }

            fin.close();
            return 0;
        }
        
        int writeFile (char* filename) {
            ofstream fout(filename, ios::out); // авто удаление
            if (!fout) {
                cout << "Ошибка открытия файла" << endl;
                return 1;
            }
            fout << size << endl;
            for (int i = 0; i < size; i++)
                fout << arr[i];
            fout.close();
            return 0;
        }
        
        
        void srt(){
            for (int i = 0; i < size; i++){
                int id = i;
                for (int j = i+1; j < size; j++) {
                    if (arr[j] < arr[id]){
                        id = j;
                    }
                }
                if (id != i){
                    std::swap(arr[i], arr[id]);
                }
            }
        }
        
        
        /*
        добавление нового объекта в БД;
        удаление объекта из БД;
        редактирование БД;
        вывод БД на экран.
        */
        
        int push(T &a){
            if (size > OVERFLOW_DB){
                cout << "ПЕРЕПОЛНЕНИЕ\n";
                return 1;
            }
            size++;
            T* buff = new T[size];
            copy(arr + 0, arr + size-1, buff);
            buff[size-1] = a;
            T* old = arr;
            arr = buff;
            delete[] old;
            return 0;
        }
        
         int del(int id) {
            if (id >= size || id < 0) {
                cout << "Нет ТАКОГО!\n";
                return 1;
            }
            size--;
            T* buff = new T[size];
            for (int i = 0; i < id; i++){
                buff[i] = arr[i];
            }
            for (int i = id + 1; i < size + 1; i++){
                buff[i-1] = arr[i];
            }
            arr = new T[size];
            for (int i = 0; i < size; i++){
                arr[i] = buff[i];
            }
            delete[] buff;
            return 0;
        }
        
        void change(int id){
            T a;
            cout << "Введите данные: ";
            cin >> a;
            cout << endl;
            change(id, a);
            return;
        }

        void change(int id, T a) {
            if (id >= size || id < 0) {
                cout << "Нет ТАКОГО!\n";
                return;
            }
            arr[id] = a;
            return;
        }
        
        void print() {
            if (size == 0){
                cout << "Ничего нет\n";
                return;
            }
            cout << size << endl; 
            for (int i = 0; i < size; i++){
                cout << arr[i];
            }
            return;
        }

        void print(int id) {
            if (id >= size){
                cout << "Такого элемента нет\n";
                return;
            }
            cout << arr[id];
        }
        
        T get(int id){
            return arr[id];
        }
};
