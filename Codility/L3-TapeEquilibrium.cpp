int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int curdiff = A[0];
    
    for (size_t i=1; i<A.size(); ++i) {
        curdiff -= A[i];
    }

    int mindiff = abs(curdiff);
    
    for (size_t i=1; i+1<A.size(); ++i) {
        curdiff += (A[i] + A[i]);
        mindiff = min(mindiff, abs(curdiff));
    }
    
    return mindiff;
}
