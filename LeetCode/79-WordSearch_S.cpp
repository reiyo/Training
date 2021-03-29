class Solution {
public:
    bool backtrack(vector<vector<char>>& board, int m, int n, int i, int j, string& w, int k) {
        // if we set "if (k <= w.length()) return true", we have to consider something like [['a']]
        if (board[i][j] != w[k]) return false;
        if (k+1 >= w.length()) return true;
        
        char ch = board[i][j];
        board[i][j] = '0';
        
        // not to go further if res is true
        bool res = false;
        if (i > 0) res = backtrack(board, m, n, i-1, j, w, k+1);
        if (!res && i+1 < m) res = backtrack(board, m, n, i+1, j, w, k+1);
        if (!res && j > 0) res = backtrack(board, m, n, i, j-1, w, k+1);
        if (!res && j+1 < n) res  = backtrack(board, m, n, i, j+1, w, k+1);

        // remember to revert
        board[i][j] = ch;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (backtrack(board, m, n, i, j, word, 0)) return true;
            }
        }  
        
        return false;      
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size() || !word.length() || !board[0].size()) return false;
        
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                set<int> used;
                if (check(board, used, i, j, word, 0)) return true;
            }
        }
        
        return false;
    }
    
    bool check(const vector<vector<char>>& board, set<int> &used, int i, int j, string &word, int k)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        const int index = i*board[0].size()+j;
        
        if (used.count(index)) return false;
        if (board[i][j] != word[k]) return false;
        used.insert(index);
        if (k+1 >= word.length()) return true;
        
        bool flag = check(board, used, i-1, j, word, k+1) || check(board, used, i+1, j, word, k+1) ||
                    check(board, used, i, j-1, word, k+1) || check(board, used, i, j+1, word, k+1);
        
        if (flag) return true;
        used.erase(index);
        return false;
    }
};
