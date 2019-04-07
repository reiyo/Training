class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0]==1) return 0;
        int rnum = obstacleGrid.size();
        int cnum = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        
        for (size_t j=1; j<cnum; ++j) {
            if (!obstacleGrid[0][j]) obstacleGrid[0][j] = obstacleGrid[0][j-1];
            else obstacleGrid[0][j] = 0;
        }
        
        for (size_t i=1; i<rnum; ++i) {
            if (!obstacleGrid[i][0]) obstacleGrid[i][0] = obstacleGrid[i-1][0];
            else obstacleGrid[i][0] = 0;
        }        
                
        for (size_t i=1; i<rnum; ++i) {
            for (size_t j=1; j<cnum; ++j) {
                if (!obstacleGrid[i][j]) obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                else obstacleGrid[i][j] = 0;
            }
        }

        return obstacleGrid[rnum-1][cnum-1];
    }
};
