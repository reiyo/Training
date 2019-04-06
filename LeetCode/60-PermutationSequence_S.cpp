class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n+1, 1);
        for (int i=2; i<=n; ++i) fac[i] = i * fac[i-1];
        
        vector<int> table(n, 1);
        for (int i=0; i<n; ++i) table[i] = i+1;
        
        k -= 1;
        string output;
        
        for (int i=n; i>=1; --i) {
            int cnt = fac[i-1];
            int index = k / cnt;
            output += std::to_string(table[index]);
            table.erase (table.begin()+index);
            k -= (index * cnt);
        }
        
        return output;
    }
};
