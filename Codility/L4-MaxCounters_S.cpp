vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
        // write your code in C++14 (g++ 6.2.0)
    vector<int> output(N, 0);
    int lastassign = 0;
    int maxval = 0;
    
    for (auto it=A.begin(); it!=A.end(); ++it) {
        const int X = *it;
        
        if (X <= N) {
            output[X-1] = max(output[X-1], lastassign);
            ++ output[X-1];
            maxval = (output[X-1]>maxval) ? output[X-1] : maxval;
        }
        else {
            lastassign = maxval; 
        }
    }
    
    for (auto it=output.begin(); it!=output.end(); ++it) {
        *it = max(*it, lastassign);
    }
    
    return output;
}
