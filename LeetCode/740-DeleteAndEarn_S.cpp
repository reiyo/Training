class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // each int is within [1, 10000]
        vector<int> bins(10001, 0);
        
        for (auto n: nums) {
            bins[n] += n;
        }
        
        int take = 0, skip = 0;
        
        for (int i=1; i<static_cast<int>(bins.size()); ++i) {
            const int take_i = skip + bins[i];
            const int skip_i = max(take, skip);
            take = take_i;
            skip = skip_i;
        }
        
        return max(take, skip);
    }
};
