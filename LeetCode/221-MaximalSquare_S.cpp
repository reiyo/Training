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
