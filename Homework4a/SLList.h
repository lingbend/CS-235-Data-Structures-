#pragma once

template <class T>
class SLList {
public:

    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    Node * head = nullptr;
    int l_size = 0;

    SLList() {
        head = nullptr;
        int l_size = 0;
    }

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_back(T item) {
        Node * current = head;
        if (head == nullptr) {
            head = new Node(item);
        }
        else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(item);
        }
        l_size++;
        current = nullptr;
    }

    void pop_back() {
        Node * current = head;
        if (head != nullptr && head->next != nullptr) {
            while (current->next != nullptr && current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            l_size--;
        }
        else if (head != nullptr) {
            delete current;
            head = nullptr;
            l_size--;
        }
        current = nullptr;
    }

    const T& front() const {
        return head->value;
    }

    int size() const {
        return l_size;
    }

    void clear() {
        Node * current = head;
        Node * last = nullptr;
        while (current != nullptr) {
            last = current;
            current = current->next;
            last->next = nullptr;
            delete last;
            l_size--;
        }
        head = nullptr;
        current = nullptr;
        last = nullptr;
    }
};
