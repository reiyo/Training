class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // state machine has three states
        int reset = 0;
        int held = INT_MIN; // otherwise, below max() will be wrong
        int sold = 0;

        for (int p: prices) {
            int pre_reset = reset;
            int pre_held = held;         
            reset = max(reset, sold); // profit of no stock after this iteration
            held = max(held, pre_reset-p); // profit of holding a stock
            sold = pre_held+p; // profit of selling the stock
        }

        return max(reset, sold);
    }
};
