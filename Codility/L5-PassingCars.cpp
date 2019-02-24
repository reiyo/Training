int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    int cnt = 0;
    
    for (int i=0; i<N; ++i) {
        if (1 == A[i]) ++ cnt;
    }
    
    if (0 == cnt) return 0;
    long long int sum = 0;
    
    for (int i=0; i<N; ++i) {
        if (1 == A[i]) -- cnt;
        else sum += cnt;
    }
    
    return (sum <= 1000000000)? sum : -1;
}
