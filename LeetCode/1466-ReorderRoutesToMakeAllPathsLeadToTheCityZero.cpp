// refer to https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/discuss/661672
class Solution {
public:
    void traverse(vector<vector<int> > &adj, int prev, int cur, int &cnt) {
        // trick: a visited array is not needed for a tree; previous is sufficient
        for (int i=0; i<adj[cur].size(); ++i) {
            int child = abs(adj[cur][i]);

            if (child != prev) {
                if (adj[cur][i] > 0) ++ cnt;
                traverse(adj, cur, child, cnt);
            }
        }        
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int> > adj(n, vector<int>());

        // trick: use positive/negative for edge direction 
        for (vector<int>& c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }

        int cnt = 0;
        traverse(adj, -1, 0, cnt);
        return cnt;                
    }
};
