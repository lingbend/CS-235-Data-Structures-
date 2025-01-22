#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children
int update_heights(Node * curr) {
    if (curr == nullptr) {
        return 0;
    }
    int left_h = 0;
    int right_h = 0;
    if (curr->left != nullptr) {
        left_h = update_heights(curr->left) ;
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

    // if (curr != nullptr) {
    //     curr->height = curr->height + by;
    // }
    // if (curr->left != nullptr) {
    //     update_heights(by, curr->left);
    // }
    // if (curr->right != nullptr) {
    //     update_heights(by, curr->right);
    // }
}


void promote_right(Node*& root) {
    Node * right_node = root->right;
    root->right = right_node->left;
    right_node->left = root;
    // root->height--;
    // update_heights(root->left);
    root = right_node;
    // root->height++;
    // update_heights(root->right);
    right_node = nullptr;
    update_heights(root);
}

void promote_left(Node*& root) {
    Node * left_node = root->left;
    root->left = left_node->right;
    left_node->right = root;
    // root->height--;
    // update_heights(root->right);
    root = left_node;
    // root->height++;
    // update_heights(root->left);
    left_node = nullptr;
    update_heights(root);
}

void rebalance(Node*& root) {
    int right_h = 0;
    int left_h = 0;
    int left_left_h = 0;
    int left_right_h = 0;
    int right_right_h = 0;
    int right_left_h = 0;

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
