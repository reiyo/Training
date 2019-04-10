class Solution {
public:
    void sortColors(vector<int>& nums) {

        int left = 0;
        int right = nums.size()-1;
        int pivot = 0;
        
        while (pivot <= right) {
            if (nums[pivot] == 0) {
                swap(nums[left++], nums[pivot++]);
            } else if (nums[pivot] == 1) {
                ++ pivot;
            } else {
                swap(nums[right--], nums[pivot]);
            }
        }
        
        return;
    }
};
