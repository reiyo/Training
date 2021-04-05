class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string> > memo;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return traverse(s, dict, memo);
    }

    vector<string> traverse(string s, unordered_set<string>& dict, unordered_map<string, vector<string> >& memo) {
        if (memo.count(s)) return memo[s];

        vector<string> out;
        for (auto it=dict.begin(); it!=dict.end(); ++it) {
            const string& word = *it;

            if (word == s) { // this is a must, e.g., s="ab", wordDict=["a", "b"]
                out.push_back(word);
            }
            else if (word == s.substr(0, word.length())) {
                const vector<string>& res = traverse(s.substr(word.length()), dict, memo);

                for (auto it2=res.begin(); it2!=res.end(); ++it2) {
                    out.push_back(word + " " + *it2);
                }
            }
        }

        memo[s] = out;
        return out;        
    }
};
