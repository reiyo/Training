/* Same as LeetCode 121 */
// Solution 1
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() <= 1) return 0;
    int maxgain = 0;
    size_t buy = 0;
        
    for (size_t i=0; i<A.size(); ++i) {
        if (A[i] < A[buy]) buy = i;
        else {
            const int diff = A[i] - A[buy];
            if (diff > maxgain) maxgain = diff;
        }
    }
    
    return maxgain;
}

// Solution 2
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() <= 1) return 0;
    size_t buy = 0;
    size_t sell = 1;
    int maxgain = max(0, A[sell]-A[buy]);
        
    for (size_t i=1; i<A.size(); ++i) {
        if (A[i] < A[buy]) {
            if (i+1 < A.size()) {
                buy = i;
                sell = i+1;
                maxgain = max(maxgain, A[sell]-A[buy]);
            }
        }
        else if (A[i] > A[sell]) {
            sell = i;
            maxgain = max(maxgain, A[sell]-A[buy]);
        }
    }
    
    return maxgain;
}
