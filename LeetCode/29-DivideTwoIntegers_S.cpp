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

class Solution {
public:
    bool getQuo(long long int& dividend, long long int divisor, long long int& quo) {
        long long int i = 1;
        long long int cur_div = divisor;

        while (dividend >= cur_div) {
            dividend -= cur_div;
            quo += i;            
            i += i;
            cur_div += cur_div;
        }

        if (dividend == 0) return true;
        else return false;
    }

    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        bool negative = false;
        long long int l_dividend = dividend;
        long long int l_divisor = divisor;
        if (dividend < 0) {
            l_dividend = 0 - l_dividend;
            negative = !negative;
        }
        if (divisor < 0) {
            l_divisor = 0 - l_divisor;
            negative = !negative;
        }
        long long int quo=0;

        while (!getQuo(l_dividend, l_divisor, quo)) {
            if (l_divisor > l_dividend) break;
        }

        if (negative) {
            quo = 0-quo;
            if (quo < INT_MIN) return INT_MAX;
            return quo;
        }
        else {
            if (quo > INT_MAX) return INT_MAX; 
            return quo;
        }
    }
};
