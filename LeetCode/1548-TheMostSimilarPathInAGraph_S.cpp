// refer to https://leetcode.com/problems/the-most-similar-path-in-a-graph/discuss/790240
// refer to https://leetcode.com/problems/the-most-similar-path-in-a-graph/discuss/788753
// Time Complexity: O(n^2 * m), where m is the length of targetPath
// Space Complexity: O(n * m)
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<list<int> > adj(n);

        // create an adjacency list for quick lookup
        for (int i=0; i<roads.size(); ++i) {
            int s = roads[i][0];
            int t = roads[i][1];
            adj[s].push_back(t);
            adj[t].push_back(s);
        }

        int m = targetPath.size();

        // dp[i][j] denotes minimum edit distance for targetPath with i moves (have visited i+1 cities), and we are now at city names[j]
        // initialize to m as the max distance is m
        vector<vector<int> > dp(m, vector<int>(n, m));
        vector<vector<int> > prev(m, vector<int>(n, -1));

        // "0 move and at city names[j]" is equivalent to start from city names[j]
        for (int j=0; j<n; ++j) {
            // it only takes a unit cost, if the starting city is not equal to the starting city in targetPath 
            if (names[j] == targetPath[0]) dp[0][j] = 0;
            else dp[0][j] = 1;
        }

        for (int i=1; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                // try to move from names[k] to names[j] along a valid edge
                for (auto k: adj[j]) {
                    if (dp[i-1][k] < dp[i][j]) {
                        // no cost for the moving from k to j according to the definition of min edit distance
                        dp[i][j] = dp[i-1][k];
                        prev[i][j] = k;
                    }
                }

                if (names[j] != targetPath[i]) ++ dp[i][j];
            }
        }
        
        /* 
           trick: last cannot be -1, because dp[m-1][j] can be m for all j,
           for example,
             4
             [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]]
             ["ATL","PEK","LAX","DXB"]
             ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
        */
        int min_dist = m;
        int last = 0;

        for (int j=0; j<n; ++j) {
            if (dp[m-1][j] < min_dist) {
                min_dist = dp[m-1][j];
                last = j;
            }
        }
        
        vector<int> res;
        res.push_back(last); // push the last city of the path

        for (int i=m-1; i>=1; --i) {
            res.push_back(prev[i][last]);
            last = prev[i][last];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
