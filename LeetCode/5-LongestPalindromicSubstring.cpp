// Not Manacher's algorithm..., Manacher's algorithm can refer to wiki or:
// http://www.csie.ntnu.edu.tw/~u91029/Palindrome.html
// https://www.itread01.com/content/1543482183.html
class Solution {
public:
    int expand(const string& s, int l, int r) {
        int len = 0;
        
        while (l >= 0 && r<s.length() && s[l]==s[r]) {
            len += 2;
            -- l;
            ++ r;
        }
        
        return len;
    }
    
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        int max_len = 1;
        int start = 0;
        
        for (int i=1; i<s.length(); ++i) {
            int odd_len  = expand(s, i-1, i+1) + 1;
            int even_len = expand(s, i-1, i); 
            int cur_len  = max(odd_len, even_len);
            
            if (cur_len > max_len) {
                max_len = cur_len;
                start = i;
            }
        }
        
        if (max_len % 2) return s.substr(start-(max_len-1)/2, max_len);
        else             return s.substr((start-1)-(max_len-2)/2, max_len);
    }
};
