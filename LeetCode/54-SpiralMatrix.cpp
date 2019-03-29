class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        
        if (matrix.empty()) return output;
        const int m = matrix.size();
        const int n = matrix[0].size();
        const int size = m * n;
        int rowS = 0, rowE = m-1;
        int colS = 0, colE = n-1;
        
        while (1) {
            for (int j=colS; j<=colE; ++j)
                output.push_back(matrix[rowS][j]);
            
            if (output.size() >= size) break;
            ++ rowS;
            
            for (int i=rowS; i<=rowE; ++i) 
                output.push_back(matrix[i][colE]);
            
            if (output.size() >= size) break;
            -- colE;
                
            for (int j=colE; j>=colS; --j)
                output.push_back(matrix[rowE][j]);
            
            if (output.size() >= size) break;
            -- rowE;
            
            for (int i=rowE; i>=rowS; --i) 
                output.push_back(matrix[i][colS]);
            
            if (output.size() >= size) break;
            ++ colS;
                
        }
        
        return output;
    }
};
