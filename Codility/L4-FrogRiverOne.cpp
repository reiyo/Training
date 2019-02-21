int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (X > static_cast<int>(A.size())) return -1;
    
    const int N = static_cast<int>(A.size());
    vector<bool> record(N+1, false);
    int cnt = 0;
    
    for (size_t i=0; i<A.size(); ++i) {
        const int j = A[i];
        
        if (j <= N && !record[j]) {
            record[j] = true;
            ++ cnt;
            if (cnt >= X) return i;
        }
    }
    
    return -1;
}
