class Solution {
public:
    string convert(string s, int numRows) {
        if (1 == numRows) return s;
            
        vector<string> myvec(numRows);
        int cnt = 0;
        bool toggle = false;
        
        for (int i=0; i<s.length(); ++i) {
            myvec[cnt] += s[i];
            
            if (!toggle) {
                if (cnt+1 >= numRows) {
                    toggle = !toggle;
                    -- cnt;
                }
                else ++ cnt;
            }
            else {
                if (0 == cnt) {
                    toggle = !toggle;
                    ++ cnt;
                }
                else -- cnt;
            }
        }
        
        string output;
        
        for (auto it=myvec.begin(); it!=myvec.end(); ++it) {
            output += *it;
        }
        
        return output;
    }
};
