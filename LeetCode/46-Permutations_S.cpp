class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        run(nums, 0, output);
        return output;
    }
    
    void run(vector<int>& nums, int k, vector<vector<int>>& output) {
        if (k >= nums.size()) {
            output.push_back(nums);
            return;
        }
        
        for (int i=k; i<nums.size(); ++i) {
            swap(nums[i], nums[k]);
            run(nums, k+1, output);
            swap(nums[i], nums[k]);
        }
    }
};
