vector<int> getMinPrimeSieves(const int maxVal)
{
    // 0 refers to prime; otherwise, it will be the min-prime factor of the value
    vector<int> minPrimeSieves(maxVal+1, 0);
    
    // Not needed to test any number (A*B, A<=B) between i*i+1 and maxVal 
    // because A must be checked earlier
    // e.g., maxVal = 25, we check 2 to 5, and then stop,
    //       while 21=3*7 must be marked when we check 3 earlier
    for (int i=2; i*i<=maxVal; ++i) {
        if (minPrimeSieves[i] == 0) {
            // start from i*i because for i * j (j<i), j must be checked earlier
            for (int j=i*i; j<=maxVal; j+=i) {
                if (minPrimeSieves[j]==0) minPrimeSieves[j] = i;
            }
        }
    }

    return minPrimeSieves;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> minPrimeSieves = getMinPrimeSieves(N);
    vector<int> accSemiPrimes(N+1, 0);
    
    // note that there will be runtime error if we compute all pairs of primes to
    // find all semiprimes

    // for each number, check if the number is a semiprime
    for (size_t i=1; i<accSemiPrimes.size(); ++i) {
        // a semiprime is not a prime, that is, a prime must not be a semiprime
        if (minPrimeSieves[i] == 0) continue;
        
        // now i is not a prime; also we know minPrimeSieves[i] is i's min-prime factor
        // thus i is divisible by minPrimeSieves[i] (i.e., remainder=0)
        // if the quotient is a prime, it means i is a product of two primes
        if (minPrimeSieves[i/minPrimeSieves[i]] == 0) accSemiPrimes[i] = 1;
    }
    
    // accumulate for later use
    for (size_t i=1; i<accSemiPrimes.size(); ++i) {
        accSemiPrimes[i] += accSemiPrimes[i-1];
    }

    const int M = static_cast<int>(P.size());
    vector<int> output(M, 0);
    
    for (int i=0; i<M; ++i) {
        output[i] = accSemiPrimes[Q[i]] - accSemiPrimes[P[i]-1];    
    }
    
    return output;
}
