class Solution {
public:
    int addDigits(int num) {
        // refer to https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
        // 10 % 9 == 1 % 9
        // e.g., abc => (a*10^2 + b*10^1 + c) % 9 = (a*1 + b*1 + c*1) % 9
        // suppose a+b+c >= 10, say, (a+b+c) = (d*10+e), so
        // (a*1 + b*1 + c*1) % 9 = (d*10+e) % 9 = (d*1+e) % 9 = ...
        // As it can be proved that the process of adding digits of a number will
        // result in a smaller number, we may eventually have, say, (g) % 9, and g < 10
        // g % 9 = g if g != 9, and g = 9, otherwise
        if (num == 0) return 0;
        int res = num % 9;
        return (res==0)? 9 : res;
        
        /*
        while (num >= 10) {
            num = oneTimeAdd(num);
        }
        
        return num;
        */
    }
    
    /*
    int oneTimeAdd(int num) {
        int r=0;
        int s=0;
        
        do {
            s += num % 10;
            num = num / 10;
        } while (num > 0);
        
        return s;
    }
    */
};
