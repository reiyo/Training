class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        int myarray[256];
        memset(myarray, -1, sizeof(myarray));
        myarray[s[0]] = 0;
        int start = 0;
        int max_len = 1;
        
        for (int i=1; i<s.length(); ++i) { 
            if (myarray[s[i]] >= start) {
                start = myarray[s[i]] + 1;
            } 
            
            max_len = max(max_len, i-start+1); 
            myarray[s[i]] = i;
        }
        
        return max_len;
    }
};
