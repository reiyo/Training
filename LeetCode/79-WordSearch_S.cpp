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
