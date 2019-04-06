class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int start = 0, end = 0;
        bool flag = true;
        bool hit = false;
        
        for (int i=0; i<s.length(); ++i) {
            if (s[i] != ' ') {
                end = i;
                
                if (flag) {
                    start = i;
                    flag = false;
                    hit = true;
                }
            } else flag = true;
        }
        
        return (hit)? end - start + 1 : 0;
    }
};
