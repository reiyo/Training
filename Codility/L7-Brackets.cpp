#include <stack>

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    std::stack<char> mystack;
    
    for (string::const_iterator cit=S.begin(); cit!=S.end(); ++cit) {
        if (*cit == '{') {
            mystack.push('}');
        } else if (*cit == '[') {
            mystack.push(']');
        } else if (*cit == '(') {
            mystack.push(')');
        } else if (!(mystack.empty()) && (*cit == mystack.top())) {
            mystack.pop();
        } else {
            return 0;
        }
    }
    
    return (mystack.empty())? 1 : 0;
}
