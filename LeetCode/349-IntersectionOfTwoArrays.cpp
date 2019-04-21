// refer to https://leetcode.com/problems/intersection-of-two-arrays/discuss/82001
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) return vector<int>();
        unordered_set<int> myset(nums1.begin(), nums1.end());
        vector<int> output;
        
        for (int val: nums2) {
            if (myset.erase(val) > 0) {
                output.emplace_back(val);
            }
        }
        
        return output;
        
        /*
        unordered_map<int, bool> mymap;
        vector<int> output;
        
        for (int val: nums1) {
            mymap[val] = false;
        }
        
        for (int val: nums2) {
            if (mymap.count(val)) {
                mymap[val] = true;
            }
        }
        
        for (auto it=mymap.begin(); it!=mymap.end(); ++it) {
            if (it->second) output.emplace_back(it->first);
        }
        
        return output;
        */
    }
};
