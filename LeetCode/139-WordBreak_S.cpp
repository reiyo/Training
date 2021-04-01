class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length(), false);
        
        // dp[k] is true if s[0...k] can be formed by dict
        for (int i=0; i<s.length(); ++i) {
            // s[0...j-1] and s[j...i]; j=0 refers to null; j<=i is a must
            for (int j=0; j<=i; ++j) {
                if ((j==0 || dp[j-1]) && dict.count(s.substr(j, i-j+1))>0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()-1];
    }
};
