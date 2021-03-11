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

// https://www.itread01.com/content/1549857275.html: 由於一個合數總是可以分解成若干個質數的乘積，那麼如果把質數（最初只知道2是質數）的倍數都去掉，那麼剩下的就是質數了。
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
