class Solution {
public:
    // My opinion: time complexity of using map for word frequency might be
    // O(n * k) because key comparison is O(k)
    // so I use TrieNode structure, but space complexity is still O(n * k)
    
    class TrieNode {
        public:
            TrieNode(): cnt(0) { 
                for (int i=0; i<256; ++i) next[i] = NULL;
            }
            int cnt;
            TrieNode* next[256];
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        TrieNode* root = new TrieNode();
        
        for (string w: words) {
            addToTree(w, root);
        }
        
        const int maxcnt = words.size();
        vector<vector<string>> buckets(maxcnt+1);
        dfs(root, "", buckets);
        vector<string> output;
        
        for (int i=maxcnt; i>0 && k>0; --i) {
            if (buckets[i].empty()) continue;
            
            for (int j=0; j<buckets[i].size() && k>0; ++j) {
                output.push_back(buckets[i][j]);
                -- k;
            }
        }
        
        return output;
    }
    
    void addToTree(const string& w, TrieNode* root) {
        for (char c: w) {
            if ((root->next)[c] == NULL) {
                (root->next)[c] = new TrieNode();
            }
            
            root = (root->next)[c];
        }
        
        ++ (root->cnt);
    }
    
    void dfs(TrieNode* root, string pre, vector<vector<string>>& buckets)
    {
        if (root->cnt > 0) {
            buckets[root->cnt].push_back(pre);
        }
        
        for (int i=0; i<256; ++i) {
            if ((root->next)[i] != NULL) {
                const char c = (char) i;
                dfs((root->next)[i], pre+string(1, c), buckets);
            }
        }
    }
};
