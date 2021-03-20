class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=0;
        int cnt=0;

        for (int &n: nums) {
            if (0 == cnt) {
                val = n;
                cnt = 1;
            }
            else {
                if (val == n) ++ cnt;
                else -- cnt;
            }
        }

        return val;
    }
};
