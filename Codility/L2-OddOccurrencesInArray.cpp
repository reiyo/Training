int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    
    for (vector<int>::const_iterator cit=A.begin(); cit!=A.end(); ++cit) {
        result ^= *cit;
    }
    
    return result;
}
