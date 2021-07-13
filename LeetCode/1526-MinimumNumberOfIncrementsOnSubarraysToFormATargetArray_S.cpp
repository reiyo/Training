// refer to https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/discuss/754623
//          https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/discuss/754674
// Time Complexity: O(n), where n is the input size
// Space Complexity: O(1)
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        
        for (int i=1; i<target.size(); ++i) {
            if (target[i] > target[i-1]) res += (target[i] - target[i-1]);
        }
        
        return res;
    }
};
