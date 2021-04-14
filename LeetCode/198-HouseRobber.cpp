// time complexity: O(n), where n is the size of nums
// space complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = static_cast<int>(nums.size());
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);

        for (int i=2; i<n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }

        return dp[n-1];
    }
};

// time complexity: O(n), where n is the size of nums
// space complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int n = static_cast<int>(nums.size());
        int next_next = nums[0];
        int next = max(next_next, nums[1]);

        for (int i=2; i<n; ++i) {
            int cur = max(next, next_next+nums[i]);
            next_next = next;
            next = cur;
        }

        return next;
    }
};
