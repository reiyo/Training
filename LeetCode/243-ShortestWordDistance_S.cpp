// time complexity: O(n * m), where n is the number of words and m is the sum of the lengths of word1 and word2
// space complexity: O(1)
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        if (word1 == word2) return 0;
        int minDist = wordsDict.size();
        int id1 = -1;
        int id2 = -1;

        for (int i=0; i<wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                id1 = i;
                if (id2 >= 0) minDist = min(minDist, id1-id2);
            }
            else if (wordsDict[i] == word2) {
                id2 = i;
                if (id1 >= 0) minDist = min(minDist, id2-id1);
            }
        }

        return minDist;
    }
};

// optimization:
// 1. time: return 1 immediately if current min distance equals 1
// 2. space: keep only one index
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        if (word1 == word2) return 0;
        int minDist = wordsDict.size();
        int last_id = -1;

        for (int i=0; i<wordsDict.size(); ++i) {
            if (wordsDict[i] == word1 || wordsDict[i] == word2) {
                if (last_id != -1 && wordsDict[last_id] != wordsDict[i]) {
                    minDist = min(minDist, i-last_id);
                    if (minDist == 1) return 1;
                }
                last_id = i;
            }
        }

        return minDist;
    }
};
