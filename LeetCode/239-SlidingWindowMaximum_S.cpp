class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return vector<int>();
        deque<int> dq;
        vector<int> output;
        
        for (int i=0; i<static_cast<int>(nums.size()); ++i) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            /* while loop is also fine
            while (!dq.empty() && dq.front() < (i-k+1)) {
                dq.pop_front();
            }
            */
            
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            if (i>=k-1) output.push_back(nums[dq.front()]);
        }
        
        return output;
    }
};
