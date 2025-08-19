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

void makeRoot(node *root, int u, int v, char c) {
    if (c == 'L') root->left = makeNode(v);
    else root->right = makeNode(v);
}

void insertNode(node *root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->data == u) {
        makeRoot(root, u, v, c);
    }
    else {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void postOrder(node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    node *root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        if (root == NULL) {
            root = makeNode(u);
            makeRoot(root, u, v, c);
        }
        else {
            insertNode(root, u, v, c);
        }
    }
    postOrder(root);
    return 0;
}
