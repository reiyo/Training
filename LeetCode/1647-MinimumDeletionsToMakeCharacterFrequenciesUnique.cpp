class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for (char c: s) { ++ freq[c-'a']; }

        sort(freq, freq+26, greater<int>());
        int res = 0;

        for (int i=1; i<26; ++i) {
            if (freq[i] > 0 && freq[i] >= freq[i-1]) {
                // "bbcebab" is a case that shows that the latter one must be smaller
                // than the previous only if the final frequency of the previous > 0 
                int diff = freq[i] - freq[i-1];
                if (freq[i-1] > 0) diff += 1;
                freq[i] -= diff;
                res += diff;
            }
        }

        return res;
    }
};
