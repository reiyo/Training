class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // my solution below works, but in fact it may cause overflow if n is very large
        // in that case, it may be better to use https://leetcode.com/problems/missing-number/discuss/69791
        
        int s = ((0 + nums.size()) * (nums.size()+1)) / 2; // 0 + 1 + 2 + ... + n
        s -= accumulate(nums.begin(), nums.end(), 0);
        
        return s;
    }
};
