#include <cmath>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    const int maxlen = sqrt(N);
    if ((maxlen * maxlen) == N) return 4 * maxlen;
    
    for (int i=maxlen+1; i>0; --i) {
        const int temp = (N / i);
        if (i * temp == N) return 2 * (i+temp);
    }
    
    return -1;
}
