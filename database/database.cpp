#include "database.hpp"

template<typename T>  Database<T>::Database() {
    arr  = static_cast<T*>(operator new[] (0*sizeof(T)));
}
template<typename T> Database<T>::Database(int size_, char* file) : FILENAME(file){
    FILENAME = file;
    size = size_;
    arr  = static_cast<T*>(operator new[] (size_*sizeof(T)));
}
template<typename T> Database<T>::~Database(){
    delete[] arr;
}

template<typename T> int Database<T>::readFile () {
    ifstream fin(FILENAME, ios::in);
    if (!fin) {
        cout << "Heт файла " << FILENAME << endl;
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

template<typename T> int Database<T>::writeFile () {
    ofstream fout(FILENAME, ios::out); // авто удаление
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


template<typename T> void Database<T>::srt(bool r){
    this-> srt(r, arr, size);
    return;
}


/*
добавление нового объекта в БД;
удаление объекта из БД;
редактирование БД;
вывод БД на экран.
*/

template<typename T> int Database<T>::push(T a){
    if (size > OVERFLOW_DB){
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

template<typename T> int Database<T>::del(int id) {
    if (id >= size) {
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

template<typename T> void Database<T>::change(int id, T a) {
    arr[id] = a;
    return;
}

template<typename T> void Database<T>::print() {
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
template<typename T> void Database<T>::print(int id) {
    if (id >= size){
        cout << "Такого элемента нет\n";
        return;
    }
    cout << arr[id];
}

template<typename T> T Database<T>::get(int id){
    return arr[id];
}

