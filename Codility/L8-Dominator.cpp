#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) return -1;
    const int N = static_cast<int>(A.size());
    int dominator = 0;
    int cnt = 1;
    
    for (int i=1; i<N; ++i) {
        if (cnt <= 0) {
            dominator = i;
            cnt = 1;
        }
        else if (A[i] != A[dominator]) {
            cnt -= 1;    
        }
        else {
            ++ cnt;
        }
    }
    
    if (cnt <= 0) return -1;
    
    const int occurance = std::count(A.begin(), A.end(), A[dominator]);
    
    return (occurance > N/2)? dominator : -1;
}
