class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string();
        int minlen = strs[0].length();
        
        for (int i=1; i<strs.size(); ++i) {
            minlen = min(minlen, static_cast<int>(strs[i].length()));
        }
        
        string output;
        
        for (int i=0; i<minlen; ++i) {
            for (int j=1; j<strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) return output;
            }
            
            output += strs[0][i];
        }
        
        return output;
    }
};
