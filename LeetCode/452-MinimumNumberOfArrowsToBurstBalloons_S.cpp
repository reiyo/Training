// refer to https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/93703
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Sorting allows us to find the last position (the last chance) for the first arrow, so as to burst the first balloon
// We will shoot at the ending position of the first balloon
// if we shoot before the ending position and we can brust the same set of ballons, we can move the position to the ending position
// if we shoot before the ending position and leave some overlapped balloons, we still need to burst the overlapped balloons later 
class Solution {
public:
    static bool cmp(const vector<int>& p1, const vector<int>& p2) {
        return p1[1] < p2[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        
        int end=points[0][1];
        int cnt=1;
        
        for (int i=1; i<points.size(); ++i) {
            if (points[i][0] > end) {
                end = points[i][1];
                ++ cnt;
            }
        }
        
        return cnt;
    }
};
