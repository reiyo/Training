// refer to @ericxu10101 in https://leetcode.com/problems/n-queens/discuss/19808
// Time Complexity: O(n!)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sol(n, string(n, '.'));
        
        // record the location of each queen that has been placed
        // not a necessary variable, but make it easy to be programmed and good for runtime improvement
        vector<int> state(n);

        dfs(0, n, state, sol, res);
        return res;
    }

    // place the first queen on the first row, the second queen on the second row, and so on
    void dfs(int row, int n, vector<int>& state, vector<string>& sol, vector<vector<string>>& res) {
        // all of the queens have been placed
        if (row >= n) {
            res.push_back(sol);
            return;
        }

        // consider to place the current queen on every possible column
        for (int col=0; col<n; ++col) {
            sol[row][col] = 'Q';
            state[row] = col;

            if (isSafe(row, col, state)) {
                // place the next queen
                dfs(row+1, n, state, sol, res);
            }

            sol[row][col] = '.';
        }
    }

    bool isSafe(int row, int col, vector<int>& state) {
        // if some previous queen has been placed on the same column
        for (int i=0; i<row; ++i) {
            if (state[i] == col) return false;
        }

        // check if the slope between the location of some previous queen and that of the current queen is +1 or -1
        for (int i=0; i<row; ++i) {
            if (abs(row-i) == abs(col-state[i])) return false;
        }

        return true;
    }
};
