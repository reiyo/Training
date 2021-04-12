// Time: O(d * f * target)
// Space: O(d * target)
class Solution {
public:
    int traverse(int d, int f, int t, vector<vector<int> >& dict) {
        if (d <= 0 || t <= 0) {
            return (d == 0 && t == 0);
        }
    
        if (dict[d][t] >= 0) return dict[d][t];
        dict[d][t] = 0;
        
        for (int i=1; i<=f; ++i) {
            dict[d][t] = (dict[d][t] + traverse(d-1, f, t-i, dict)) % 1000000007;
        }
    
        return dict[d][t];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        if (d <= 0) return 0;
        if (target <= 0) return 0;
        if (target<d || target>f*d) return 0;
        vector<vector<int> > dict(d+1, vector<int>(target+1, -1));
        return traverse(d, f, target, dict);
    }
};
