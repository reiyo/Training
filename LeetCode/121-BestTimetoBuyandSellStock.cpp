class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin = prices[0];
        int maxpro = 0;

        for (int p: prices) {
            if (p<curmin) curmin = p;
            else if (p - curmin > maxpro) maxpro = p - curmin;            
        }

        return maxpro;
    }
};
