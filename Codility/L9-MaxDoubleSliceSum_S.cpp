// refer to https://stackoverflow.com/questions/20660989/max-double-slice-sum
#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    vector<int> maxsum_until(N, 0);
    vector<int> maxsum_from(N, 0);
    
    // impossible to use A[0] or A[N-1] as parts of any double slice 
    for (int i=1; i<N-1; ++i) {
        maxsum_until[i] = std::max(maxsum_until[i-1]+A[i], 0);
    }
    
    for (int i=N-2; i>0; --i) {
        maxsum_from[i] = std::max(maxsum_from[i+1]+A[i], 0);
    }
    
    int maxsum = 0;
    
    for (int y=1; y<N-1; ++y) {
        maxsum = std::max(maxsum, maxsum_until[y-1] + maxsum_from[y+1]);
    }
    
    return maxsum;
}
