// refer to https://leetcode.com/problems/stone-game-iii/discuss/598795
//          https://leetcode.com/problems/stone-game-iii/discuss/564260
// below are recursion -> recursion with memorization (top-down DP) -> bottom-up DP -> bottom-up DP with memory optimization 

// Time Complexity: O(3^n)
// Space Complexity: O(1)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int res = helper(stoneValue, 0);

        if (res > 0) return "Alice";
        else if (res < 0) return "Bob";
        else return "Tie";
    }

    int helper(vector<int>& stoneValue, int start) {
        if (start >= stoneValue.size()) return 0;

        int take = stoneValue[start];
        int maxScore = take - helper(stoneValue, start+1);

        for (int i=start+1; i<start+3 && i<stoneValue.size(); ++i) {
            take += stoneValue[i]; 
            // helper(stoneValue, i+1) is the max score the second player can obtain
            maxScore = max(maxScore, take - helper(stoneValue, i+1));
        }

        return maxScore;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        // memo[i] ignores stones before i (exclusive)
        // memo[i] stores the max score starts from i; this can be Alice's, or Bob's
        // INT_MAX is used to check if memo[i] has been written or not
        // the max sum is 50000 * 1000 < 10^9, so INT_MAX can be used
        vector<int> memo(stoneValue.size(), INT_MAX);
        int res = helper(stoneValue, 0, memo);

        if (res > 0) return "Alice";
        else if (res < 0) return "Bob";
        else return "Tie";
    }

    int helper(vector<int>& stoneValue, int start, vector<int>& memo) {
        if (start >= stoneValue.size()) return 0;
        if (memo[start] < INT_MAX) return memo[start];

        int take = stoneValue[start];
        int maxScore = take - helper(stoneValue, start+1, memo);

        for (int i=start+1; i<start+3 && i<stoneValue.size(); ++i) {
            take += stoneValue[i]; 
            // helper(stoneValue, i+1, memo) is the max score the second player can obtain
            maxScore = max(maxScore, take - helper(stoneValue, i+1, memo));
        }

        memo[start] = maxScore;
        return maxScore;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> memo(n+1, 0); // n+1 is used because "for (int i=n-1; ...)"
        
        // trick: from the last to the begin
        for (int i=n-1; i>=0; --i) {
            int take = stoneValue[i];
            int maxScore = take - memo[i+1];
            
            for (int j=i+1; j<i+3 && j<n; ++j) {
                take += stoneValue[j];
                maxScore = max(maxScore, take - memo[j+1]);
            }
            
            memo[i] = maxScore;
        }

        if (memo[0] > 0) return "Alice";
        else if (memo[0] < 0) return "Bob";
        else return "Tie";
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> memo(3+1, 0);
        
        // trick: from the last to the begin
        for (int i=n-1; i>=0; --i) {
            int take = stoneValue[i];
            int maxScore = take - memo[(i+1)%4];
            
            for (int j=i+1; j<i+3 && j<n; ++j) {
                take += stoneValue[j];
                maxScore = max(maxScore, take - memo[(j+1)%4]);
            }
            
            memo[i%4] = maxScore;
        }

        if (memo[0] > 0) return "Alice";
        else if (memo[0] < 0) return "Bob";
        else return "Tie";
    }
};
