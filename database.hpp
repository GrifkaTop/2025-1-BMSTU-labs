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
        Database() {
            arr  = static_cast<T*>(operator new[] (0*sizeof(T)));
        }
        Database(int size_){
            size = size_;
            arr  = static_cast<T*>(operator new[] (size_*sizeof(T)));
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
            delete[] arr;
            size = n;
            arr  = static_cast<T*>(operator new[] (size*sizeof(T)));
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
            fout << size;
            for (int i = 0; i < size; i++)
                fout << arr[i] << endl;
            fout.close();
            return 0;
        }
        
        
        void srt(bool r = false){
            if (r)
                sort(arr + 0, arr + size);
            else
                sort(arr + size, arr + 0);
            return;
        }
        
        
        /*
        добавление нового объекта в БД;
        удаление объекта из БД;
        редактирование БД;
        вывод БД на экран.
        */
        
        int push(T a){
            if (size > OVERFLOW_DB){
                cout << "ПЕРЕПОЛНЕНИЕ\n";
                return 1;
            }

            T* arr2 = static_cast<T*>(operator new[] ((size + 1)*sizeof(T)));
            copy(arr + 0, arr + size, arr2);
            arr[size] = a;
            arr = arr2;
            size++;
            delete[] arr2;
            return 0;
        }
        
         int del(int id) {
            if (id >= size) {
                cout << "Нет ТАКОГО!\n";
                return 1;
            }
            T* arr2 = static_cast<T*>(operator new[] ((size - 1)*sizeof(T)));
            for (int i = 0; i < id; i++){
                arr2[i] = arr[i];
            }
            for (int i = id + 1; i < size; i++){
                arr2[i-1] = arr[i];
            }
            arr = arr2;
            size--;
            delete[] arr2;
            return 0;
        }
        
        void change(int id, T a) {
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
