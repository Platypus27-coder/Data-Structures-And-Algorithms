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
