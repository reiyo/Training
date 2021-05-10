// time complexity: O(k)
// space complexity: O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;

        if (k >= n) {
            for (int p: cardPoints) sum += p;
            return sum;  
        }

        // pick k cards from the left side
        for (int i=0; i<k; ++i) sum += cardPoints[i];
        int maxSum = sum;
        
        // remove one from left, and add one from right
        for (int i=0; i<k; ++i) {
            sum -= cardPoints[k-1-i];
            sum += cardPoints[n-1-i];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
