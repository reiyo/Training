// Not Manacher's algorithm..., Manacher's algorithm can refer to wiki or:
// http://www.csie.ntnu.edu.tw/~u91029/Palindrome.html
// https://www.itread01.com/content/1543482183.html
// Also, DP solution can refer to https://leetcode.com/problems/longest-palindromic-substring/discuss/2921
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

class Solution {
public:
    int expand(int left, int right, string& s) {
        if (s[left] != s[right]) return 1;
        int len = right - left + 1;

        while (left>0 && right+1<s.length() && s[left-1] == s[right+1]) {
            len += 2;
            -- left;
            ++ right;
        } 

        return len;
    }

    string longestPalindrome(string s) {
        int maxlen = 1;
        int start = 0;

        for (int i=0; i+1<s.length(); ++i) {
            int odd = expand(i, i, s);
            int even = expand(i, i+1, s);
            int curmax = max(odd, even);

            if (curmax > maxlen) {
                maxlen = curmax;
                start = i;
            }           
        }

        if (maxlen % 2) return s.substr(start - (maxlen-1)/2, maxlen);
        else return s.substr(start - (maxlen-2)/2, maxlen);
    }
};
