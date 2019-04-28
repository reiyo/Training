class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        for (size_t i=0; i<nums.size(); ++i) {
            if (i > 0) leftSum += nums[i-1];
            rightSum -= nums[i];
            
            if (leftSum == rightSum) return i;
        }
        
        return -1;
    }
};
