class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> cur;
        
        output.push_back(vector<int>());
        
        for (int i=1; i<=nums.size(); ++i) {
            collect(nums, i, 0, cur, output);
        }
        
        return output;
    }
    
    void collect(const vector<int>& nums, int k, int c, vector<int> &cur, vector<vector<int>> &output)
    {
        if (k == 0) {
            output.push_back(cur);
            return;
        }
        
        for (int i=c; i<=nums.size()-k; ++i) {
            cur.push_back(nums[i]);
            collect(nums, k-1, i+1, cur, output);
            cur.resize(cur.size()-1);
        }
        
        return;
    }
};
