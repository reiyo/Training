// refer to https://leetcode.com/problems/find-and-replace-in-string/discuss/130577
// Time Complexity: O(n + m), where n is the length of s, and m is the total length of the target strings
// Space Complexity: O(max(n, m))
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, string>> record(s.length(), {0, ""});
        
        for (int i=0; i<indices.size(); ++i) {
            if (s.compare(indices[i], sources[i].length(), sources[i]) == 0) {
                record[indices[i]] = {sources[i].length(), targets[i]};
            }
        }
        
        string res;
        
        for (int i=0; i<s.length(); ) {
            if (record[i].first == 0) {
                res += s[i];
                ++ i;
            }
            else {
                res += record[i].second;
                i += record[i].first;
            }
        }
        
        return res;
    }
};

// my solution
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<string> v;

        for (auto c: s) v.push_back(string(1, c));

        for (int i=0; i<sources.size(); ++i) {
            string& src=sources[i];

            int j=indices[i];
            int k=0;

            while (k<src.length()) {
                if (s[j] != src[k]) break;
                else {
                    ++ j;
                    ++ k;
                }
            }

            if (k>=src.length()) {
                j=indices[i];
                v[j++] = targets[i];

                while (j<indices[i]+src.length()) v[j++]="";
            }
        }

        string res;

        for (auto str: v) {
            if (str.length() > 0) res += str;
        }

        return res;
    }
};
