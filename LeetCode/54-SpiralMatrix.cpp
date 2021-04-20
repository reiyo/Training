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

// same idea
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        res.reserve(m*n); // this can reduce memory consumption
        
        int t=0, b=m-1, l=0, r=n-1;
        
        while (t <= b && l <= r) {
            for (int i=l; i<=r; ++i) res.push_back(matrix[t][i]);
            
            // otherwise, we will loop the same line from right to late
            if (t == b) break;
            
            for (int i=t+1; i<=b; ++i) res.push_back(matrix[i][r]);
            
            // otherwise, we will loop the same column from bottom to top
            if (l == r) break;
            
            for (int i=r-1; i>=l; --i) res.push_back(matrix[b][i]);
            
            for (int i=b-1; i>t; --i) res.push_back(matrix[i][l]);
            ++ t;
            -- b;
            ++ l;
            -- r;
        }

        return res;
    }
};
