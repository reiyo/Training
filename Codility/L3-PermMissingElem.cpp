int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) return 1; // N+1 = 0+1 = 1
    const int N = static_cast<int>(A.size());
    int out = N+1;
    
    for (int i=0; i<N; ++i) {
        out ^= (i+1);
        out ^= A[i];
    }
    
    return out;
}
