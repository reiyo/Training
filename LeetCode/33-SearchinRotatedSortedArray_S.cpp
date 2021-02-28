class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return -1;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right)/2;
            
            if (nums[mid] == target) return mid;
            
            if (nums[mid] >= nums[left]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                }
                else left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }
        
        return -1;
    }
};

// same idea: see the pivot is right or left with respect to the mid 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int last = nums.size()-1;
        int left = 0, right = last;
        
        while (left <= right) {
            int mid = (left+right)/2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) {
                if (nums[last] > nums[mid]) {
                    if (nums[last]<target) right = mid-1;
                    else left = mid+1;
                }
                else left = mid+1;
            }
            else {
                if (nums[last] > nums[mid]) right = mid-1;
                else {
                    if (nums[last]>=target) left = mid+1;
                    else right = mid-1;
                }
            }
        }
        return -1;
    }
};
