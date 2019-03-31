class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> output;
        output.push_back(intervals[0]);
        int index = 0;
        
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i].start <= output[index].end) {
                output[index].end = max(output[index].end, intervals[i].end);
            } else {
                output.push_back(intervals[i]);
                ++ index;
            }
        }
        
        return output;
    }
};
