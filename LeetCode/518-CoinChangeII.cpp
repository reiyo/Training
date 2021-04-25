// time complexity: O(N * amount), where N is the number of coins
// space complexity: O(N * amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = static_cast<int>(coins.size());
        vector<vector<int> > dp(N+1, vector<int>(amount+1, 0));
        dp[0][0] = 1; // 1 way for 0 coin to get 0

        for (int i=1; i<=N; ++i) {
            int v = coins[i-1];
            
            for (int j=0; j<=amount; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j>=v) dp[i][j] += dp[i][j-v];
            }
        }

        return dp[N][amount];
    }
};

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
