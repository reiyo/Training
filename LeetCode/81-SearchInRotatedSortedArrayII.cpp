class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while (left <= right) {
            int mid = (left + right)/2;
            
            if (nums[mid] == target) return true;
            
            int index = mid + 1;
            while (index <= right && nums[mid] == nums[index]) ++ index;
            
            if (index-1 >= right) {
                right = mid - 1;
                continue;
            }

            index = mid - 1;
            while (index >= left && nums[mid] == nums[index]) -- index;
            
            if (index+1 <= left) {
                left = mid + 1;
                continue;
            }            
            
            if (nums[left] <= nums[mid]) {
                if (nums[mid] > target && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};
