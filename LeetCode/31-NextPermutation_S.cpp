class Solution {
public:    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int t = nums.size()-2;
        
        while (t >= 0 && nums[t] >= nums[t+1]) -- t;
        
        if (t < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // search for the smallest one greater than nums[t]
        int i=t+1;

        for (; i<nums.size(); ++i) {
            if (nums[i]<=nums[t]) break;
        }

        // e.g., 125310 -> 135210 -> 130125
        swap(nums[t], nums[i-1]);
        reverse(nums.begin()+t+1, nums.end());
    }
};
