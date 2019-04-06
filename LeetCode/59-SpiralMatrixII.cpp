class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output(n, vector<int>(n, 0));
        
        int cnt = n * n;
        int counter = 0;
        int rowS = 0;
        int rowE = n-1;
        int colS = 0;
        int colE = n-1;
        
        while (counter < cnt) {
            for (int j=colS; j<=colE; ++j) {
                output[rowS][j] = ++ counter;
            }
            
            ++ rowS;
            //if (counter >= cnt) return output;
            
            for (int i=rowS; i<=rowE; ++i) {
                output[i][colE] = ++ counter;
            }
            
            -- colE;
            //if (counter >= cnt) return output;
            
            for (int j=colE; j>=colS; --j) {
                output[rowE][j] = ++ counter;
            }
            
            -- rowE;
            //if (counter >= cnt) return output;
            
            for (int i=rowE; i>=rowS; --i) {
                output[i][colS] = ++ counter;
            }
            
            ++ colS;
            //if (counter >= cnt) return output;
        }
        
        return output;
    }
};
