class AutocompleteSystem {
public:
    class TrieNode {
        public:
            TrieNode(): str(""), cnt(0) {}
            unordered_map<char, TrieNode*> child;
            string str; // a sentence, say, words
            int cnt;
    };
    
    void insert(TrieNode* root, string& str, int times) {
        TrieNode* curr = root;
        
        for (char c: str) {
            if ((curr->child).find(c) == (curr->child).end())
                (curr->child)[c] = new TrieNode();
            
            curr = (curr->child)[c];
        }
        
        curr->str = str;
        curr->cnt += times; 
    }
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        _root = new TrieNode();
        
        for (size_t i=0; i<sentences.size(); ++i) 
            insert(_root, sentences[i], times[i]);
    
        _curr = _root;
        _prefix = "";
    }
    
    struct comp {
        bool operator()(pair<string, int> a, pair<string, int>b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        }
    };
    
    void dfs(TrieNode* curr) {
        if (curr->cnt > 0) 
            _q.push(make_pair(curr->str, curr->cnt));
        
        for (auto it=curr->child.begin(); it!=curr->child.end(); ++it)
            dfs((*it).second);
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(_root, _prefix, 1);
            _curr = _root;
            _prefix = "";
            return vector<string>();
        }
        
        _prefix += c;
        
        if (_curr && (_curr->child).find(c) != (_curr->child).end())
            _curr = _curr->child[c];
        else {
            _curr = NULL; // mark that it is impossible to get relatives
            return vector<string>();
        }
        
        _q = priority_queue<pair<string, int>, vector<pair<string, int> >, comp>(); 
        dfs(_curr);
        vector<string> out;
        
        while (!_q.empty() && out.size() < 3) {
            out.push_back(_q.top().first);
            _q.pop();
        }
        
        return out;
    }
private:
    TrieNode* _root;
    TrieNode* _curr;
    string _prefix;
    priority_queue<pair<string, int>, vector<pair<string, int> >, comp> _q;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
