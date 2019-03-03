int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int quotient = A / K;
    if ((A % K) != 0) ++ quotient;
    
    int start = K * quotient;
    if (start > B) return 0;
    
    return 1+((B - start)/K);
}
