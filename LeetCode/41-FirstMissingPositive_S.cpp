class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        
        // check if there is any 1
        int i=0;
        for (; i<n; ++i) {
            if (nums[i] == 1) break;
        }
        if (i >= n) return 1;

        // use 1 to replace numbers <= 0 so that 
        // every number can change from being positive to negative
        for (i=0; i<n; ++i) {
            if (nums[i] <= 0) nums[i] = 1;
        }

        // nums[i] corresponds to the presence of i+1
        for (i=0; i<n; ++i) {
            int cur = abs(nums[i]);
            
            if (cur <= n) {
                // below is equivalent to if (nums[cur-1] > 0) nums[cur-1] = - nums[cur-1];
                nums[cur-1] = - abs(nums[cur-1]);
            }
        }
        
        for (i=0; i<n; ++i) {
            if (nums[i] > 0) return i+1;
        }
        
        return i+1;
    }
};
