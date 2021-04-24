// Similar to coin change problems; this problem has several better solutions than below
// time complexity: O(n * sqrt(n))
// space complexity: O(n * sqrt(n))
class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        sq.reserve(sqrt(n));
        
        for (int i=1; i<=sqrt(n); ++i) sq.push_back(i*i);

        int cnt = sq.size();
        vector<vector<int> > dp(cnt+1, vector<int>(n+1, INT_MAX));
        
        // trick to consider the remainder (i.e., j-v) itself is a perfect square
        // 0 way to use 0 perfect square for target 0 
        dp[0][0] = 0;

        for (int i=1; i<=cnt; ++i) {
            int v = sq[i-1];

            for (int j=0; j<=n; ++j) {
                dp[i][j] = dp[i-1][j];

                // "dp[i][j-v]!=INT_MAX" considers the case that the first perfect squares can not reach j-v; this condition can be removed actually 
                if (j >= v && dp[i][j-v]!=INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][j-v]+1);
            }
        }

        return dp[cnt][n];
    }
};

// time complexity: O(n * sqrt(n))
// space complexity: O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int i=1; i<=sqrt(n); ++i) {
            int v = i*i;

            // j=0 is not helpful because the presence of "if (j >= v)"
            for (int j=1; j<=n; ++j) {
                // not needed to check if "dp[j-v]!=INT_MAX" may be because
                // every numbers can be reached by 1's (1 is a perfect square)
                if (j >= v) dp[j] = min(dp[j], dp[j-v]+1); 
            }
        }

        return dp[n];
    }
};
