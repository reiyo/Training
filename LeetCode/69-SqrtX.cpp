class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        
        long long int left = 1;
        long long int right = x;
        
        while (left <= right) {
            long long int mid = (left + right)/2;
            long long int sq = mid * mid;
            
            if (sq == x) {
                return mid;
            } else if (sq > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            } 
        }
        
        return right;
    }
};
