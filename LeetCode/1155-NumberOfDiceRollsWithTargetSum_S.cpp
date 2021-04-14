// Time: O(d * f * target)
// Space: O(d * target)
class Solution {
public:
    int traverse(int d, int f, int t, vector<vector<int> >& dict) {
        if (d <= 0 || t <= 0) {
            return (d == 0 && t == 0);
        }
    
        if (dict[d][t] >= 0) return dict[d][t];
        dict[d][t] = 0;
        
        for (int i=1; i<=f; ++i) {
            dict[d][t] = (dict[d][t] + traverse(d-1, f, t-i, dict)) % 1000000007;
        }
    
        return dict[d][t];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        if (d <= 0) return 0;
        if (target <= 0) return 0;
        if (target<d || target>f*d) return 0;
        vector<vector<int> > dict(d+1, vector<int>(target+1, -1));
        return traverse(d, f, target, dict);
    }
};

// Time: O(d * f * target)
// Space: O(d * target)
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int> > dp(d+1, vector<int>(target+1, 0));
        dp[0][0] = 1; // 1 way for 0 dice to get target 0

        for (int i=1; i<=d; ++i) {
            for (int j=1; j<=f; ++j) {
                // k starts from j, otherwise, we have to add "if (k>=j)" so that k-j>=0
                for (int k=j; k<=target; ++k) {
                    dp[i][k] = (dp[i][k] + dp[i-1][k-j]) % 1000000007;
                }
            }
        }

        return dp[d][target];
    }
};

// refer to https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/discuss/355940/C%2B%2B-Coin-Change-2
// Time: O(d * f * target)
// Space: O(target)
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1; // 1 way for 0 dice to get target 0

        for (int i=1; i<=d; ++i) {
            // no need to set dp_tmp[0]=1 because 0 way for >=1 dice to get target 0
            vector<int> dp_tmp(target+1, 0);
            
            for (int j=1; j<=f; ++j) {
                // k starts from j, otherwise, we have to add "if (k>=j)" so that k-j>=0
                for (int k=j; k<=target; ++k) {
                    dp_tmp[k] = (dp_tmp[k] + dp[k-j]) % 1000000007;
                }
            }
            
            dp.swap(dp_tmp);
        }

        return dp[target];
    }
};
