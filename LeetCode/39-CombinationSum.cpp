class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> current;
        
        sort(candidates.begin(), candidates.end());
        collect(candidates, 0, target, current, output);
        return output;
    }
    
    void collect(vector<int>& nums, int start, int target, vector<int>& cur, vector<vector<int>>& output) {
        if (0 == target) {
            output.push_back(cur);
            return;
        }
        
        for (int i=start; i<nums.size() && nums[i] <= target; ++i) {
            cur.push_back(nums[i]);
            collect(nums, i, target-nums[i], cur, output);
            cur.resize(cur.size()-1);
        }
    }
};
