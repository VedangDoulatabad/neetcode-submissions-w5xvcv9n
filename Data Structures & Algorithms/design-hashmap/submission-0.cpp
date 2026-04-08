class MyHashMap {
private:
    static const int size = 1000;
    vector<list<pair<int, int>>> buckets;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashMap() {
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int index = hash(key);

        for (auto& p : buckets[index]) {
            if (p.first == key) {
                p.second = value; // update
                return;
            }
        }

        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);

        for (auto& p : buckets[index]) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);

        for (auto it = buckets[index].begin(); it != buckets[index].end(); it++) {
            if (it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};