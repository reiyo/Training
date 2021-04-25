class Node {
public:
    Node() {
        memset(children, 0, sizeof(children));
    }
    
    // optimization only
    bool isLeaf() {
        for (int i=0; i<26; ++i) {
            if (children[i]) return false;
        }
        return true;
    }

    string word;
    Node* children[26];
};

class Solution {
public:
    void buildTree(vector<string>& words) {
        root = new Node();

        for (string s: words) {
            Node* cur = root;

            for (char ch: s) {
                if (!cur->children[ch-'a']) cur->children[ch-'a'] = new Node();
                cur = cur->children[ch-'a'];
            }

            cur->word = s;
        }
    } 

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTree(words);

        int m = board.size();
        int n = board[0].size();
        set<string> res;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                traverse(board, m, n, i, j, root, res);            
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void traverse(vector<vector<char>>& board, int m, int n, int r, int c, Node* parent, set<string>& res) {
        // trick; the input is a parent, and move to the current node at this moment
        char ch = board[r][c];
        Node* cur = parent->children[ch-'a'];
        
        if (!cur) return;
        if (!cur->word.empty()) res.insert(cur->word);
        board[r][c] = '#';

        if (r-1 >= 0 && board[r-1][c] != '#') {
            traverse(board, m, n, r-1, c, cur, res);
        }

        if (r+1 < m && board[r+1][c] != '#') {
            traverse(board, m, n, r+1, c, cur, res);
        }  

        if (c-1 >= 0 && board[r][c-1] != '#') {
            traverse(board, m, n, r, c-1, cur, res);
        }

        if (c+1 < n && board[r][c+1] != '#') {
            traverse(board, m, n, r, c+1, cur, res);
        }
        
        board[r][c] = ch;
        
        // optimization only
        // once a leaf is reached, the associated word must have been inserted into the solution set
        // there is no need to traverse through the branch
        if (cur->isLeaf()) {
            delete cur;
            parent->children[ch-'a'] = 0;
        }
    }
private:
    Node* root;
};
