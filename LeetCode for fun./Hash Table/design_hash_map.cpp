class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<pair<int, int>> mp[SIZE];
    int hashFunction(int key) {
        return key % SIZE;
    }
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int hash = hashFunction(key);
        for (auto &it : mp[hash]) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        mp[hash].push_back({key, value});
    }
    
    int get(int key) {
        int hash = hashFunction(key);
        for (auto it : mp[hash]) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = hashFunction(key);
        for (int i = 0; i < mp[hash].size(); i++) {
            if (mp[hash][i].first == key) {
                mp[hash].erase(mp[hash].begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
