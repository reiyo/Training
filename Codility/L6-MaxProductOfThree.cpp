#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int max1 = *max_element(A.begin(), A.end());
    if (0 == max1) return 0;
    
    const int N = static_cast<int>(A.size());
    
    nth_element(A.begin(), A.begin()+(N-3), A.end());
    const int max3 = A[N-3];
    nth_element(A.begin(), A.begin()+(N-2), A.end());
    const int max2 = A[N-2];
        
    if (max1 > 0) {
        // -3, -2, -1, 1
        // -3, -2, 1, 2
        // -3, 1, 2, 3
        nth_element(A.begin(), A.begin(), A.end());
        const int min1 = A[0];
        nth_element(A.begin(), A.begin()+1, A.end());
        const int min2 = A[1];

        return max(min1*min2*max1, max1*max2*max3);
    } 
    else {
        return max1*max2*max3;
    }
}
