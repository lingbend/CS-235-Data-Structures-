#pragma once
#include <vector>
using std::vector;
#include <set>
using std::set;

template<class T>
class VectorSet {
public:
    bool contains(T item) const {
        if (c_set.find(item) != c_set.end()) {
            return true;
        }
        else {
            return false;
        }
        // implement contains here

        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        if (c_set.find(item) != c_set.end()) {
            return false;
        }
        else {
            c_set.insert(item);
            c_vector.push_back(item);
            return true;
        }
        // implement insert here

        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        if (c_set.find(item) == c_set.end()) {
            return false;
        }
        else {
            c_set.erase(item);
            for (int i = 0; i < c_vector.size(); i++) {
                if (c_vector.at(i) == item) {
                    c_vector.erase(c_vector.begin() + i);
                }
            }
            return true;
        }
        // implement remove here

        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        return c_vector.size();
        // implement size here

        // return the number of items in the set
    }

    bool empty() const {
        if (c_vector.size() == 0) {
            return true;
        }
        else {
            return false;
        }
        // implement empty here

        // return true if the set is empty and return false otherwise
    }

    void clear() {
        c_set.clear();
        c_vector.clear();
        // implement clear here

        // remove all items from the set
    }
private:
    vector<T> c_vector;
    set<T> c_set;
};
