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
                // we don't know what nums[right] has before the swap, 
                // so we leave pivot for the next iteration
                swap(nums[right--], nums[pivot]);
            }
        }
        
        return;
    }
};

// almost the same idea
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int r=0;
        int b=nums.size()-1;
        int i=0;

        while (i <= b) {
            if (nums[i] == 0) {
                swap(nums[r++], nums[i]);
                if (nums[i] == 2) swap(nums[b--], nums[i]);
            }
            else if (nums[i] == 2) {
                swap(nums[b--], nums[i]);
                if (nums[i] == 0) swap(nums[r++], nums[i]);
            }
            // the if-statement is essential, e.g., for [2, 1, 2]
            if (nums[i] != 2) ++i;
        }
    }
};
