class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> output(n, 1);
        int fromBegin = 1;
        int fromEnd = 1;
        
        for (int i=0; i<n; ++i) {
            output[i] *= fromBegin;
            fromBegin *= nums[i];
        }
        
        for (int i=n-1; i>=0; --i) {
            output[i] *= fromEnd;
            fromEnd *= nums[i];
        }
        
        return output;
    }
};
