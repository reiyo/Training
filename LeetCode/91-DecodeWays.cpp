class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        
        vector<int> table(s.size()+1, 0);
        table[0] = 1;
        
        for (int i=1; i<table.size(); ++i) {     
            for (int j=0; j<i; ++j) {
                string str = s.substr(j, i-j);
                if (str[0] == '0') continue;
                int val = atoi(str.c_str());
                
                if (val>=1 && val <= 26) {
                    table[i] += (table[j]);
                }
            }
        }
        
        return table[table.size()-1];
    }
};
