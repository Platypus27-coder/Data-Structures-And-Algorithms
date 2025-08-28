#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include<cctype>

using namespace std;
using ll = long long;

struct node {
    int data;
    node *left;
    node *right;
};

node *makeNode(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool search(node *root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

node *insert(node *root, int key) {
    if (root == nullptr) {
        return makeNode(key);
    }
    if (root->data > key) {
        root->left = insert(root->left, key);
    }
    else if (root->data < key) {
        root->right = insert(root->right, key);
    }
    return root;
}

node *minNode(node *root) {
    node *temp = root;
    while(temp != nullptr && temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

node *deleteNode(node *root, int key) {
    if (root == nullptr) return root;
    if (root->data > key) {
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == nullptr) {
            node *tmp = root->left;
            delete root;
            return tmp;
        }
        else {
            node *tmp = minNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }
    return root;
}
