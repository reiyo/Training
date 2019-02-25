vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    // refer to https://www.martinkysel.com/codility-genomicrangequery-solution/
    const int N = static_cast<int>(S.size());
    vector<int> lastA(N, -1);
    vector<int> lastC(N, -1);
    vector<int> lastG(N, -1);
    vector<int> lastT(N, -1);
    
    for (int i=0; i<N; ++i) {
        if (i > 0) {
            lastA[i] = lastA[i-1];
            lastC[i] = lastC[i-1];
            lastG[i] = lastG[i-1];
            lastT[i] = lastT[i-1];
        }
        
        if ('A' == S[i]) lastA[i] = i;
        else if ('C' == S[i]) lastC[i] = i;
        else if ('G' == S[i]) lastG[i] = i;
        else lastT[i] = i;
    } 
    
    const int M = static_cast<int>(P.size());
    vector<int> output(M, -1);
    
    for (int i=0; i<M; ++i) {
        if (lastA[Q[i]] >= P[i]) output[i] = 1;
        else if (lastC[Q[i]] >= P[i]) output[i] = 2;
        else if (lastG[Q[i]] >= P[i]) output[i] = 3; 
        else if (lastT[Q[i]] >= P[i]) output[i] = 4;        
    }

    return output; 
}
