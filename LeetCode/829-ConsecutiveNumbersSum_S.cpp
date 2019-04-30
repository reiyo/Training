class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int cnt = 0;
        
        // x + (x+1) + ... + (x+(k-1)) = N
        // => (x+(x+(k-1)))*k/2 = N
        // => kx = N - (k^2-k)/2
        // x is an integer, and it can be an integer if N-(k^2-k)/2 is a multiple of k
        // try to use k numbers, k+1 numbers, ...
        // k^2 makes N-(k^2-k)/2 close to 0, and even < 0, with an O(sqrt(N)) complexity 
        for (int k=1; ; ++k) {
            // (k^2 - k) is divisible by 2
            // because k^2-k = k*(k-1) and either k or (k-1) is an even number 
            const int kx = N - (k*k-k)/2;
            if (kx <= 0) break;
            if (kx % k == 0) ++ cnt;
        }
        
        return cnt;
    }
};
