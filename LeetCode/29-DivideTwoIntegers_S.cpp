class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        const int sign = ((dividend<0) ^ (divisor<0)) ? -1 : 1;
        long long divd = llabs(dividend);
        long long divr = llabs(divisor);
        long long cur = divr;
        long long mul = 1;
        long long res = 0;
        
        while (divd >= cur) {
            while (divd >= cur) {
                cur <<= 1;
                mul <<= 1;
            }
            cur >>= 1;
            mul >>= 1;
            res += mul;
            divd -= cur;
            cur = divr;
            mul = 1;
        }

        return sign * res;
    }
};
