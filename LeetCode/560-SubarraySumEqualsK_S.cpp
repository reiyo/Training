class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count; // keep (nums[0]+...+nums[j]), j is any previous index
        int acc_sum = 0;
        int total = 0;
        
        for (size_t i=0; i<nums.size(); ++i) {
            acc_sum += nums[i];
            
            // even if we have ++ total, we still need ++ count[acc_sum]
            // for example, nums={0, 0}, k=0, result should be 3, not 2
            // this can be replaced by the setting of "count[0] = 1" before the loop
            if (acc_sum == k) ++ total;
            
            // (nums[0]+ ... + nums[i]) - (nums[0]+ ... + nums[j]) == k, for all j < i 
            total += count[acc_sum-k];
            ++ count[acc_sum];
        }
        
        return total;
    }
};
