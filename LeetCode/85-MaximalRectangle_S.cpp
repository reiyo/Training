// refer to https://leetcode.com/problems/maximal-rectangle/discuss/29054
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n-1);
        int maxArea = 0;
        
        for (int i=0; i<m; ++i) {
            int curLeft = 0;
            int curRight = n-1;
            
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == '1') ++ height[j];
                else height[j] = 0;
            }
            
            // from left to right
            // left[j] is for previous row, and curLeft is for current row 
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == '1') left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;   // not to bound the left (we know height[j]=0 now)
                    curLeft = j+1;
                }
            }
            
            // from right to left
            for (int j=n-1; j>=0; --j) {
                if (matrix[i][j] == '1') right[j] = min(right[j], curRight);
                else {
                    right[j] = n-1;
                    curRight = j-1;
                }
            }
            
            for (int j=0; j<n; ++j) {
                maxArea = max(maxArea, (right[j]-left[j]+1)*height[j]);
            }
        }
        
        return maxArea;
    }
};
