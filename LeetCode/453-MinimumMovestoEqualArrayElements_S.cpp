class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        const int n = static_cast<int>(nums.size());
        const long long int minVal = *min_element(nums.begin(), nums.end());
        long long int sum = 0;
        for (int i=0; i<n; ++i) sum += nums[i];
        
        return sum - n * minVal;
    }
};
