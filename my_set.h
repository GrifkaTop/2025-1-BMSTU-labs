

#include "my_vector.h"

template<typename T>
class MySet : public MyVector<T> {
    int q_find(const T element) const {
        int left = 0;
        int right = static_cast<int>(this->size) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (this->ptr[mid] == element)
                return mid;
            if (this->ptr[mid] < element)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

 public:
    MySet(T element = T(), size_t capacity = kDefaultVectorCapacity) : MyVector<T>(element, capacity) {};

    bool operator==(MySet<T>& other);

    MySet& operator+=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            add_element(other.ptr[i]);
        }
        return *this;
    }

    MySet& operator-=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            int index = q_find(other.ptr[i]);
            if (index != -1) {
                this->delete_element(index);
            }
        }
        return *this;
    }

    MySet& operator*=(const MySet& other) {
        for (int i = static_cast<int>(this->size) - 1; i >= 0; --i) {
            if (other.q_find(this->ptr[i]) == -1) {
                this->delete_element(i);
            }
        }
        return *this;
    }

    void add_element(T element) {
        if (!this->ptr) {
            throw std::runtime_error("invalid vector");
        }

        if (!is_element(element)) {
            MyVector<T>::add_element(element);
            this->sort();
        }
    };

    bool is_element(T element) const {
        if (!this->ptr || this->size == 0) {
            return false;
        }

        int index = q_find(element);
        if (index == -1) {
            return false;
        }
        return true;
    };

    friend MySet operator+(const MySet& s1, const MySet& s2) {
        MySet temp = s1;
        temp += s2;
        return temp;
    };

    friend MySet operator-(const MySet& s1, const MySet& s2) {
        MySet temp = s1;
        temp -= s2;
        return temp;
    };

    friend MySet operator*(const MySet& s1, const MySet& s2) {
        MySet temp = s1;
        temp *= s2;
        return temp;
    };
};

template<>
int MySet<char*>::q_find(char* element) const {
    if (!element)
        return -1;

    int left = 0;
    int right = static_cast<int>(this->size) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = std::strcmp(this->ptr[mid], element);
        if (cmp == 0)
            return mid;
        if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<typename T>
bool MySet<T>::operator==(MySet<T>& other) {
    if (this->size != other.size) {
        return false;
    }

    for (size_t i = 0; i < this->size; ++i) {
        if (this->ptr[i] != other.ptr[i]) {
            return false;
        }
    }

    return true;
}

template<>
bool MySet<char*>::operator==(MySet<char*>& other) {
    if (this->size != other.size) {
        return false;
    }

    for (size_t i = 0; i < this->size; ++i) {
        if (std::strcmp(this->ptr[i], other.ptr[i]) != 0) {
            return false;
        }
    }

    return true;int
}

MySet(const char*) -> MySet<char*>;