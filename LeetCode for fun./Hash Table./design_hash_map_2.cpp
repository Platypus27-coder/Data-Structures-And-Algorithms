#include<bits/stdc++.h>
#define MAX 1000

class MyHashmap {
private:
    static const int SIZE = 1000;
    struct Node {
        int key;
        int value;
        Node *next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    Node *mp[SIZE];
    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    MyHashmap() {
        for (int i = 0; i < SIZE; i++) {
            mp[i] = nullptr;
        }
    }

    void put(int key, int value) {
        int hash = hashFunction(key);
        Node *cur = mp[hash];
        while(cur) {
            if (cur->key == key) {
                cur->value = value;
                return;
            }
            cur = cur->next;
        }
        Node *newNode = new Node(key, value);
        newNode->next = mp[hash];
        mp[hash] = newNode;
    }

    int get(int key) {
        int hash = hashFunction(key);
        Node *cur = mp[hash];
        while(cur) {
            if (cur->key == key) {
                return cur->value;
            }
            cur = cur->next;
        }
        return -1;
    }

    void remove(int key) {
        int hash = hashFunction(key);
        Node *prev = nullptr;
        Node *cur = mp[hash];
        while(cur) {
            if (cur->key == key) {
                if (prev) {
                    prev->next = cur->next;
                }
                else {
                    mp[hash] = cur->next;
                }
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    ~MyHashmap() {
        for (int i = 0; i < SIZE; i++) {
            Node *cur = mp[i];
            while(cur) {
                Node *next = cur->next;
                delete cur;
                cur = next;
            }
        }
    }
};
