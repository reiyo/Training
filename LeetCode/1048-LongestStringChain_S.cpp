// refer to nkallen's solution in https://leetcode.com/problems/longest-string-chain/discuss/294890
// Time Complexity: O(n * L^2), where n is the number of words, and L is the average length of a word
// Space Complexity: O(n * L)
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_map<string, int> wordMap;

        int res = 0;
        for (string& word: words) {
            res = max(res, helper(wordSet, word, wordMap));
        }

        return res;
    }

    int helper(unordered_set<string>& wordSet, string& word, unordered_map<string, int>& wordMap) {
        if (wordMap.find(word) != wordMap.end()) return wordMap[word];

        int cnt = 1;
        for (int i=0; i<word.length(); ++i) {
            // remove a character; btw, substr(0, 0) will give a string with length 0
            string cand = word.substr(0, i) + word.substr(i+1);

            if (wordSet.find(cand) != wordSet.end()) {
                // +1 is to consider the current word itself
                cnt = max(cnt, helper(wordSet, cand, wordMap) + 1);
            }
        }

        wordMap[word] = cnt;
        return cnt;
    }
};
