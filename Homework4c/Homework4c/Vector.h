#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
private:

T * v_data;
int v_size = 0;
int capacity = 10;

// bool good_index (int index) {
//     if (index < 0 || (index >= v_size && index != 0)) {
//         return false;
//     }
//     else {
//         return true;
//     }
// }

void grow () {
    capacity *= 2;
    T * temp = new T[capacity];
    for (int i = 0; i < capacity / 2; i++) {
        temp[i] = v_data[i];
    }
    delete [] v_data;
    v_data = temp;
    temp = nullptr;
}

bool at_capacity () {
    if (v_size >= capacity) {
        return true;
    }
    else {
        return false;
    }
}

public:
    Vector() {
        v_data = new T [10];
    }

    ~Vector() {
        delete [] v_data;
        v_data = nullptr;
        v_size = 0;
        capacity = 0;
    }

    void push_back(T item) {
        if (at_capacity()) {
            grow();
        }
        v_data[v_size] = item;
        v_size++;
    }

    void insert(T item, int position) {
        if (position < 0 || position > v_size) {
            throw std::out_of_range("The index is out of range for the insert function.");
        }
        else if (at_capacity()) {
            grow();
        }
        if (position == v_size) {
            v_data[position] = item;
        }
        else {
            for (int i = v_size; i > position; i--) {
                v_data[i] = v_data[i - 1];
            }
            v_data[position] = item;
        }
        v_size++;
    }

    void remove(int position) {
        if (position < 0 || (position >= v_size && position != 0) || v_size == 0) {
            throw std::out_of_range("The position you are trying to remove is not in the vector");
        }
        else if (at_capacity()) {
            grow();
        }
        if (position != v_size - 1) {
            for (int i = position; i < v_size - 1; i++) {
                v_data[i] = v_data[i + 1];
            }
        }
        v_size--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= v_size) {
            throw std::out_of_range("Tried to access data that was not in the vector.");
        }
        else {
            return v_data[index];
            
        }
    }

    int size() const {
        return v_size;
    }

    void clear() {
        delete [] v_data;
        v_size = 0;
        v_data = new T[10];
        capacity = 10;
    }
};
