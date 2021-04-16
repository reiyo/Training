// refer to https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/discuss/831480/C%2B%2BPython-O(n)
class Solution {
public:
    string modifyString(string s) {
        int n = s.length();

        for (int i=0; i<n; ++i) {
            if (s[i] != '?') continue;
            
            // ++s[i] is a trick
            for (s[i]='a'; s[i]<='c'; ++s[i]) {
                // use OR to consider boundary condition is also a trick
                if ((i-1<0 || s[i-1]!=s[i]) && (i+1>=n || s[i+1]!=s[i])) break;
            }
        }

        return s;
    }
};
