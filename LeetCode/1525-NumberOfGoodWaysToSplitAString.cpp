// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int numSplits(string s) {
        if (s.size() <= 1) return 0; 

        int left[26]  = {0};
        int right[26] = {0};
        int left_cnt  = 0;
        int right_cnt = 0;

        for (char c: s) {
            // below two lines can be replaced with "right_cnt += ++ right[c-'a'] == 1;"
            // others are similar, refer to https://leetcode.com/problems/number-of-good-ways-to-split-a-string/discuss/754678
            if (right[c-'a'] == 0) ++ right_cnt;
            ++ right[c-'a'];
        } 

        int res = 0;

        for (int i=0; i+1<s.size(); ++i) {
            char c = s[i];
            if (left[c-'a'] == 0) ++ left_cnt;
            ++ left[c-'a'];
            -- right[c-'a'];
            if (right[c-'a'] == 0) -- right_cnt;
            if (left_cnt == right_cnt) ++ res;
        }

        return res;
    }
};
