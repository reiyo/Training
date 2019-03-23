class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup_cnt = 0;
        
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] == nums[i-1]) ++ dup_cnt;
            else nums[i-dup_cnt] = nums[i];
        }
        
        return nums.size()-dup_cnt;
    }
};
