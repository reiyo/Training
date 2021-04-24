class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        sq.reserve(sqrt(n));
        
        for (int i=1; i<=sqrt(n); ++i) sq.push_back(i*i);

        int cnt = sq.size();
        vector<vector<int> > dp(cnt+1, vector<int>(n+1, INT_MAX));
        dp[0][0] = 0;

        for (int i=1; i<=cnt; ++i) {
            int v = sq[i-1];

            for (int j=0; j<=n; ++j) {
                dp[i][j] = dp[i-1][j];

                if (j >= v && dp[i][j-v]!=INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][j-v]+1);
            }
        }

        return dp[cnt][n];
    }
};
