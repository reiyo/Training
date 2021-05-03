// time complexity: O(n^2), where n is the number of inputs
// space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] stores the max length of LIS up to nums[i]
        vector<int> dp(nums.size(), 1);

        for (int i=1; i<nums.size(); ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// time complexity: O(n log n), where n is the number of inputs
// space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tail[i] stores the LIS with the smallest end element among LIS's with length i+1
        vector<int> tail(nums.size(), 0);
        int size = 0;

        for (int n: nums) {
            int left = 0;
            int right = size; // tail[size] has not been defined  

            // not a typical binary search! 
            // it is to find the lower bound to [left, right)
            // find index so that tails[index-1] < n <= tails[index]
            while (left < right) {
                int mid = left + (right-left)/2;

                if (tail[mid] < n) left = mid + 1;
                else right = mid; // not mid-1
            }

            tail[left] = n;
            if (left == size) ++ size;
        }

        return size;
    }
};
