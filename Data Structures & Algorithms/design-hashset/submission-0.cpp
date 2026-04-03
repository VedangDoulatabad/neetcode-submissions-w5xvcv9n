class MyHashSet {
private:
    static const int size = 1000; // number of buckets
    vector<list<int>> buckets;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashSet() {
        buckets.resize(size);
    }
    
    void add(int key) {
        int index = hash(key);
        
        // check if already exists
        for (int val : buckets[index]) {
            if (val == key) return;
        }
        
        buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        
        buckets[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);
        
        for (int val : buckets[index]) {
            if (val == key) return true;
        }
        
        return false;
    }
};