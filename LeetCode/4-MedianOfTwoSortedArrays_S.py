class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if (len(nums1)>len(nums2)):
            nums1, nums2 = nums2, nums1
        if (len(nums2)<=0):
            raise ValueError
        
        m, n = len(nums1), len(nums2)
        imin, imax = 0, m
        
        while (imin <= imax):
            i = (imin+imax)//2
            j = (m+n+1)//2 - i
            
            if i-1>=0 and j<n and nums1[i-1] > nums2[j]:
                # in fact, i>0 implies j<n, so j<n can be removed
                imax = i-1
            elif j-1>=0 and i<m and nums2[j-1] > nums1[i]:
                # in fact, i<m implies j>0, so j-1>=0 can be removed
                imin = i+1
            else:
                if (i<=0):
                    maxLeft = nums2[j-1]
                elif (j<=0):
                    maxLeft = nums1[i-1]
                else:
                    maxLeft = max(nums1[i-1], nums2[j-1])
                
                if (m+n)%2:
                    return maxLeft+0.0
                
                if (i>=m):
                    minRight = nums2[j]
                elif (j>=n):
                    minRight = nums1[i]
                else:
                    minRight = min(nums1[i], nums2[j])
                    
                return (maxLeft + minRight)/2.0
                            
        return 0.0
