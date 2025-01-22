#pragma once



template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}

        ~Node() {
            left = nullptr;
            right = nullptr;
        }
    };

private:
    Node * head;
    int t_size;

public:

    BST() {
        head = nullptr;
        t_size = 0;
    }

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        return head;
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

    Node * find_parent (T item, Node * curr) const { //finds parent unless there is none and then returns node
        if (head->value == item) {
            return head;
        }
        else if (head->left == nullptr && head->right == nullptr) {
            return nullptr;
        }

        if ((curr->left != nullptr && curr->left->value == item) || (curr->right != nullptr && curr->right->value == item)) {
            return curr;
        }
        else if (item < curr->value && curr->left != nullptr) {
            return find_parent(item, curr->left);
        }
        else if (item > curr->value && curr->right != nullptr) {
            return find_parent(item, curr->right);
        }
        else {
            return nullptr;
        }
    }

    Node * find_iop (Node * curr) {
        Node * iop = nullptr;
        iop = curr->left;
        while (iop->right != nullptr) {
            iop = iop->right;
        }
        return iop;
    } 

    bool insert(T item) {
        if (head == nullptr) {
            head = new Node(item);
            t_size++;
            return true;
        }
        else if (find(item, head)->value == item) {
            return false;
        }
        else {
            Node * parent = find(item, head);
            if (item < parent->value) {
                parent->left = new Node(item);
            }
            else {
                parent->right = new Node(item);
            }
            t_size++;
            return true;
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

    bool remove(T item) {
        if (head == nullptr) {
            return false;
        }

        Node * parent = find_parent(item, head);

        if (parent == nullptr) {
            return false;
        }

        Node * target = nullptr;

        if (item < parent->value) {
            target = parent->left;
        }
        else if (item > parent->value) {
            target = parent->right;
        }
        else {
            target = parent;
        }

        if (num_children(target) == 0) { // deletes node and disconnects parent
            if (target == head) {
                clear();
            }
            else {
                if (item < parent->value) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
                delete target;
            }
        }

        else if (num_children(target) == 1) { // connects parent to child and deletes
            Node * child = nullptr;

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
            target->value = iop_value;
            iop = nullptr;
        }

        target = nullptr;
        parent = nullptr;

        if (t_size != 0) {
            t_size--;
        }

        return true;
    }

    bool contains(T item) const {
        if (find(item, head)->value == item) {
            return true;
        }
        else {
            return false;
        }
    } 

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
