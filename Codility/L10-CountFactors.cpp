#include <cmath>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    if (N == 1) return 1;
    int sq = sqrt(N);
    int cnt = 1; // 1
    
    for (int i=2; i<=sq; ++i) {
        if (N % i == 0) cnt += 2;
    }
    
    if (sq * sq == N) -- cnt; 
    cnt += 1; // N itself
    return cnt;
}
