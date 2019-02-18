int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int maxcnt = 0, cnt = 0;
    bool rflag = false;
    
    while (N > 0) {
        if (N & 0x1) {
            if (rflag == false) {
                rflag = true;
            }
            else {
                maxcnt = max(maxcnt, cnt);
            }
            
            cnt = 0;
        } else {
            ++ cnt;
        }
        
        N /= 2;
    }
    
    return maxcnt;
}
