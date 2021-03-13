class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int len = static_cast<int>(nums.size());
        int res = len+1;
        int l=0;
        int sum=0;

        for (int r=0; r<len; ++r) {
            sum += nums[r];

            while (sum >= target) {
                res = min(res, r-l+1);
                sum -= nums[l];
                ++ l;
            }
        }

        return (res==len+1)? 0 : res;
    }
};
