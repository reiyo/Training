// time complexity: O(n * S), where n is the number of coins, and S is the amount
// space complexity: O(n * S)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = static_cast<int>(coins.size());
        vector<vector<int> > dp(n+1, vector<int>(amount+1, INT_MAX));

        // trick is the setting of INT_MAX and 0
        for (int i=0; i<=n; ++i) dp[i][0] = 0;
        
        for (int i=1; i<=n; ++i) {
            int v = coins[i-1];
            
            for (int j=1; j<=amount; ++j) {
                dp[i][j] = dp[i-1][j];
                
                // dp[i][j-v] includes dp[i-1][j-v] & results of using i-th coin previously
                if (j>=v && dp[i][j-v] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i][j-v]+1);
                }
            }
        }

        return (dp[n][amount]!=INT_MAX)? dp[n][amount] : -1;
    }
};
