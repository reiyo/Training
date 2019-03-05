#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // refer to https://codesays.com/2014/solution-to-triangle-by-codility/ , where it
    // proves (1) only need to check adjacent numbers if the array is sorted,
    // and (2) only need to check A[P] + A[Q] > A[R]
    const int N = static_cast<int>(A.size());
    std::sort(A.begin(), A.end());
    
    for (int i=0; i<N-2; ++i) {
        // A[i] + A[i+1] > A[i+2] => avoid overflow, A[i] + (A[i+1] - A[i+2]) 
        if (A[i] + (A[i+1] - A[i+2]) > 0) return 1;
    }
    
    return 0;
}
