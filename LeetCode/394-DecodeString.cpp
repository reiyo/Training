class Solution {
public:
    string decodeString(string s) {
        stack<string> stStr;
        stack<int> stCnt;
        string curStr = "";
        int curCnt = 0;
        
        for (size_t i=0; i<s.size(); ++i) {
            const char c = s[i];
            
            if (isdigit(c)) {
                if (!curStr.empty()) {
                    stStr.push(curStr);
                    curStr.clear();    
                } else if (i > 0 && s[i-1]=='[') {
                    stStr.push("");
                }
                
                curCnt *= 10;
                curCnt += c - '0';
            }
            else if (c == '[') {
                stCnt.push(curCnt);
                curCnt = 0;
            }
            else if (c == ']') {
                const int cnt = stCnt.top();
                stCnt.pop();
                string temp = ""; 
                if (!stStr.empty()) {
                    temp = stStr.top();
                    stStr.pop();
                }
                for (int i=0; i<cnt; ++i) temp += curStr;
                curStr.swap(temp);
            } else {
                curStr += c;
            }
        }
        
        return curStr;
    }
};
