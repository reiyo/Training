class Solution {
public:
    bool canJump(vector<int>& nums) {     
        for (int i=0; i+1<nums.size(); ++i) {
            if (nums[i] == 0) return false;
            int len = nums[i]-1;
            
            for (int j=i+1; j+1<nums.size() && len>0; ++j, --len) {
                if (len > nums[j]) nums[j] = len;
            }
        }
        
        return true;
    }
};
