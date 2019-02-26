class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        int i = 0, j = n-1;
        
        while (i<m && j>=0) {
            if (target == matrix[i][j]) return true;
            else if (target > matrix[i][j]) ++ i;
            else -- j;
        }
        
        return false;
    }
};
