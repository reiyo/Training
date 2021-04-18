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

// almost the same, but using sort
class TrieNode {
public:
    TrieNode(): cnt(0) {
    }

    unordered_map<char, TrieNode*> children;
    string sent;
    int cnt;
};

bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
    if (p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
}

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();

        for (int i=0; i<sentences.size(); ++i) {
            tree_insert(sentences[i], times[i]);
        }
        
        temp = root;
    }

    void tree_insert(string& str, int cnt) {
        TrieNode* cur = root;

        for (char ch: str) {
            if (cur->children.find(ch) == cur->children.end()) cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }

        cur->sent = str;
        cur->cnt = cnt;
    }

    void tree_collect(TrieNode* cur, vector<pair<string, int> > &out) {
        if (!cur->sent.empty()) {
            out.push_back(make_pair(cur->sent, cur->cnt));
        }

        for (auto it=cur->children.begin(); it!=cur->children.end(); ++it) tree_collect(it->second, out); 
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            if (temp) {
                if (temp->sent.empty()) temp->sent = prefix; // forgot to add this caused a bug
                ++ temp->cnt;
            }
            else tree_insert(prefix, 1);

            temp = root;
            prefix = "";
            return vector<string>();
        }

        prefix += c;
        if (temp == NULL) return vector<string>();

        if (temp->children.find(c) != temp->children.end()) {
            temp = temp->children[c];
        }
        else {
            temp = NULL;        
            return vector<string>();
        }

        vector<pair<string, int> > candidates;
        tree_collect(temp, candidates);
        sort(candidates.begin(), candidates.end(), cmp);

        vector<string> res;
        for (int i=0; i<3 && i<candidates.size(); ++i) {
            res.push_back(candidates[i].first);
        }   
        return res;
    }
private:
    TrieNode* root;
    TrieNode* temp;
    string prefix;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
