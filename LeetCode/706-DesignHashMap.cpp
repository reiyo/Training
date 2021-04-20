class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(): mapsize(10000) {
        mymap.resize(mapsize);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        list<pair<int, int> >& mylist = mymap[key % mapsize]; 
        
        for (auto it=mylist.begin(); it!=mylist.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }        
        
        //mylist.push_back(make_pair(key, value));
        mylist.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        list<pair<int, int> >& mylist = mymap[key % mapsize]; 
        
        for (auto it=mylist.begin(); it!=mylist.end(); ++it) {
            if (it->first == key) return it->second;
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        list<pair<int, int> >& mylist = mymap[key % mapsize]; 

        for (auto it=mylist.begin(); it!=mylist.end(); ++it) {
            if (it->first == key) {
                mylist.erase(it);
                return;
            }
        }
    }
private:
    vector<list<pair<int, int> > > mymap;
    int mapsize;
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
