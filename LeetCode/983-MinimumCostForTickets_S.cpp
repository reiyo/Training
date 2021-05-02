// time complexity: O(W), where W is 365 is the max numbered day of the train plan for this problem
// space complexity: O(W)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> day_set(days.begin(), days.end());
        vector<int> dp(366, 0); // trick: dp[0] = 0

        for (int i=1; i<366; ++i) {
            // trick: dp[i] = dp[i-1] if no travel on current day
            if (day_set.find(i) == day_set.end()) dp[i] = dp[i-1];
            else {
                // (dp[i-7] + costs[1]) is to buy a 7-day pass to cover days
                // i-6, i-5, i-4, i-3, i-2, i-1, and i
                // suppose the last travel day is 5; we have dp[max(0, i-7)] = dp[0], so as to consider the case of a 7-day pass
                dp[i] = min(dp[i-1]+costs[0], min(dp[max(0, i-7)]+costs[1], dp[max(0, i-30)]+costs[2]));
            }
        }

        return dp[365];
    }
};
