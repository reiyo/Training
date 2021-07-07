// refer to https://leetcode.com/problems/car-fleet-ii/discuss/1085987
// refer to https://leetcode.com/problems/car-fleet-ii/discuss/1085844 (workcool's observation as follows)
// key idea: "The collision time for a car will only be affected by the cars on its right. Again among 
//            all the cars on current car's right, there are certain cars that won't affect current car's
//            collision time. Namely, if the car has a higher speed than the current car, or, if the car's 
//            collision time is earlier than the current car's collision time with this car, then such
//            cars won't affect current car's collision time, and can be ignored. The mono stack has only 
//            kept those cars that can possibly affect the current car." by workcool
// Time Complexity: O(n), where n is the number of cars. Note that the while loop runs at most n times.
// Space Complexity: O(n)
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1.0);
        stack<int> car_stack;

        for (int i=n-1; i>=0; --i) {
            int pi = cars[i][0];
            int si = cars[i][1];

            while (!car_stack.empty()) {
                int j = car_stack.top();
                int pj = cars[j][0];
                int sj = cars[j][1];                
                
                // no need to consider the previous car if
                // case 1: cannot catch up the previous car
                // case 2: the previous car had collided with the next car, before it was catched up
                if (sj >= si || (res[j]>=0 && (pj-pi)*1.0/(si-sj) >= res[j])) car_stack.pop();
                else break;
            }

            if (!car_stack.empty()) {
                int j = car_stack.top();
                int pj = cars[j][0];
                int sj = cars[j][1];
                res[i] = (pj-pi)*1.0/(si-sj);                
            }

            car_stack.push(i);
        }

        return res;
    }
};
