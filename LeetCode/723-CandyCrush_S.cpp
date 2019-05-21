class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        // implement https://leetcode.com/problems/candy-crush/discuss/113914/15-ms-Short-Java-Solution-Mark-crush-with-negative-value
        const int r = static_cast<int>(board.size());
        const int c = static_cast<int>(board[0].size());
        bool done = false;
        
        while (!done) {
            done = true;
            
            for (int i=0; i<r; ++i) {
                for (int j=0; j<c; ++j) {
                    if (board[i][j]==0) continue;
                    const int val = abs(board[i][j]);
                    
                    if (j+2<c && abs(board[i][j+1])==val && abs(board[i][j+2])==val) {
                        done = false;
                        int k = j;
                        while (k<c && abs(board[i][k])==val) board[i][k++] = -val;
                    }
                    
                    if (i+2<r && abs(board[i+1][j])==val && abs(board[i+2][j])==val) {
                        done = false;
                        int k = i;
                        while (k<r && abs(board[k][j])==val) board[k++][j] = -val;
                    } 
                }
            }
            
            if (!done) {
                for (int j=0; j<c; ++j) {
                    int bottom = r-1;
                    
                    for (int i=r-1; i>=0; --i) {
                        if (board[i][j] > 0) {
                            board[bottom--][j] = board[i][j];
                        }
                    }
                    
                    for (int i=bottom; i>=0; --i) board[i][j] = 0;
                }
            }
        }
        
        return board;
    }
};
