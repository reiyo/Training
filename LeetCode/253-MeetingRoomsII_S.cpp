class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        vector<int> starts(intervals.size(), 0);
        vector<int> ends(intervals.size(), 0);
        
        for (size_t i=0; i<intervals.size(); ++i) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int room_cnt = 0;
        int end_index = 0;
        
        for (size_t i=0; i<starts.size(); ++i) {
            ++ room_cnt; // a new meeting requires a room
            
            // if a meeting ends at the same time or even earlier 
            if (starts[i] >= ends[end_index]) {
                ++ end_index;
                -- room_cnt;  // no need to add a new room
            }
        }
        
        // btw, if the earliest end time > all start times, it is impossible to reuse any room 
        
        return room_cnt;
    }
};
