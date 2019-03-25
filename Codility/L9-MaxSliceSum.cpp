#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    
    if (std::all_of(A.begin(), A.end(), [](int i){return i<=0;})) {
        return *std::max_element(A.begin(), A.end());
    }
    
    long long int maxSum = 0;
    long long int sum = 0;
    
    for (int i=0; i<N; ++i) {
        sum += A[i];
        
        if (A[i] >= 0) maxSum = std::max(maxSum, sum);
        else if (sum < 0) sum = 0;
    }
    
    return static_cast<int>(maxSum);
}
