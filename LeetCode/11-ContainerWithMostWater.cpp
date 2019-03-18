class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size()<2) return 0;
        int i = 0;
        int j = height.size()-1;
        int max_area = 0;
        
        while (i < j) {
            max_area = max(max_area, (j-i) * min(height[i], height[j]));
            
            if (height[i] == height[j]) {
                ++ i;
                -- j;
            } else if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }       
        }
        
        return max_area;
    }
};
