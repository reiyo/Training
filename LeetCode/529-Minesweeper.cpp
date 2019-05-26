class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        
        if (board[r][c]=='M') {
            board[r][c] = 'X';
            return board;
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        board[r][c] = 'B'; // avoid to be added to queue again!! save the "visited" table
        
        while (!q.empty()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();          
            int cnt = 0;
            
            addMine(board, r-1, c-1, cnt);
            addMine(board, r-1, c,   cnt);
            addMine(board, r-1, c+1, cnt);
            addMine(board, r,   c-1, cnt);
            addMine(board, r,   c+1, cnt);
            addMine(board, r+1, c-1, cnt);
            addMine(board, r+1, c,   cnt);
            addMine(board, r+1, c+1, cnt);
            
            if (cnt > 0) {
                board[r][c] = cnt + '0';
            }
            else {
                // board[r][c] = 'B'; // not needed if 'B' is used as the "visited" table 
                traverse(board, r-1, c-1, q);
                traverse(board, r-1, c,   q);
                traverse(board, r-1, c+1, q);
                traverse(board, r,   c-1, q);
                traverse(board, r,   c+1, q);
                traverse(board, r+1, c-1, q);
                traverse(board, r+1, c,   q);
                traverse(board, r+1, c+1, q);
            }
        }
        
        return board;
    }
    
    void addMine(const vector<vector<char>>& board, int r, int c, int& cnt) {           
        const int m = board.size();
        const int n = board[0].size();         
        
        if (!isFeasible(m, n, r, c)) return;
        
        if (board[r][c] == 'M' || board[r][c] == 'X') ++ cnt;
    }
    
    void traverse(vector<vector<char>>& board, int r, int c, queue<pair<int, int>>& q) {
        const int m = board.size();
        const int n = board[0].size();
        
        if (!isFeasible(m, n, r, c)) return;
        
        if (board[r][c] == 'E') {
            q.push(make_pair(r, c));
            board[r][c] = 'B'; // avoid to be added to queue again!! save the "visited" table
        }
    }
    
    bool isFeasible(int m, int n, int r, int c) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
};
