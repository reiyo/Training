class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i=0; i<static_cast<int>(words.size()); ++i) {
            dict[words[i]].push_back(i);
        }
        
        wordCnt = static_cast<int>(words.size());
    }
    
    int shortest(string word1, string word2) {
        // given that word1 and word2 are both in the list
        const vector<int>& vec1 = dict[word1];
        const vector<int>& vec2 = dict[word2];
        
        int minDist = wordCnt;
        int i=0, j=0;
        
        while (i < static_cast<int>(vec1.size()) && j < static_cast<int>(vec2.size())) {
            minDist = min(minDist, abs(vec1[i] - vec2[j]));
            
            if (vec1[i] < vec2[j]) {
                ++ i;
            } else {
                ++ j;
            }
        }

        return minDist;
    }
private:
    unordered_map<string, vector<int>> dict;
    int wordCnt;
};
