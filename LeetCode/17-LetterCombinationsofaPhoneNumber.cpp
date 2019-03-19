class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if (digits.empty()) return output;
        
        vector<string> myvec = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        const string& first = myvec[digits[0]-'2'];
        
        for (int i=0; i<first.size(); ++i) {
            output.push_back(string(1, first[i]));
        }
        
        for (int i=1; i<digits.size(); ++i) {
            const string& temp = myvec[digits[i]-'2'];
            vector<string> current;
            current.swap(output);
            
            for (int j=0; j<current.size(); ++j) {
                for (int k=0; k<temp.size(); ++k) {
                    output.push_back(current[j] + temp[k]);
                }
            }
        }
        
        return output;
    }
};
