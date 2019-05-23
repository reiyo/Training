class Solution {
public:
    int trap(vector<int>& height) {
        // implement https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space
        if (height.empty()) return 0;
        
        int left = 0;
        int right = static_cast<int>(height.size())-1;
        int maxLeft = 0;
        int maxRight = 0;
        int sum = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > maxLeft) maxLeft = height[left];
                else sum += (maxLeft - height[left]);
                ++ left;
            }
            else {
                if (height[right] > maxRight) maxRight = height[right];
                else sum += (maxRight - height[right]);
                -- right;
            }
        }
        
        return sum;
    }
};
