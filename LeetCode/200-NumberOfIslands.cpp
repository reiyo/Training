// BFS solution: space is O(min(M, N)) where M is the number of rows and N is the number of columns
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        int res = 0;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '0') continue;
                ++ res;
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));

                // we have to set a grid to be visited right after the grid is
                // push into the queue; otherwise it will be Time Limit Exceeded
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    if (r > 0 && grid[r-1][c]=='1') {
                        q.push(make_pair(r-1, c));
                        grid[r-1][c] = '0';
                    }
                    if (c > 0 && grid[r][c-1]=='1') {
                        q.push(make_pair(r, c-1));
                        grid[r][c-1] = '0';
                    }
                    if (r < m-1 && grid[r+1][c]=='1') {
                        q.push(make_pair(r+1, c));
                        grid[r+1][c] = '0';
                    }
                    if (c < n-1 && grid[r][c+1]=='1') {
                        q.push(make_pair(r, c+1));
                        grid[r][c+1] = '0';
                    }
                }                
            }
        }
        return res;
    }
};

// DFS solution
class Solution {
public:
    void traverse(vector<vector<char>>& grid, int m, int n, int i, int j) {
        if (grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        if (i > 0) traverse(grid, m, n, i-1, j);
        if (j > 0) traverse(grid, m, n, i, j-1);
        if (i < m-1) traverse(grid, m, n, i+1, j);
        if (j < n-1) traverse(grid, m, n, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        int res = 0;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    traverse(grid, m, n, i, j);
                    ++ res;
                }
            }
        }

        return res;        
    }
};
