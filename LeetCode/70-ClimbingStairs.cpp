class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
            
        int prev_prev = 1;
        int prev = 1;
        int cur = 0;
        
        for (int i=2; i<=n; ++i) {
            cur = prev + prev_prev;
            prev_prev = prev;
            prev = cur;
        }
        
        return cur;
    }
};
