class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int rowNum = static_cast<int>(matrix.size());
        const int colNum = static_cast<int>(matrix[0].size());
        vector<int> record(colNum, 0);
        int maxLen = 0;
        int pre = 0;
        
        for (int i=0; i<rowNum; ++i) {         
            for (int j=0; j<colNum; ++j) {
                const int temp = record[j];
                
                if (i==0 || j==0 || matrix[i][j]=='0') {
                    record[j] = matrix[i][j] - '0';
                }
                else {
                    // pre is upper-left, record[j] is upper, record[j-1] is left
                    record[j] = min(pre, min(record[j], record[j-1])) + 1;
                }
                
                maxLen = max(maxLen, record[j]);
                pre = temp;
            }
        }
        
        return maxLen * maxLen;
    }
};

// time complexity: O(m*n)
// space complexity: O(m*n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_len = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i=0; i<n; ++i) {
            if (matrix[0][i]=='1') {
                dp[0][i] = 1;
                max_len = 1;
            }
        }

        for (int i=0; i<m; ++i) {
            if (matrix[i][0]=='1') {
                dp[i][0] = 1;
                max_len = 1;
            }
        }

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (matrix[i][j] != '1') continue;
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
                max_len = max(max_len, dp[i][j]);
            }
        }    
        return max_len * max_len; 
    }
};

// time complexity: O(m*n)
// space complexity: O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_len = 0;
        vector<int> dp(n, 0);

        for (int i=0; i<n; ++i) {
            // dp[i] = 1 if matrix[0][i]=='1' else 0
            dp[i] = matrix[0][i] - '0'; 
            max_len = max(max_len, dp[i]);
        }

        for (int i=1; i<m; ++i) {
            // j == 0
            int prev = dp[0];
            dp[0] = matrix[i][0] - '0';
            max_len = max(max_len, dp[0]);

            for (int j=1; j<n; ++j) {
                int temp = dp[j];
                
                if (matrix[i][j] != '1') dp[j] = 0;
                else {
                    dp[j] = min(prev, min(dp[j-1], dp[j]))+1;
                    max_len = max(max_len, dp[j]);
                }
                
                prev = temp;
            }
        }
        
        return max_len * max_len; 
    }
};
