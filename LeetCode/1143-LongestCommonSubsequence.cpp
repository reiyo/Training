class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = static_cast<int>(text1.length());
        int n = static_cast<int>(text2.length());
        
        if (m < n) return longestCommonSubsequence(text2, text1);

        //vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    //dp[i][j] = dp[i-1][j-1]+1;
                    dp[i%2][j] = dp[(i-1)%2][j-1]+1;
                }
                else {
                    //dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
                }
            }
        }

        //return dp[m][n];
        return dp[m%2][n];
    }
};
