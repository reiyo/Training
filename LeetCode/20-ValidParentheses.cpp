class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        
        for (auto it=s.begin(); it!=s.end(); ++it) {
            if (*it == ')') {
                if (mystack.empty() || mystack.top() != '(') return false;
                mystack.pop();
            } else if (*it == '}') {
                if (mystack.empty() || mystack.top() != '{') return false;
                mystack.pop();                
            } else if (*it == ']') {
                if (mystack.empty() || mystack.top() != '[') return false;
                mystack.pop();                
            } else mystack.push(*it);
        }
        
        return (mystack.empty())? true : false;
    }
};
