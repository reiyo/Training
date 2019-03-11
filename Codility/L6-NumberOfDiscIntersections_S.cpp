#include <algorithm>

// refer to https://codesays.com/2014/solution-to-beta2010-number-of-disc-intersections-by-codility
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
   
    // avoid overflow
    vector<long long int> uppers(N, 0);
    vector<long long int> lowers(N, 0);
    
    // avoid overflow
    for (int i=0; i<N; ++i) {
        uppers[i] = i + static_cast<long long int>(A[i]);
        lowers[i] = i - A[i];
    }
    
    std::sort(uppers.begin(), uppers.end());
    std::sort(lowers.begin(), lowers.end());
    int total = 0;
    int j = 0;
    
    for (int i=0; i<N; ++i) {
        while ((j < N) && (lowers[j] <= uppers[i])) {
            ++ j;
        }
        
        /*  
         *  Consider the following case,
         *  i =      0     1     2
         *           ]     ]     ]
         *      [ [    [ [    [    [
         *  j = 0 1    2 3    4    5
         *  When i = 2, j = 5, it is expected that for i=2,
         *  there will be 5 (i=0, i=1, i=2, i=3, i=4) intersections.
         *  But we have to remove those paired with i=1 and i=2.
         *  That is, the discs are closed. Further, we have to remove some one
         *  paired with i=2 itself.
         */
        total += (j - i -1);
        
        if (total > 10000000) return -1;
    }

    return total;
}
