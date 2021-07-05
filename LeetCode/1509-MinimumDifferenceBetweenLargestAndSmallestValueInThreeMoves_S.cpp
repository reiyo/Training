// refer to ezpzm9's solution in discussion of https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/730567/JavaC%2B%2BPython-Straight-Forward
// Time Complexity: O(n log k), where n is the size of nums, and k is 3 (3 moves)
// Space Complexity: O(k)
// The main idea is to find the smallest k values and the largest k values, and tries to find minimum considering the cases: 
// Case I: decrease the largest k values to the (k+1)-th largest value, 
// Case II: increase the smallest 1 value to the 2nd smallest value and decrease the largest (k-1) to the k-th largest value, 
// Case III: increase the smallest 2 values to the 3nd smallest value and decrease the largest (k-2) to the (k-1) largest value, etc. 
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;

        // use heaps to find the smallest 4 elements and the largest 4 elements
        // we find 4 rather than 3, so as to consider the cases that 3 elements are changed
        priority_queue<int> maxQ; // max-heap
        priority_queue<int, vector<int>, greater<int>> minQ;

        // trick: (1) size is limited, (2) max heap keeps the smallest ones
        for (int n: nums) {
            maxQ.push(n);
            if (maxQ.size() >= 5) maxQ.pop(); // the left ones are the smallest 4 values
            minQ.push(n);
            if (minQ.size() >= 5) minQ.pop(); // the left ones are the largest 4 values
        }

        vector<int> mins, maxs;

        while(!maxQ.empty()) {
            mins.push_back(maxQ.top());
            maxQ.pop();
        }

        // mins and maxs will be in an ascending order
        reverse(mins.begin(), mins.end());     
        
        while(!minQ.empty()) {
            maxs.push_back(minQ.top());
            minQ.pop();
        }

        int res = maxs[0] - mins[0];
        
        // change the i smallest values, and the (3-i) largest values
        for (int i=1; i<=3; ++i) res = min(res, maxs[i] - mins[i]);

        return res;  
    }
};
