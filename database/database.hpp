#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T> class Database{
    private:
        const int OVERFLOW_DB = 100;
        char* FILENAME = "base.txt";
    public:
        int size = 0;
        T *arr;
        Database();
        Database(int size_, char* );
        ~Database();
        int readFile ();
        int writeFile ();

        void srt(bool r = false);

        int push(T a);
        int del(int id);
        void change(int id, T a);
        void print();
        void print(int id);
        T get(int id);
};