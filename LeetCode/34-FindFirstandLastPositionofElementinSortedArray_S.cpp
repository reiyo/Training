class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return vector<int>(2, -1);
        if (nums.size()==1) {
            if (nums[0] == target) return vector<int>(2, 0);
            else return vector<int>(2, -1);
        }

        int low = lowerbound(nums, target);
        
        if (low >= nums.size() || nums[low]!=target) return vector<int>(2, -1);
        int high = lowerbound(nums, target+1);
        return {low, high-1};
    }
    
    int lowerbound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while (left <= right) {
            int m = (left+right)/2;
            
            if (nums[m] < target)  left = m + 1;
            else right = m-1;

        }
        
        return left;
    }
};
