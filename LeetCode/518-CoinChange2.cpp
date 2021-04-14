// time complexity: O(N * amount), where N is the number of coins
// space complexity: O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (auto v: coins) {
            // i starts from v; otherwise, it will be "if (i>=v) dp[i] += dp[i-v];"
            for (int i=v; i<=amount; ++i) {
                // not use the coin + use the coin
                dp[i] += dp[i-v];
            }
        }

        return dp[amount];
    }
};
