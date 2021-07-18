// refer to https://leetcode.com/problems/asteroid-collision/discuss/109694
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // trick: use a vector to simulate a stack
        // if a stack is used, we still need a vector, and a reverse() may be needed for data from the stack to the vector
        vector<int> s; // trick: use a vector to simulate a stack

        for (int i=0; i<asteroids.size(); ++i) {
            if (asteroids[i] > 0) s.push_back(asteroids[i]);
            else {
                // trick: not to use abs(), just -asteroids[i]
                while (!s.empty() && s.back()>0 && s.back()<-asteroids[i]) s.pop_back();
                
                if (s.empty() || s.back()<0) s.push_back(asteroids[i]);
                else if (s.back()==-asteroids[i]) s.pop_back();
            }
        }

        return s;
    }
};
