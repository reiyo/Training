class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<bool> primetable(n+1, true);
        int count = 0;
        int upper = sqrt(n);
        
        for (int i=2; i<n; ++i) {
            if (primetable[i]) {
                ++ count;
                
                if (i > upper) continue;
                
                for (int j=i*i; j<n; j+=i) {
                    primetable[j] = false;
                }
            }
        }
        
        return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;

        int sq = static_cast<int>(sqrt(n)+0.5);
        vector<bool> p(n, true);

        for (int i=2; i<=sq; ++i) {
            if (p[i]) {
                for (int j=i+i; j<n; j+=i) p[j] = false;
            }
        } 

        int res = 0;
        for (int i=2; i<n; ++i) {
            if (p[i]) ++ res;
        }

        return res;
    }
};
