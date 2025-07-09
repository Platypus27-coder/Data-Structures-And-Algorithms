#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node *next;
};

typedef Node* node;

node makeNode(int data) {
    node newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int size(node head) {
    int count = 0;
    while(head != NULL) {
        ++count;
        head = head->next;
    }
}

void print(node head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

void pushFront(node &head, int data) {
    node newNode = makeNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void pushBack(node &head, int data) {
    node newNode = makeNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node tmp = head;
    while(tmp->next == NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void insert(node &head, int data, int k) {
    int n = size(head);
    if (k < 1 || k > n + 1) {
        return;
    }
    else if (k == 1) {
        pushFront(head, data);
        return;
    }
    else if (k == n + 1) {
        pushBack(head, data);
        return;
    }
    else {
        node tmp = head;
        for (int i = 1; i <= k - 2; i++) {
            tmp = tmp->next;
        }
        node newNode = makeNode(data);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void popFront(node &head) {
    if (head == NULL) {
        return;
    }
    node tmp = head;
    head = head->next;
    delete tmp;
}

void popBack(node &head) {
    if (head == NULL) {
        return;
    }
    node tmp = head;
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    node last = tmp->next;
    tmp->next = NULL;
    delete last;
}

void erase(node &head, int k) {
    int n = size(head);
    if (k < 1 || k > n) {
        return;
    }
    else if (k == 1) {
        popFront(head);
        return;
    }
    node tmp = head;
    for (int i = 1; i <= k - 2; i++) {
        tmp = tmp->next;
    }
    node del = tmp->next;
    tmp->next = del->next;
    delete del;
}

void selectionsort(node &head) {
    for (node i = head; i != NULL; i = i->next) {
        node min = i;
        for (node j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

void REVERSE(node &head) {
    vector<int> v;
    node p = head;
    while(p!= NULL) {
        v.push_back(p->data);
        p = p->next;
    }
    reverse(v.begin(), v.end());
    node tmp = head;
    int id = 0;
    while(tmp != NULL) {
        tmp->data = v[id++];
        tmp = tmp->next;
    }
}
