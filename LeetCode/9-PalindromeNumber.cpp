class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (x % 10 == 0) return false;
        
        int out = 0;
        
        while (x > out) {
            int res = x % 10;
            out = out * 10 + res;
            x /= 10;
        }
        
        return (x == out) || (x == out/10);
    }
};
