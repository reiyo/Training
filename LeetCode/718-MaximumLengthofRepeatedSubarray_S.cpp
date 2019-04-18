class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int m = static_cast<int>(A.size());
        const int n = static_cast<int>(B.size());
        int maxLen = 0;
        
        for (int k=0; k<n; ++k) {
            int curMaxLen = 0;
            
            for (int i=0, j=k; i<m && j<n; ++i, ++j) {
                if (A[i] == B[j]) {
                    curMaxLen += 1;
                    maxLen = max(maxLen, curMaxLen);
                }
                else curMaxLen = 0;
            }
        }
        
        for (int k=1; k<m; ++k) {
            int curMaxLen = 0;
            
            for (int i=k, j=0; i<m && j<n; ++i, ++j) {
                if (A[i] == B[j]) {
                    curMaxLen += 1;
                    maxLen = max(maxLen, curMaxLen);
                }
                else curMaxLen = 0;                
            }
        }
        
        return maxLen;
        
        /*
        vector<vector<int>> record(m, vector<int>(n, 0));
        
        for (int i=0; i<m; ++i) {
            if (A[i] == B[0]) record[i][0] = 1;
        }
        
        for (int j=0; j<n; ++j) {
            if (A[0] == B[j]) record[0][j] = 1;
        }
        
        int maxlen = 0;
        
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (A[i] == B[j]) {
                    record[i][j] = record[i-1][j-1]+1;
                    maxlen = max(maxlen, record[i][j]);
                }
                else record[i][j] = 0;
            }
        }
        
        return maxlen;
        */
    }
};
