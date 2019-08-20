class Solution(object):
    # refer to https://leetcode.com/problems/prison-cells-after-n-days/discuss/205684
    # refer to https://leetcode.com/problems/prison-cells-after-n-days/discuss/266854
    def getNext(self, cells):
        temp = 8 * [0]
        
        for i in range(1, 7):
            if cells[i-1] == cells[i+1]:
                temp[i] = 1
                
        return temp
    
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        mydict = {}
        has_loop = False
        symbol = ''
        curDay = 1
        
        # cannot use "for curDay in range(1, N+1)" to prevent from a large list
        while curDay <= N:
            cells = self.getNext(cells)
            symbol = str(cells)
            
            if str(cells) in mydict:
                has_loop = True
                break
                
            mydict[symbol] = curDay
            curDay += 1
        
        if has_loop:
            lastDay = mydict[symbol]
            loop_len = curDay - lastDay
            N = (N - curDay) % loop_len
            
            for i in range(N):
                cells = self.getNext(cells)
        
        return cells
