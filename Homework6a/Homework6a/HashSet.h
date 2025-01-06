#pragma once
#include <functional>
#include <list>
#include<vector>

using namespace std;

template<class T>
class HashSet {
private:
vector<list <T>> * data;
int list_cap = 11;
int list_size = 0;
double average_comparisons = 0.0;

void update_comparisons() {
    average_comparisons = (1 + ((list_size/list_cap) / 2));
    while (average_comparisons > 1.5) {
        grow();
    }
}

void grow() {
    int old_cap = list_cap;
    list_cap = (list_cap * 2) + 1;
    vector<list<T>> * old_data = data;
    data = new vector<list<T>>(list_cap);
    for (int i = 0; i < old_cap; i++) {
        list<T> current_list = old_data->at(i);
        if (current_list.size() != 0) {
            for (T j : current_list) {
                insert(j, true);
            }
        }
    }
    delete old_data;
    old_data = nullptr;
    average_comparisons = (1 + ((list_size/list_cap) / 2));
}

size_t get_hash_num(T item) const{
    size_t temp_hash = hash<T>{}(item);
    return temp_hash;
}

size_t calculate_hash_index(T item) const{
    size_t temp_hash = (get_hash_num(item) % list_cap);
    return temp_hash;
}

bool find(list<T> bucket, T item) const{
    for (T i : bucket) {
        if (i == item) {
            return true;
        }
    }
    return false;
}

vector<list<T>> * refresh_table(){
        vector<list<T>> * temp_data = new vector<list<T>>(11);
        list_cap = 11;
        list_size = 0;
        average_comparisons = 0.0;
        return temp_data;
}


public:
    HashSet() {
        data = new vector<list<T>>(11);
        list_cap = 11;
        list_size = 0;
        average_comparisons = 0.0;
    }

    ~HashSet() {
        clear();
    }

    bool insert(T item, bool growing = false) {
        if (data == nullptr) {
            data = refresh_table();
        }
        size_t index = calculate_hash_index(item);
        list<T>& bucket = data->at(index);
        if (!bucket.empty()) {
            if (find(bucket, item)) {
                return false;
            }
        }
        bucket.push_front(item);
        list_size++;
        if (!growing) {
            update_comparisons();
        }
        return true;
        // implement insert here
        // return true if item was inserted, false if item was already in the set
    }

    bool remove(T item) {
        if (data == nullptr) {
            data = refresh_table();
        }
        size_t index = calculate_hash_index(item);
        list<T>& bucket = data->at(index);
        if (bucket.empty() || !find(bucket, item)) {
            return false;
        }
        else {
            bucket.remove(item);
            list_size--;
            return true;
        }
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
    }

    bool contains(T item) const {
        size_t index = calculate_hash_index(item);
        list<T>& bucket = data->at(index);
        if (!bucket.empty() && find(bucket, item)) {
            return true;
        }
        else {
            return false;
        }

        // implement contains here
        // return true if item is in the set, false otherwise
    }

    void clear() {
        if (data != nullptr) {
            delete data;
            data = nullptr;
            list_size = 0;
            list_cap = 11;
            average_comparisons = 0.0;
        }
    }

    int size() const {
        return list_size;
    }
};

