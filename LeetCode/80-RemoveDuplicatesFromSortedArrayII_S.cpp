class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int cur = 2;
        
        for (int i=2; i<nums.size(); ++i) {
            if (nums[i] != nums[cur-2]) nums[cur++] = nums[i];
        }
        
        return cur;
    }
};
