// refer to https://leetcode.com/problems/backspace-string-compare/discuss/135603/JavaC%2B%2BPython-O(N)-time-and-O(1)-space
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length()-1;
        int j = T.length()-1;

        while (1) {
            int cnt=0;
            while(i>=0) {
                if (S[i] == '#') {
                    ++ cnt;
                }
                else if (cnt > 0) {
                    -- cnt;
                }
                else break;
                -- i;
            }

            cnt = 0;
            while(j>=0) {
                if (T[j] == '#') {
                    ++ cnt;
                } else if (cnt > 0) {
                    -- cnt;
                }
                else break;
                -- j;
            }

            if (i >= 0 && j >= 0 && S[i] != T[j]) return false;
            if (i < 0 || j < 0) break;
            -- i;
            -- j;
        }
        
        return i==-1 && j==-1;
    }
};
