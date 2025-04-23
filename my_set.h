#ifndef MY_SET_H
#define MY_SET_H

#include "my_vector.h"
#include <iostream>

template <typename T>
class MySet : public MyVector<T> {
private:
    int q_find(const T& element) const {
        int left = 0;
        int right = static_cast<int>(this->size) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (this->pdata[mid] == element) {
                return mid;
            }
            
            if (this->pdata[mid] < element) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }

public:
    using MyVector<T>::MyVector;

    bool is_element(const T& element) const {
        return q_find(element) != -1;
    }

    void add_element(const T& element) {
        if (!is_element(element)) {
            MyVector<T>::add_element(element);
            this->sort(); 
        }
    }
    
    void delete_element(const T& element) {
        int index = q_find(element);
        if (index != -1) {
            MyVector<T>::delete_element(static_cast<size_t>(index));
        }
    }
    
    MySet& operator+=(const MySet& other) {
        for (size_t i = 0; i < other.get_size(); i++) {
            add_element(other[i]);
        }
        return *this;
    }
    
    MySet& operator-=(const MySet& other) {
        for (size_t i = 0; i < other.get_size(); i++) {
            delete_element(other[i]);
        }
        return *this;
    }
    
    MySet& operator*=(const MySet& other) {
        MySet<T> result;
        for (size_t i = 0; i < this->size; i++) {
            if (other.is_element(this->pdata[i])) {
                result.add_element(this->pdata[i]);
            }
        }
        *this = result;
        return *this;
    }
    
    template <typename U>
    friend MySet<U> operator+(const MySet<U>& lhs, const MySet<U>& rhs);
    
    template <typename U>
    friend MySet<U> operator-(const MySet<U>& lhs, const MySet<U>& rhs);
    
    template <typename U>
    friend MySet<U> operator*(const MySet<U>& lhs, const MySet<U>& rhs);
    
    template <typename U>
    friend bool operator==(const MySet<U>& lhs, const MySet<U>& rhs);
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MySet<U>& set);
};

template <typename T>
MySet<T> operator+(const MySet<T>& lhs, const MySet<T>& rhs) {
    MySet<T> result = lhs;
    result += rhs;
    return result;
}

template <typename T>
MySet<T> operator-(const MySet<T>& lhs, const MySet<T>& rhs) {
    MySet<T> result = lhs;
    result -= rhs;
    return result;
}

template <typename T>
MySet<T> operator*(const MySet<T>& lhs, const MySet<T>& rhs) {
    MySet<T> result = lhs;
    result *= rhs;
    return result;
}

template <typename T>
bool operator==(const MySet<T>& lhs, const MySet<T>& rhs) {
    if (lhs.get_size() != rhs.get_size()) {
        return false;
    }
    
    for (size_t i = 0; i < lhs.get_size(); i++) {
        if (!rhs.is_element(lhs[i])) {
            return false;
        }
    }
    
    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MySet<T>& set) {
    os << "{";
    for (size_t i = 0; i < set.get_size(); i++) {
        os << set[i];
        if (i < set.get_size() - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

#endif // MY_SET_H
