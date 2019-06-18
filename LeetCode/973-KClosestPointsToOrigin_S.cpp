class Solution {
public:
    // refer to https://leetcode.com/problems/k-closest-points-to-origin/discuss/220235
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {     
        vector<vector<int>> output(K, vector<int>());
        int l = 0;
        int r = static_cast<int>(points.size())-1;
        K -= 1; // because index starts from 0
        
        while (l < r) {
            const int mid = partition(l, r, points);
  
            if (mid == K)     break;
            else if (mid < K) l = mid + 1;
            else              r = mid - 1;
        }
        
        copy_n (points.begin(), K+1, output.begin());
        return output;
    }
    
    int partition(int l, int r, vector<vector<int>>& points) {
        vector<int> pivot = points[l];
        
        // if "=" is not set, {{0, 1}, {1, 0}} may result in an infinite loop
        while (l < r) {
            while (l < r && compare(pivot, points[r]) <= 0) -- r;
            points[l] = points[r];
            
            while (l < r && compare(pivot, points[l]) >= 0) ++ l;
            points[r] = points[l];
        }
        
        points[l] = pivot;
        return l;
    }
    
    int compare(vector<int>& p1, vector<int>& p2) {
        return (p1[0]*p1[0] + p1[1]*p1[1]) - (p2[0]*p2[0] + p2[1]*p2[1]);
    }
};
