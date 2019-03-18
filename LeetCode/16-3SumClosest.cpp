class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int diff = target - nums[0]-nums[1]-nums[2];
        
        for (int i=0; i<nums.size()-2; ++i) {
            int j=i+1;
            int k=nums.size()-1;
            int temp = target-nums[i];
            
            while (j<k) {
                int cur_diff = temp - nums[j] - nums[k];
                if (cur_diff == 0) return target;
                if (abs(cur_diff) < abs(diff)) diff = cur_diff;
                
                if (cur_diff > 0) {
                    while (j<k && nums[j] == nums[j+1]) ++j;
                    ++ j;
                }
                else {
                    while (j<k && nums[k] == nums[k-1]) --k;
                    --k;
                }
            }
        }
        
        return target - diff;
    }
};
