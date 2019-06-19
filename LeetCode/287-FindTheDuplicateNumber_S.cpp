class Solution {
public:
    // refer to https://leetcode.com/problems/find-the-duplicate-number/discuss/72846
    // and its proof in the post
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return -1;
        
        // note that nums[0] is the start point because integer is between 1 and n
        // if it can be 0, nums[0]=0 will make this algorithm fails; but this is not the case
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        int new_slow = nums[0]; // goes from the start point
        slow = nums[slow];      // goes from the meeting point
        
        while (new_slow != slow) {
            new_slow = nums[new_slow];
            slow = nums[slow];
        }
        
        // slow is the entry point of the circle
        return slow;
    }
};
