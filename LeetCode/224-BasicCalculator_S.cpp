class Solution {
public:
    int calculate(string s) {
        stack<int> mystack;
        int num = 0;
        int sign = 1;
        int result = 0;
        
        for (char c: s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else {
                result += sign * num;
                num = 0;
                
                if (c == '+') sign = 1;
                else if (c == '-') sign = -1;
                else if (c == '(') {
                    mystack.push(result);
                    mystack.push(sign);
                    result = 0;
                    sign = 1;
                }
                else if (c == ')') {
                    result *= mystack.top();
                    mystack.pop();
                    result = mystack.top() + result;
                    mystack.pop();
                }
            }
        }
        
        if (num != 0) {
            result += (sign * num);
        }
        
        return result;
    }
};
