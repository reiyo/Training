class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val) nums[i-length] = nums[i];
            else ++ length;
        }
        
        return nums.size() - length;
    }
};
