// refer to https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643429
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns of the input matrix
// Space Complexity: O(m * n), if the input matrix cannot be modified
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;

        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) continue;

                // skip the uppermost cells and the leftmost cells
                // the max size of the current cell can be determined by the max sizes of the three adjacent cells
                if (i != 0 && j != 0) matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i][j-1], matrix[i-1][j])) + 1;

                res += matrix[i][j]; 
            }
        }

        return res;
    }
};

// below is my original idea, the time complexity increase to O(k * m * n), where k is the side length of the max square that can be obtained
// the idea is somehow similar...
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int side = 2;
        int last = side - 1;
        bool find = true;

        while (find) {
            find = false;

            for (int i=0; i+1<matrix.size(); ++i) {
                for (int j=0; j+1<matrix[i].size(); ++j) {
                    if (matrix[i][j] == last && matrix[i+1][j] == last && matrix[i][j+1] == last && matrix[i+1][j+1] == last) {
                        matrix[i][j] = side;
                        find = true;
                    }
                }
            }

            ++ side;
            ++ last;
        }

        int res = 0;

        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[i].size(); ++j) res += matrix[i][j];
        }

        return res;
    }
};
