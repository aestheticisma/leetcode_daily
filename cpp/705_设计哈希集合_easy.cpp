class MyHashSet {
private:
    static const int base = 769;
    vector<list<int>> hashset;
    static int hash(int x) {
        return x % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() : hashset(base) {}
    
    void add(int key) {
        int h = hash(key);
        for (auto it = hashset[h].begin(); it != hashset[h].end(); it++) {
            if ((*it) == key)
                return;
        }
        hashset[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = hashset[h].begin(); it != hashset[h].end(); it++) {
            if ((*it) == key) {
                hashset[h].erase(it);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto it = hashset[h].begin(); it != hashset[h].end(); it++) {
            if ((*it) == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */