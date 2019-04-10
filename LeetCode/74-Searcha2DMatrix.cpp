class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
            
        int left = 0;
        int right = matrix.size()-1;
        
        while (left <= right) {
            int mid = (left+right)/2;
            
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if (right < 0) return false;
        int rid = right;
        left = 0;
        right = matrix[rid].size() - 1;
        
        while (left <= right) {
            int mid = (left+right)/2;
            
            if (matrix[rid][mid] == target) return true;
            else if (matrix[rid][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return false;
    }
};
