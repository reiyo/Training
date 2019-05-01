class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        const int len = static_cast<int>(words.size());
        const bool same = (word1 == word2);
        int id1 = len;
        int id2 = -len;
        int minDist = 2*len;
        
        for (int i=0; i<len; ++i) {
            if (words[i] == word1) {
                if (same) id2 = id1;
                    
                id1 = i;
            }
            else if (words[i] == word2) {
                id2 = i;
            }
                
            minDist = min(minDist, abs(id1-id2));
        }
        
        /*
        const int len = static_cast<int>(words.size());
        int id1 = -1;
        int id2 = -1;
        int minDist = len;
        
        if (word1 != word2) {
            for (int i=0; i<len; ++i) {
                if (words[i] == word1) {
                    id1 = i;
                }
                else if (words[i] == word2) {
                    id2 = i;
                }
                
                if (id1 >= 0 && id2 >= 0) minDist = min(minDist, abs(id1-id2));
            }
        } else {
            for (int i=0; i<len; ++i) {
                if (words[i] != word1) continue;
                    
                if (id1 >= 0) minDist = min(minDist, abs(id1-i));
                id1 = i;
            }
        }
        */
        
        return minDist;
    }
};
