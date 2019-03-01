int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // refer to https://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/
    const int N = static_cast<int>(A.size());
    double minval = (A[0]+A[1])/2.0;
    int minid = 0;
    
    for (int i=0; i<N-2; ++i) {
        double sub1 = (A[i]+A[i+1])/2.0;
        double sub2 = (A[i]+A[i+1]+A[i+2])/3.0;
        
        if (sub1 < minval) {
            minval = sub1;
            minid = i;
        }
        
        if (sub2 < minval) {
            minval = sub2;
            minid = i;
        }
    }
    
    if ((A[N-2]+A[N-1])/2.0 < minval) {
        return N-2;
    }
    else {
        return minid;
    }
}
