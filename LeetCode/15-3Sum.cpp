class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if (nums.size() < 3) return output;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i+2<nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int t = 0-nums[i];
            int j = i+1;
            int k = nums.size()-1;
            
            while (j < k) {
                if (nums[j]+nums[k] == t) {
                    output.push_back({nums[i], nums[j], nums[k]});                    
                    while (j < k && nums[j] == nums[j+1]) ++j;
                    while (j < k && nums[k] == nums[k-1]) --k;
                    ++ j;
                    -- k;
                } else if (nums[j]+nums[k] < t) {
                    while (j < k && nums[j] == nums[j+1]) ++j;
                    ++ j;           
                } else {
                    while (j < k && nums[k] == nums[k-1]) --k;
                    -- k;
                }
            }
        }
        
        return output;
    }
};
