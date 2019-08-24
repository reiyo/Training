# refer to https://leetcode.com/problems/partition-labels/discuss/298474
class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        endLst = [0] * 26;
        
        for i, c in enumerate(S):
            endLst[ord(c)-ord('a')] = i
        
        output = []
        left, right = 0, 0
        
        for i, c in enumerate(S):
            right = max(right, endLst[ord(c)-ord('a')])
            
            if i == right:
                output.append(right-left+1)
                left = i+1
        
        return output
