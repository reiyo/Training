// refer to https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/discuss/831588
// note that it is of no use to delete any non-repeating letter

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if (s.length() <= 1) return 0;
        int res = 0;

        int max_cost = cost[0];
        int sum_cost = max_cost;
        
        for (int i=1; i<s.length(); ++i) {
            if (s[i] != s[i-1]) {
                // non-repeating letters results in 0 cost
                res += sum_cost - max_cost;
                max_cost = cost[i];
                sum_cost = max_cost;
            }
            else {
                max_cost = max(max_cost, cost[i]);
                sum_cost += cost[i];
            }
        }
        // consider the case if the last letter is repeated
        res += sum_cost - max_cost;
        return res;
    }
};
