# refer to https://leetcode.com/problems/reorder-log-files/discuss/192144 and
# https://leetcode.com/problems/reorder-log-files/discuss/198197
class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        letter_logs = []
        digit_logs = []
        
        for log in logs:
            if log[log.find(" ")+1].isdigit():
                digit_logs.append(log)
            else:
                letter_logs.append(log)
        
        # for tuple, compare the first element, then compare the second element
        # thus, compare log[log.find(" ")+1:], then compare log[:log.find(" ")]        
        letter_logs.sort(key=lambda log: (log[log.find(" ")+1:], log[:log.find(" ")]))
        
        return letter_logs + digit_logs

