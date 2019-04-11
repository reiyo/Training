class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n<0 || k<0) return vector<vector<int>>();
        
        vector<vector<int>> output;
        vector<int> cur;
        
        collect(n, k, 1, cur, output);
        return output;
    }
    
    void collect(int n, int k, int c, vector<int> &cur, vector<vector<int>> &output)
    {
        if (k == 0) {
            output.push_back(cur);
            return;
        }
        
        for (int i=c; i<=n-k+1; ++i) {
            cur.push_back(i);
            collect(n, k-1, i+1, cur, output);
            cur.resize(cur.size()-1);
        } 
        
        return;   
    }
};
