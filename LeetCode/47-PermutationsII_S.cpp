class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        getPermutation(nums, 0, result);
        return result;
    }
    
    void getPermutation(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        set<int> myset;
        
        for (int i=index; i<nums.size(); ++i) {
            if (myset.count(nums[i])) continue;
            else {
                myset.insert(nums[i]);
                swap (nums[i], nums[index]);
                getPermutation(nums, index+1, result);
                swap (nums[i], nums[index]);
            }
        }
    }
};
