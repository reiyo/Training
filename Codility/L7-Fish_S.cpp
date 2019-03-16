#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = static_cast<int>(A.size());
    int survive = 0;
    std::stack<int> mystack; // keep those move downward
    
    for (int i=0; i<N; ++i) {
        if (B[i] == 1) { // downstream
            mystack.push(i);
        }
        else { // upstream
            while (!mystack.empty()) {
                const int j = mystack.top();
                if (A[j] > A[i]) break;
                mystack.pop();
            }
            
            if (mystack.empty()) ++ survive;
        }
    }
    
    // those who move downward are also survived
    survive += static_cast<int>(mystack.size());
    
    return survive;
}
