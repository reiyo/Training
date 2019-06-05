class LFUCache {
public:
    LFUCache(int capacity) {
        this->cap = capacity;
        minCnt = 0;
    }
    
    int get(int key) {
        if (keyValMap.find(key)==keyValMap.end()) return -1;
        
        const int val = keyValMap[key];
        int cnt = keyCntMap[key];
        list<int>::iterator it = keyPosMap[key];
        cntKeyMap[cnt].erase(it);
        
        // important!!
        if (cnt == minCnt && cntKeyMap[cnt].size() <= 0) minCnt = cnt+1;
        
        ++ cnt;
        it = cntKeyMap[cnt].insert(cntKeyMap[cnt].begin(), key);
        
        keyCntMap[key] = cnt;
        keyPosMap[key] = it;

        return val;
    }
    
    void put(int key, int value) {
        // important!
        if (cap <= 0) return;
        
        if (keyValMap.find(key) != keyValMap.end()) {
            keyValMap[key] = value;
            get(key); // good idea !!
            return;
        }
        
        if (keyCntMap.size() >= cap) {
            const int rmKey = cntKeyMap[minCnt].back();
            keyValMap.erase(rmKey);
            keyCntMap.erase(rmKey);
            keyPosMap.erase(rmKey);
            cntKeyMap[minCnt].pop_back();
            // not needed to consider how to update minCnt here, it will be updated soon
        }
        
        keyValMap[key] = value;
        keyCntMap[key] = 1;
        keyPosMap[key] = cntKeyMap[1].insert(cntKeyMap[1].begin(), key);
        minCnt = 1;
    }
    
    // it may be better to define a structure containing val, cnt, and pos
    unordered_map<int, int> keyValMap;
    unordered_map<int, int> keyCntMap;
    unordered_map<int, list<int>::iterator> keyPosMap;
    unordered_map<int, list<int>> cntKeyMap;
    int cap;
    int minCnt;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
