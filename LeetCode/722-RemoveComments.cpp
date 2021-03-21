class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string line;
        bool block = false;

        for (string &s: source) {
            int length = static_cast<int>(s.length());
            
            // use string::find could be more complicated
            for (int i=0; i<length; ++i) {
                if (block) {
                    // ++i is to skip '/'
                    if (i+1 < length && s[i] == '*' && s[i+1] == '/') { block = false; ++i; }
                }
                else {
                    if (i+1 < length && s[i] == '/' && s[i+1] == '/') break;
                    else if (i+1 < length && s[i] == '/' && s[i+1] == '*') { block = true; ++i; }
                    else {
                        // According to http://www.cplusplus.com/, it seems that
                        // push_back() may result in better performance than +=
                        line.push_back(s[i]);
                    }
                }
            }
            
            // !block considers the case ["a/*comment", "line", "more_comment*/b"] 
            // to be ["ab"]; that is, ignore newlines appear in a block comment
            if (!line.empty() && !block) {
                res.push_back(line);
                line.clear();
            }
        }

        return res;
    }
};
