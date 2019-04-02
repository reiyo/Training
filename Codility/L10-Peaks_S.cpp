// refer to https://stackoverflow.com/questions/20886486/codility-peaks-complexity
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    if (N <= 2) return 0;
    
    // accumulate the number of peaks
    vector<int> accPeak(N, 0);
    
    // 0 and N-1 cannot be peak
    for (int i=1; i<N-1; ++i) {
        accPeak[i] = accPeak[i-1];
        
        if (A[i] > A[i-1] && A[i] > A[i+1]) accPeak[i] += 1;
    }
    
    accPeak[N-1] = accPeak[N-2];
    
    // consider one block
    if (accPeak[N-1] <= 0) return 0;
    int maxBlockCnt = 1;
    
    // block size cannot be 1 because 0/(N-1) cannot be peak -> i<N
    for (int i=2; i<N; ++i) {
        if (N % i != 0) continue;
        const int blockSize = N / i;
        int index = blockSize;
        bool flag = true;

        // the first block has to be with at least a peak
        if (accPeak[index-1] <= 0) flag = false;

        while (index < N && flag) {
            // compare the last items of two adjacent blocks
            if (accPeak[index-1+blockSize] <= accPeak[index-1]) flag = false;
            else index += blockSize;
        }
        
        if (flag) maxBlockCnt = i;
    }
    
    return maxBlockCnt;
}
