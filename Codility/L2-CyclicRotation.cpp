void rotate(int s, int e, vector<int> &vec) {
    while (s < e) {
        int temp = vec[s];
        vec[s] = vec[e];
        vec[e] = temp;
        ++ s;
        -- e;
    }
}

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) return A;
    K = K % A.size();
    if (0 == K) return A;
    const int len = static_cast<int>(A.size());
    
    rotate(0, len-1, A);
    rotate(0, K-1, A);
    rotate(K, len-1, A);
    
    return A;
}
