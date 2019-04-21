// refer to https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/85422
// unordered_map find and [] both have O(1) time complexity in average case, 
// but getRandom() is a problem, something like iter advance() may not result in O(1)
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // cannot use val2Index.count(val), because it takes linear time!!!!
        if (val2Index.find(val)!=val2Index.end()) return false;
        
        vals.emplace_back(val);
        val2Index[val] = static_cast<int>(vals.size())-1; 
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val2Index.find(val)==val2Index.end()) return false;
        
        const int lastVal = vals.back();
        const int rmIndex = val2Index[val];
        vals[rmIndex] = lastVal;
        val2Index[lastVal] = rmIndex;
        val2Index.erase(val);
        vals.pop_back();
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
    
    unordered_map<int, int> val2Index;
    vector<int> vals;
};
