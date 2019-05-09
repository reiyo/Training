class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key)!=m.end()) {
            const int value = m[key]->second;
            l.erase(m[key]);
            l.push_front(make_pair(key, value));
            m[key] = l.begin();
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key)!=m.end()) {
            l.erase(m[key]);
        } 
        else if (m.size() >= cap) {          
            const int rmkey = l.back().first;
            l.erase(m[rmkey]);
            m.erase(rmkey);             
        }
        
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l; // key, value
    int cap;
};
