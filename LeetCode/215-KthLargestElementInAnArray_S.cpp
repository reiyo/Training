class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // make the largest to be with index 0
        -- k;
        
        int left = 0, right = nums.size()-1;
        
        while (left <= right) {
            int index = partition(nums, left, right);
            if (index == k) return nums[index];
            else if (index < k) left=index+1;
            else right=index-1;
        }
        
        return -1;
    }

    // return the position of the pivot for large to small
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i=left-1;

        for (int j=left; j<right; ++j) {
            if (nums[j] >= pivot) {
                ++ i;
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[i+1], nums[right]);
        return (i+1);
    }
};
