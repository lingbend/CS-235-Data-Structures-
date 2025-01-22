#pragma once
#include <iostream>


template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}

        ~Node() {
            left = nullptr;
            right = nullptr;
            height = 0;
        }
    };
private:
    Node * head;
    int t_size;

    void clear_helper(Node * curr) {
        if (curr->left != nullptr) {
            clear_helper(curr->left);
        }
        
        if (curr->right != nullptr) {
            clear_helper(curr->right);
        }
        delete curr;
        curr = nullptr;
    }

    Node * find (T item, Node * curr) const { //finds node or if not found would be parent
        if (curr->value == item) {
            return curr;
        }
        else if (item < curr->value && curr->left != nullptr) {
            return find(item, curr->left);
        }
        else if (item > curr->value && curr->right != nullptr) {
            return find(item, curr->right);
        }
        else {
            return curr;
        }
    }

    bool insert_helper(T item, Node * & curr) {
        bool result;
        if (curr == nullptr) {
            curr = new Node(item);
            update_heights(head);
            result = true;
        }
        else if (curr->value == item) {
            result = false;
        }
        else if (item < curr->value) {
            result = insert_helper(item, curr->left);
        }
        else {
            result = insert_helper(item, curr->right);
        }

        if (result) {
            rebalance(curr);
        }
        
        return result;
    }

    int update_heights(Node * curr) {
        if (curr == nullptr) {
            return 0;
        }
        int left_h = 0;
        int right_h = 0;
        if (curr->left != nullptr) {
            left_h = update_heights(curr->left);
        }
        if (curr->right != nullptr) {
            right_h = update_heights(curr->right);

        }
        if (right_h > left_h) {
            curr->height = right_h + 1;

            return right_h + 1;
        }
        else {
            curr->height = left_h + 1;
            return left_h + 1;
        }
    }

    void promote_right(Node*& root) {
        Node * right_node = root->right;
        root->right = right_node->left;
        right_node->left = root;
        root = right_node;
        right_node = nullptr;
        update_heights(head);
    }

    void promote_left(Node*& root) {
        Node * left_node = root->left;
        root->left = left_node->right;
        left_node->right = root;
        root = left_node;
        left_node = nullptr;
        update_heights(head);
    }

    void rebalance(Node*& root) {
        int right_h = 0;
        int left_h = 0;
        int left_left_h = 0;
        int left_right_h = 0;
        int right_right_h = 0;
        int right_left_h = 0;
        if (root == nullptr) {
            return;
        }
        if (root->right != nullptr){
            right_h = root->right->height;
            if (root->right->right != nullptr) {
                right_right_h = root->right->right->height;
            }
            if (root->right->left != nullptr) {
                right_left_h = root->right->left->height;
            }
        }

        if (root->left != nullptr) {
            left_h = root->left->height;
            if (root->left->right != nullptr) {
                left_right_h = root->left->right->height;
            }
            if (root->left->left != nullptr) {
                left_left_h = root->left->left->height;
            }
        }
        int root_balance = (right_h - left_h);
        int left_balance = (left_right_h - left_left_h);
        int right_balance = (right_right_h - right_left_h);
        if (root_balance > 1) {
            if (right_balance < 0) {
                promote_left(root->right);
            }
            promote_right(root);
        }
        else if (root_balance < -1) {
            if (left_balance > 0) {
                promote_right(root->left);
            }
            promote_left(root);
        }
}

    int num_children(Node * curr) {
        int num = 0;
        if (curr->left != nullptr) {
            num++;
        }
        if (curr->right != nullptr) {
            num++;
        }
        return num;
    }

    Node * find_iop (Node * curr) {
        Node * iop = nullptr;
        iop = curr->left;
        while (iop->right != nullptr) {
            iop = iop->right;
        }
        return iop;
    } 

    void remover(Node * & parent, Node * target, T item) {

        if (num_children(target) == 0) { // deletes node and disconnects parent
            if (target != head) {
                if (item < parent->value) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
                delete target;
            }
            else {
                clear();
                t_size++;
            }
            
        }

        else if (num_children(target) == 1) { // connects parent to child and deletes
            Node * child;

            if (target->left != nullptr) {
                child = target->left;
            }
            else {
                child = target->right;
            }

            if (target == head) {
                head = child;
                delete target;
            }
            else {
                if (item < parent->value) {
                    parent->left = child;
                }
                else {
                    parent->right = child;
                }
                delete target;
            }

            child = nullptr;
        }

        else {
            Node * iop = find_iop(target);
            T iop_value = iop->value;
            remove(iop_value);
            t_size++;
            target->value = iop_value;
            iop = nullptr;
        }
        update_heights(head);
    }

    bool remove_helper(Node * & curr, T item) {
        bool result;
        if (curr == nullptr) {
            result = false;
        }
        else if (curr->value == item) {
            remover(curr, curr, item);
            result = true;
        }
        else if (curr->left != nullptr && curr->left->value == item) {
            remover(curr, curr->left, item);
            result = true;
        }
        else if (curr->right != nullptr && curr->right->value == item) {
            remover(curr, curr->right, item);
            result = true;
        }  
        else if (item < curr->value && curr->left != nullptr) {
            result = remove_helper(curr->left, item);
        }
        else if (item > curr->value && curr->right != nullptr) {
            result = remove_helper(curr->right, item);
        }
        else {
            result = false;
        }

        if (result) {
            rebalance(curr);
        }
        
        return result;
    }

public:
    AVL() {
        head = nullptr;
        t_size = 0;
    }

    ~AVL() {
        clear();
    }

    const Node* getRootNode() const {
        return head;
    }

    bool insert(T item) {
        bool insert_result = insert_helper(item, head);
        if (insert_result) {
            t_size++;
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(T item) {
        bool result = remove_helper(head, item);
        if (result) {
            t_size--;
        }
        return result;
    }

    bool contains(T item) const {
        if (find(item, head)->value == item) {
            return true;
        }
        else {
            return false;
        }
    } 

    void clear() {
        if (head != nullptr) {
            clear_helper(head);
            head = nullptr;
            t_size = 0;
        }
    }

    int size() const {
        return t_size;
    }
};
