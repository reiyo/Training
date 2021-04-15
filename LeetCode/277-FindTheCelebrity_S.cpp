// time complexity: O(n)
// space complexity: O(1)
class Solution {
public:
    int findCelebrity(int n) {
        int cand = 0;
        
        // for each call to knows(), we konw that exactly 1 of the people is not a celebrity
        // knows(a, b) is true shows a is not candidate, and b is candidate
        // knows(a, b) is false shows b is not candidate, and a is candidate
        for (int i=1; i<n; ++i) {
            if (knows(cand, i)) cand = i;
        }
        
        // check if the candidate is the celebrity or not
        for (int i=0; i<n; ++i) {
            if (cand == i) continue;
            if (knows(cand, i) || !knows(i, cand)) return -1;
        }
        
        return cand;
    }
};
