class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] != 1) continue;
                queue<pair<int, int>> q;
                int area = 0;
                q.push(make_pair(i, j));
                grid[i][j] = 2;

                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    ++ area;

                    // note that grid has to be set before/right after the push; otherwise
                    // it is possible two same grids are pushed and get a larger area!!
                    if (r-1>=0 && grid[r-1][c]==1) {
                        q.push({r-1, c}); // same as q.push(make_pair(r-1, c));
                        grid[r-1][c] = 2;
                    }
                    if (r+1<m && grid[r+1][c]==1) {
                        q.push({r+1, c});
                        grid[r+1][c] = 2;
                    }
                    if (c-1>=0 && grid[r][c-1]==1) {
                        q.push({r, c-1});
                        grid[r][c-1] = 2;
                    }
                    if (c+1<n && grid[r][c+1]==1) {
                        q.push({r, c+1});
                        grid[r][c+1] = 2;
                    }
                }

                max_area = max(max_area, area);
            }
        }

        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 2) grid[i][j] = 1;

        return max_area;
    }
};
