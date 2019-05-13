class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m-1; i>=0; --i) {
            nums1[i+n] = nums1[i];
        }
        
        int i=0, j=0;
        int k=0;
        
        while (i<m && j<n) {
            if (nums1[i+n] <= nums2[j]) {
                nums1[k++] = nums1[i+n];
                ++i;
            } else {
                nums1[k++] = nums2[j];
                ++j;
            }
        }
        
        while (i<m) {
            nums1[k++] = nums1[i+n];
            ++i;            
        }
        
        while (j<n) {
            nums1[k++] = nums2[j];
            ++j;            
        }
        
        return;
    }
};
