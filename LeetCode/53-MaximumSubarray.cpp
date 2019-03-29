class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        
        int maxSofar = nums[0];
        int maxVal = maxSofar;
        
        for (int i=1; i<nums.size(); ++i) {
            maxSofar = max(nums[i], nums[i] + maxSofar);
            maxVal = max(maxVal, maxSofar);
        }
        
        return maxVal;
    }
};
