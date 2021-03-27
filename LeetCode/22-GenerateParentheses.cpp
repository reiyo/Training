class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string current;
        generate(n, n, current, output);
        return output;
    }
    
    void generate(int left, int right, string& current, vector<string>& output) {
        if (left < 0) return;
        
        if (left == 0 && right == 0) {
            output.push_back(current);
            return;
        }
        
        current += "(";
        generate(left-1, right, current, output);
        current.resize(current.size()-1);
        
        if (right > left) {
            current += ")";
            generate(left, right-1, current, output);
            current.resize(current.size()-1);
        }
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(string(""), n, 0, 0, res);
        return res;                
    }

    void generate(string s, int n, int left, int right, vector<string> &res) {
        if (left >= n && right >= n) {
            res.push_back(s);
            return;
        }

        if (left < n) generate(s+"(", n, left+1, right, res);

        //if (right < n && right < left)
        if (right < left) generate(s+")", n, left, right+1, res); 
    }
};
