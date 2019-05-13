class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results(1, vector<int>());
        int last = 0;
        
        for (int i=0; i<nums.size(); ++i) {
            int cnt = results.size();
            int j=0;
            
            if (i > 0 && nums[i] == nums[i-1]) {
                j = cnt-last;
            }
            else {     
                last = cnt;
            }
            
            for (; j<cnt; ++j) {
                results.push_back(results[j]);
                results[results.size()-1].push_back(nums[i]);
            }
        }
        
        return results;
    }
};
