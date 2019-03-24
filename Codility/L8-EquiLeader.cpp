#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    int dominator = A[0];
    int cnt = 1;
    
    for (int i=1; i<N; ++i) {
        if (cnt == 0) {
            dominator = A[i];
            cnt = 1;
        }
        else if (A[i] != dominator) {
            -- cnt;
        }
        else {
            ++ cnt;
        }
    }
    
    const int dominator_cnt = std::count(A.begin(), A.end(), dominator);
    if (dominator_cnt <= N/2) return 0;
    int output_cnt = 0;
    int prev_cnt = 0;
    int post_cnt = dominator_cnt;
    
    for (int i=0; i<N; ++i) {
        if (A[i] == dominator) {
            ++ prev_cnt;
            -- post_cnt;
        } 
        
        if (prev_cnt > (i+1)/2 && post_cnt > (N-i-1)/2) {
            ++ output_cnt;
        }
    }
    
    return output_cnt;
}
