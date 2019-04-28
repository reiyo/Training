class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1;
        int pos2 = -1;
        int minDist = static_cast<int>(words.size());
        
        for (int i=0; i<static_cast<int>(words.size()); ++i) {
            if (words[i] == word1) pos1 = i;
            else if (words[i] == word2) pos2 = i;
                
            if (pos1 >=0 && pos2 >= 0) minDist = min(minDist, abs(pos1-pos2));
        }
        
        return minDist;
    }
};
