class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxgain = 0;
        int buy = 0;
        
        for (int i=0; i<prices.size(); ++i) {
            if (prices[i] < prices[buy]) buy = i;
            else {
                int diff = prices[i] - prices[buy];
                if (diff > maxgain) maxgain = diff;
            }
        }
        return maxgain;
    }
};
