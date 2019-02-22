int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    vector<bool> record(N+1, false);
    
    for (auto it=A.begin(); it!=A.end(); ++it) {
        if (*it >= 1 && *it <= N) record[*it] = true;
    }
    
    for (int i=1; i<=N; ++i) {
        if (!record[i]) return i;
    }
    
    return N+1;
}
