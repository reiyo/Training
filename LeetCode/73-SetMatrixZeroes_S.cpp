class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size()) return;
        int rnum = matrix.size();
        int cnum = matrix[0].size();
        bool rflag = false;
        bool cflag = false;
        
        for (int i=0; i<rnum && !cflag; ++i) {
            if (!matrix[i][0]) cflag = true;
        }
        
        for (int j=0; j<cnum && !rflag; ++j) {
            if (!matrix[0][j]) rflag = true;
        }
        
        for (int i=1; i<rnum; ++i) {
            for (int j=1; j<cnum; ++j) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int j=1; j<cnum; ++j) {
            if (!matrix[0][j]) {
                for (int i=1; i<rnum; ++i) {
                    matrix[i][j] = 0;
                }
            }
        } 
        
        for (int i=1; i<rnum; ++i) {
            if (!matrix[i][0]) {
                for (int j=1; j<cnum; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }   
        
        if (cflag) {
            for (int i=0; i<rnum; ++i) {
                matrix[i][0] = 0;
            }
        }
        
        if (rflag) {
            for (int j=0; j<cnum; ++j) {
                matrix[0][j] = 0;
            }            
        }
    }
};
