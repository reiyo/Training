class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int t = nums.size()-2;
        
        while (t >= 0 && nums[t] >= nums[t+1]) -- t;
        
        if (t < 0) {
            reverseSort(0, nums.size()-1, nums);
            return;
        }
        
        int min_id = t+1;
        
        for (int i=t+1; i<nums.size(); ++i) {
            if (nums[i] <= nums[t]) continue;
            if (nums[i] <= nums[min_id]) {
                min_id = i;
            }
        }
        
        swap(nums[t], nums[min_id]);
        reverseSort(t+1, nums.size()-1, nums);
    }
    
    void reverseSort(int start, int end, vector<int>& nums) {
        while (start < end) {
            swap(nums[start], nums[end]);
            ++ start;
            -- end;
        }
    }
};
