int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int leftCnt = 0;
    
    // different from L7-Brackets, no need to use a stack here
    for (string::const_iterator cit=S.begin(); cit!=S.end(); ++cit) {
        if (*cit == '(') ++ leftCnt;
        else -- leftCnt;
        
        if (leftCnt < 0) return 0;
    }
    
    return (leftCnt != 0)? 0 : 1;
}
