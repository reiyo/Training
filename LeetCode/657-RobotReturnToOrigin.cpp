class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0;
        int r = 0;
        
        for (char c: moves) {
            if (c == 'U') ++ u;
            else if (c == 'D') --u;
            else if (c == 'R') ++ r;
            else -- r;
        }
        
        return (u == 0) && (r == 0);
    }
};
