class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {    
        if (nums.size() <= 3) return vector<vector<int>>();
        const int size = static_cast<int>(nums.size()); 
        vector<vector<int>> output;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<size-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
                
            for (int j=i+1; j<size-2; ++j) {
                if (j > (i+1) && nums[j] == nums[j-1]) continue;
                int curTarget = target - nums[i] - nums[j];
                int k = j+1;
                int r = size-1;
                
                while (k < r) {
                    const int sum = nums[k] + nums[r];
                    
                    if (sum == curTarget) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[r]};
                        output.push_back(temp);
                        --r;
                        ++k;
                        while (k < r && nums[r] == nums[r+1]) --r;              
                        while (k < r && nums[k] == nums[k-1]) ++k;
                    }
                    else if (sum > curTarget) {
                        -- r;
                        while (k < r && nums[r] == nums[r+1]) --r;
                    }
                    else {
                        ++ k;
                        while (k < r && nums[k] == nums[k-1]) ++k;
                    }
                }
            }
        }
        
        return output;
    }
};
