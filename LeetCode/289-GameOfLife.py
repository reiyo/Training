# refer to the discussions
class Solution(object):
    def decideStatus(self, board, i, j, m, n):
        direct = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        live_cnt = 0
        
        for d in direct:
            x = i + d[0]
            y = j + d[1]
            
            if (x >= 0 and x <m and y>=0 and y<n):
                if (board[x][y] & 1):
                    live_cnt += 1
        
        if (board[i][j] == 1):
            if (live_cnt == 2 or live_cnt == 3):
                board[i][j] = 3 # 01 -> 11 (live to live)
            #else:
            #    board[i][j] = 1 # 01 -> 01 (live to dead)
        else:
            if (live_cnt == 3):
                board[i][j] = 2 # 00 -> 10 (dead to live)
            #else:
            #    board[i][j] = 0 # 00 -> 00 (dead to dead)
            
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        ## 0 is dead, 1 is live; bit 0 is current, bit 1 is next
        # 00: dead to dead (default)
        # 01: live to dead (default)
        # 10: dead to live
        # 11: live to dead
        
        if (not board or len(board[0]) <= 0):
            return
        
        m, n = len(board), len(board[0])
        
        for i in range(m):
            for j in range(n):
                self.decideStatus(board, i, j, m, n)
                
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
