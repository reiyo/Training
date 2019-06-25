def solution(N):
    # write your code in Python 3.6
    right = -1
    cur = 0
    maxlen = 0
    
    while (N):
        if (N & 1):
            if (right >= 0):
                maxlen = max(cur - right - 1, maxlen)
            right = cur
        N >>= 1
        cur += 1
        
    return maxlen
