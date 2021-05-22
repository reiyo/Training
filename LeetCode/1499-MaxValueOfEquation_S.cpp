// time complexity: O(n)
// space complexity: O(n)
// refer to https://leetcode.com/problems/max-value-of-equation/discuss/709231
// yi + yj + |xi - xj| = yi + yj + (xj - xi) = (yi - xi) + (yj + xj)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int res = INT_MIN;

        for (int i=0; i<points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];

            while (!dq.empty() && (x - points[dq.front()][0]) > k) {
                dq.pop_front();
            } 

            if (!dq.empty()) {
                res = max(res, points[dq.front()][1]-points[dq.front()][0]+x+y);
            }

            int diff = y - x;

            // ensure the queue to be monotonically decreasing 
            while (!dq.empty() && (points[dq.back()][1] - points[dq.back()][0]) < diff) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return res;
    }
};
