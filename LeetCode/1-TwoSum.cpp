class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        
        for (int i=0; i<nums.size(); ++i) {            
            if (mymap.count(nums[i])) {
                vector<int> out;
                out.push_back(mymap[nums[i]]);
                out.push_back(i);
                return out;
            } else {
                mymap[target - nums[i]] = i;
            }
        }
        
        return vector<int>();
    }
};
