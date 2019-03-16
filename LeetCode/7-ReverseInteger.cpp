class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);
        int sum = 0;
        
        while (x > 0) {
            int res = x % 10;
            
            if (sign == 1) {
                if (sum > (INT_MAX - res)/10) return 0;
            } else {
                if ((-1 * sum) < (INT_MIN+res)/10) return 0;
            }
            
            sum = sum * 10 + res;
            x /= 10;
        }

        return sign * sum;
    }
};
