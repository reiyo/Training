// refer to https://codility.com/media/train/solution-flags.pdf
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    if (N <= 2) return 0; // no peaks, so no flags needed
    
    vector<int> nextFlag(N, -1);
    
    for (int i=N-2; i>0; --i) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) nextFlag[i] = i;
        else nextFlag[i] = nextFlag[i+1];
    }
    
    nextFlag[0] = nextFlag[1];
    if (nextFlag[0] < 0) return 0; // no peaks
    int maxOut = 0;
    int flagCnt = 1;
    
    // set 1 flag and then set (flagCnt-1) flags
    // 3 flags set to 0*, 1, 2, 3*, 4, 5, 6* -> 1 + (3-1) * 3
    while (1 + (flagCnt-1) * flagCnt <= N) {
        // set 1st flag
        int pos = nextFlag[0];
        int cnt = 1;
        
        while (cnt < flagCnt && pos+flagCnt < N) {
            pos = nextFlag[pos+flagCnt]; // next pos
            if (pos < 0) break;
            ++ cnt;
        } 
        
        if (cnt >= flagCnt) maxOut = max(flagCnt, maxOut);
        
        ++ flagCnt;
    }
    
    return maxOut;
}
