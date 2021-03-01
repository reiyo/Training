class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> output;
        vector<int> current;
        collect(candidates, 0, target, current, output);
        return output;
    }
    
    void collect(vector<int>& nums, int start, int target, vector<int>& cur, vector<vector<int>>& output) {
        if (0 == target) {
            output.push_back(cur);
            return;
        }
        
        for (int i=start; i<nums.size() && nums[i]<=target; ++i) {
            // given that [1, 1, 1, 2], the if-statement guarantees that exactly [1, 1, x] can be considered, no [1, x, 1], if two ones are required
            if (i > start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            collect(nums, i+1, target-nums[i], cur, output);
            cur.pop_back();
        }
    }
};
