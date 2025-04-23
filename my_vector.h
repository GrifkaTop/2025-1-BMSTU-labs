#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <algorithm>

template <typename T>
class MyVector {
protected:
    size_t max_size; 
    size_t size;    
    T* pdata;     

    static const size_t DEFAULT_SIZE;

    void resize() {
        if (size >= max_size) {
            max_size *= 2;
            T* new_data = new T[max_size];x
            for (size_t i = 0; i < size; i++) {
                new_data[i] = pdata[i];
            }
            delete[] pdata;
            pdata = new_data;
        } else if (size < max_size / 4 && max_size > DEFAULT_SIZE) {
            max_size = std::max(max_size / 2, DEFAULT_SIZE);
            T* new_data = new T[max_size];
            for (size_t i = 0; i < size; i++) {
                new_data[i] = pdata[i];
            }
            delete[] pdata;
            pdata = new_data;
        }
    }

public:
    explicit MyVector(size_t initial_size = DEFAULT_SIZE) : max_size(initial_size), size(0) {
        pdata = new T[max_size];
    }

    MyVector(const MyVector& other) : max_size(other.max_size), size(other.size) {
        pdata = new T[max_size];
        for (size_t i = 0; i < size; i++) {
            pdata[i] = other.pdata[i];
        }
    }

    virtual ~MyVector() {
        delete[] pdata;
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] pdata;
            max_size = other.max_size;
            size = other.size;
            pdata = new T[max_size];
            for (size_t i = 0; i < size; i++) {
                pdata[i] = other.pdata[i];
            }
        }
        return *this;
    }

    void add_element(const T& element) {
        if (size >= max_size) {
            resize();
        }
        pdata[size++] = element;
    }

    void delete_element(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        
        for (size_t i = index; i < size - 1; i++) {
            pdata[i] = pdata[i + 1];
        }
        size--;
        
        resize();
    }

    int find(const T& element) const {
        for (size_t i = 0; i < size; i++) {
            if (pdata[i] == element) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return pdata[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return pdata[index];
    }

    size_t get_size() const {
        return size;
    }

    size_t get_max_size() const {
        return max_size;
    }

    void sort() {
        std::sort(pdata, pdata + size);
    }
};

template <typename T>
const size_t MyVector<T>::DEFAULT_SIZE = 1;

#endif // MY_VECTOR_H
