// refer to https://leetcode.com/problems/maximum-number-of-visible-points/discuss/877822/Python-clean-sliding-window-solution-with-explanation
// time complexity: O(n log n), where n is the number of points
// space complexity: O(n)
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> pnt_angles;

        pnt_angles.reserve(points.size() * 2);
        int extra = 0;

        for (auto p: points) {
            // extract the points at the location
            if (p[0] == location[0] && p[1] == location[1]) {
                ++ extra;
                continue;
            }

            // trick
            // use atan2 [-pi, +pi] rather than atan [-pi/2, +pi/2]
            double radians = atan2(p[1]-location[1], p[0]-location[0]);
            pnt_angles.push_back(radians * 180/M_PI);
        }

        // so as to enable sliding windows
        sort(pnt_angles.begin(), pnt_angles.end());

        // trick is to add same points + 360 to handle the cyclic condition
        int cnt = pnt_angles.size();
        for (int i=0; i<cnt; ++i) pnt_angles.push_back(pnt_angles[i]+360);
        
        int start = 0;
        int max_inc = 0;
        
        /* 
           use "cnt" as the bound of the for loops will fail in the case:
           [[0,0],[0,2]]
           90
           [1,1]
           pnt_angles: -135, 135, 225, 495
        */
        for (int end=0; end<pnt_angles.size(); ++end) {
            while (pnt_angles[end]-pnt_angles[start] > angle) ++ start;
            max_inc = max(max_inc, end-start+1);
        }

        return max_inc + extra;        
    }
};
