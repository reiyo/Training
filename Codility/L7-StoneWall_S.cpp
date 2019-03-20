#include <stack>

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    std::stack<int> mystack;
    int cnt = 0;
    
    // consider the skyline, consisting of edges with different heights
    // the idea of the greedy algorithm: suppose there are two edges, h1 and h2,
    // where h2 comes after h1, and h1 > h2
    // for h1, we assign a block with height, h1; then, we check h2 and find that
    // h1 > h2; we now make a horizontal cut. That is, we make a block with height,
    // (h1 - h2). So far, we'd like to use a block of height, (h1-h2), and a block
    // of height, h2, to build the wall. Of course, the block of height, (h1-h2),
    // will be placed on top of the block of height, h2. Two blocks are necessary
    // to build the wall
    for (size_t i=0; i<H.size(); ++i) {
        while (!mystack.empty() && (H[i] < mystack.top())) {
            ++ cnt;        // add the block of height, "h1-h2"
            mystack.pop(); // will not to use the block of height, "h1," anymore
        }
        
        if (mystack.empty()) mystack.push(H[i]);
        else if (H[i] > mystack.top()) mystack.push(H[i]);
    }
    
    cnt += static_cast<int>(mystack.size());
    
    return cnt;
}
