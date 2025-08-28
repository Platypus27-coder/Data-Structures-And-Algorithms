#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) {
        key = k;
        height = 1;
        left = right = nullptr;
    }
};

int getBalance(Node* n) {
    if (n == nullptr) return 0;
    int hl, hr;
    if (n->left == nullptr) hl = 0;
    else hl = n->left->height;

    if (n->right == nullptr) hr = 0;
    else hr = n->right->height;

    return hl - hr;
}

void updateHeight(Node* n) {
    if (n != nullptr) {
        int hl, hr;
        if (n->left == nullptr) hl = 0;
        else hl = n->left->height;

        if (n->right == nullptr) hr = 0;
        else hr = n->right->height;

        n->height = 1 + max(hl, hr);
    }
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* balanceNode(Node* node, int key) {
    updateHeight(node);
    int balance = getBalance(node);
    // LL
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
    // RR
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; 

    return balanceNode(node, key);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp;
            if (root->left != nullptr) temp = root->left;
            else temp = root->right;

            if (temp == nullptr) { 
                temp = root;
                root = nullptr;
            } else {
                *root = *temp; 
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;
    updateHeight(root);
    int balance = getBalance(root);
    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);
    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);
    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (key == root->key) return true;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    vector<int> keys = {10, 20, 30, 40, 50, 25};
    cout << "==== INSERT ====\n";
    for (int k : keys) {
        root = insert(root, k);
        inorder(root);
        cout << endl;
    }
    cout << "==== DELETE 40 ====\n";
    root = deleteNode(root, 40);
    inorder(root);
    cout << endl;
    cout << "==== SEARCH ====\n";
    cout << (search(root, 25) ? "Found 25" : "Not found") << endl;
    cout << (search(root, 40) ? "Found 40" : "Not found") << endl;
}
