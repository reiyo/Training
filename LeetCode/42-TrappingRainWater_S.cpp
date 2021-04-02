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

// dynamic programming: O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = static_cast<int>(height.size());
        if (n <= 2) return 0;

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = height[0];
        for (int i=1; i<n; ++i) {
            left[i] = max(left[i-1], height[i]);
        }

        right[n-1] = height[n-1];
        for (int i=n-2; i>=0; --i) {
            right[i] = max(right[i+1], height[i]);
        }

        int res=0;
        for (int i=1; i<n-1; ++i) {
            int minh = min(left[i], right[i]);

            if (height[i] < minh) {
                res += (minh-height[i]);
            }
        }

        return res;
    }
};
