// refer to https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/453880
//          https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/451787
// Time Complexity: O(m * n * k), where m/n is the number of rows/columns of the grid; note that each cell may be pushed into the queue at most k times
// Space Complexity: O(m * n * k)
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // cover the case of a large k that allows us to move toward the goal directly
        // cover the boundary case [[0]]
        if (k >= m-1+n-1) return m-1+n-1;
        
        vector<vector<int> > dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        queue<vector<int> > q;
        vector<vector<int> > visited(m, vector<int>(n, -1));
        
        q.push({0, 0, k});
        visited[0][0] = k; // known grid[0][0] = 0, remain the capability to remove k
        int steps = 0;
        int minStepsToTarget = m-1 + n-1;

        while (!q.empty()) {
            int cnt = q.size();
            ++ steps;

            // the for loop allows the use of "steps" to track the number of steps
            // otherwise, we need to save the number of steps in the queue
            for (int i=0; i<cnt; ++i) {
                int r = q.front()[0];
                int c = q.front()[1];
                int cur_k = q.front()[2];
                q.pop();
                int idealSteps = minStepsToTarget;
                              
                for (auto& d: dirs) {
                    int rr = r + d[0];
                    int cc = c + d[1];
                    
                    if (rr < 0 || rr >= m || cc < 0 || cc >= n) continue; 
                    if (rr == m-1 && cc == n-1) return steps;
                    
                    int kk = cur_k - grid[rr][cc];
                    
                    // "if (kk < 0 || kk <= visited[rr][cc])" can be replaced with "if (kk <= visited[rr][cc])"
                    // it may be the best to initialize visited to -1; note that visited=0 is still needed, e.g., 
                    // k=0, visited=-1 and visited=0 denote unvisited and visited for common BFS, respectively
                    if (kk <= visited[rr][cc]) continue; // k=0, grid=1 or cannot be better
                    
                    int stepsToTarget = (m-1-rr) +(n-1-cc);
                    
                    // the nested if-statements are just a shortcut, not necessary
                    // kk is large enough to remove the remaining obstacles
                    // -1 is because (m-1, n-1) must not be an obstacle
                    if (kk >= stepsToTarget-1) {
                        // -1 is because we have moved at most 1 step towards (m-1, n-1); of course we might not move towards the target
                        if (stepsToTarget == idealSteps-1) return steps + stepsToTarget;
                    };
                    
                    visited[rr][cc] = kk;
                    q.push({rr, cc, kk});
                    
                    // for the shortcut, we have to ensure we get the min steps for cases of the same round, i.e., "for (int i=0; i<cnt; ++i)"
                    // to do so, we save minStepsToTarget as an estimation of ideal number of remaining steps for the next round
                    minStepsToTarget = min(minStepsToTarget, stepsToTarget);
                }
            }
        }

        return -1;
    }
};
