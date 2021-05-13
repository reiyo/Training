// refer to https://leetcode.com/problems/car-fleet/discuss/139850/C%2B%2BJavaPython-Straight-Forward
// time complexity: O(N log N), where N is the number of cars. Note that the map insertion takes logarithmic time in map size.
// space complexity: O(N)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> reqTimeMap;

        // map is sorted by its key, in an increasing order
        for (int i=0; i<position.size(); ++i) {
            int pos = position[i];

            // -pos helps to visit the one from the most closer to the target to the least
            // value of map is the time required to arrive the target
            reqTimeMap[-pos] = (1.0* (target-pos))/speed[i];            
        }

        int res = 0;
        double reqTime = 0;

        // for (auto p: reqTimeMap)
        for (pair<int, double> p: reqTimeMap) {
            if (p.second > reqTime) {
                ++ res;
                reqTime = p.second;
            }
        }

        return res;
    }
};
