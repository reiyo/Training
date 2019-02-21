int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) return 1;
    
    const int len = static_cast<int>(A.size());
    vector<bool> record(len, false);
    
    for (auto it=A.begin(); it!=A.end(); ++it) {
        const int i = *it - 1;
        if (i < 0 || i >= len || record[i]) return 0;
        else record[i] = true;
    }
    
    return 1;
}
