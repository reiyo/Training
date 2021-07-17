// refer to https://leetcode.com/problems/range-module/discuss/108923
// Time Complexity: O(n) for addRange() and removeRange(), O(n log n) for queryRange(), where n is the number of operations
// Space Complexity: O(n)
// trick: keeps no overlaps for the intervals stored in the map, and thus not needed to cosndier the cases of overlapped intervals in the map 
class RangeModule {
public:
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        auto it = m.lower_bound(left);

        if (it != m.begin()) {
            --it;
            if (it->second < left) ++it;
        }

        while (it!=m.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = m.erase(it);
        }

        m[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (it == m.begin()) return false;
        -- it;
        return (it->first <= left && it->second >= right); 
    }
    
    void removeRange(int left, int right) {
        auto it = m.lower_bound(left);

        if (it != m.begin()) {
            --it;
            if (it->second < left) ++it;
        }
        
        while (it!=m.end() && it->first < right) {
            if (it->second > right) m[right] = it->second;
            
            if (it->first < left) {
                m[it->first] = left;
                ++ it;
            }
            else it = m.erase(it);
        }
    }
private:
    map<int, int> m;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
