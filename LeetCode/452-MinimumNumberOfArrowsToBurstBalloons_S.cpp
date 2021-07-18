// refer to https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/93703
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Sorting allows us to find the last position (the last chance) for the first arrow, so as to burst the first balloon
// We will shoot at the ending position of the first balloon
// For the proof,
// If we shoot before the ending position for a specific interval and we can brust the same set of balloons, we can always move the position to the ending position
// Assume we can achieve a smaller number of arrows if we shoot before the ending position and leave some overlapped balloons
// The left balloons will be either convered by existing arrows or additional arrow(s)
// The total number of arrows is either the same or increased, and thus result contradicts our assumption
// That is, we cannot achieve a samller number of arrows if we shoot before the ending position and leave some overlapped balloons
// Remind that we can always move the position to the ending position if we can brust the same set of balloons
// Therefore, the greedy algorithm below can obtain the minimum number of arrows
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
