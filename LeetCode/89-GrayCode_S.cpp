class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) return vector<int>(1, 0);
        
        vector<int> results = {0, 1};
        
        for (int i=1; i<n; ++i) {
            int size = results.size();
            int val = 1 << i;
            
            for (int j=size-1; j>=0; --j) {
                results.push_back(results[j] | val);
            }    
        }
        
        return results;
    }
};
