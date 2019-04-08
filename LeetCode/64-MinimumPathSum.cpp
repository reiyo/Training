class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        size_t rnum = grid.size();
        size_t cnum = grid[0].size();
        
        for (size_t j=1; j<cnum; ++j) {
            grid[0][j] += grid[0][j-1];
        }
        
        for (size_t i=1; i<rnum; ++i) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (size_t i=1; i<rnum; ++i) {
            for (size_t j=1; j<cnum; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[rnum-1][cnum-1];
    }
};
