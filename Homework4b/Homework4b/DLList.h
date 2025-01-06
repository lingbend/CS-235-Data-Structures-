#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

template<class T>
class DLList {
public:
    // **Important**
    // Normally you would make the Node struct PRIVATE
    // but for this assignment it is important to keep it 
    // PUBLIC
    // Also, the declaration of Node needs to come 
    // before everything else in the class, so leave it here
    // at the beginning.
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

private:
    Node * head = nullptr;
    Node * tail = nullptr;
    int l_size = 0;

    Node * find_node (int index) {
        Node * temp = head;
        if (index < l_size) {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    }
    
    void delete_node (Node * current) {
        current->prev = nullptr;
        current->next = nullptr;
        delete current;
        current = nullptr;
    }

public:
    DLList() {}

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        if (head == nullptr) {
            head = new Node(item);
            tail = head;
        }
        else {
            head->prev = new Node(item);
            head->prev->next = head;
            head = head->prev;
        }
        l_size++;
    }

    void push_back(T item) {
        if (tail == nullptr) {
            tail = new Node(item);
            head = tail;
        }
        else {
            tail->next = new Node(item);
            tail->next->prev = tail;
            tail = tail->next;
        }
        l_size++;
    }

    void insert(T item, int position) {
            if (position < 0 || position > l_size) {
                throw std::out_of_range("This position does not exist. Could not insert.");
            }
            else if (position == 0 || l_size == 0) {
                push_front(item);
            }
            else if (position == l_size) {
                push_back(item);
            }
            else {
                Node * temp = find_node(position);
                Node * inserted = new Node(item);
                inserted->prev = temp->prev;
                inserted->next = temp;
                temp->prev = inserted;
                inserted->prev->next = inserted;
                l_size++;
            }
    }

    void pop_front() {
            if (l_size == 0) {
                throw std::length_error("This list has no length. Could not pop front.");
            }
            else if (head != nullptr && l_size >= 2) {
                head = head->next;
                head->prev->next = nullptr;
                delete head->prev;
                head->prev = nullptr;
                l_size--;
            }
            else if (head != nullptr && l_size == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                l_size--;
            }
    }

    void pop_back() {
            if (l_size == 0) {
                throw std::length_error("This list has no length. Could not pop back.");
            }
            else if (tail != nullptr && l_size >= 2) {
                tail = tail->prev;
                tail->next->prev = nullptr;
                delete tail->next;
                tail->next = nullptr;
                l_size--;
            }
            else if (tail!= nullptr && l_size == 1) {
                delete tail;
                tail = nullptr;
                head = nullptr;
                l_size--;
            }
    }
    
    void remove(int position) {
            if (l_size == 0 || position < 0 || position >= l_size) {
                throw std::out_of_range("This operation is invalid. Could not remove at this position.");
            }
            else if (position == 0) {
                pop_front();
            }
            else if (position == l_size - 1) {
                pop_back();
            }
            else {
                Node * temp = find_node(position);
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = nullptr;
                temp->prev = nullptr;
                delete temp;
                temp = nullptr;
                l_size--;
        }
    }

    const T& front() const {
        if (l_size == 0) {
            throw std::length_error("This list has no length and therefore no front.");
        }
        else if (head != nullptr) {
            return head->value;
        }
    }

    const T& back() const {
            if (l_size == 0) {
                throw std::length_error("This list has no length and therefore no back.");
            }
            else if (tail != nullptr) {
                return tail->value;
            }
    }

    const T& at(int index) const {
        if (index < 0 || index >= l_size) {
            throw std::out_of_range("This position is greater or smaller than the list's size. Could not access.");
        }
        else {
            Node * temp = head;
            if (index < l_size) {
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp->value;
            }
        }
    }

    bool contains(const T& item) const {
        Node * temp = head;
        if (temp->value == item) {
            return true;
        }
        for (int i = 0; i < l_size - 1; i++) {
            temp = temp->next;
            if (temp->value == item) {
                return true;
            }
        }
        return false;
    }

    int size() const {
        return l_size;
    }

    void clear() {
        try {
            if (l_size == 0) {
                throw std::length_error("There is nothing to clear.");
            }
            else {
                Node * temp = head;
                while (l_size > 1) {
                    temp = temp->next;
                    delete_node(temp->prev);
                    l_size--;
                }
                delete_node(temp);
                temp = nullptr;
                head = nullptr;
                tail = nullptr;
                l_size--;
            }
        }
        catch (std::length_error& error) {
        }
    }
};
