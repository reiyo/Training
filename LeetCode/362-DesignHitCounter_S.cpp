class HitCounter {
public:
    // initially, I thought that dequeue may work well, but then I found xuyirui's solution
    // is better (https://leetcode.com/problems/design-hit-counter/discuss/83483)
    // so below are my implementation of xuyirui's solution
    
    int hit_bucket[300];
    int time_bucket[300];
    
    /** Initialize your data structure here. */
    HitCounter() {
        // hit_slot[i] is associated with time_slot[i]
        memset(hit_bucket, 0, 300 * sizeof(int));
        memset(time_bucket, 0, 300 * sizeof(int));     
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        const int id = timestamp % 300;
        
        if (time_bucket[id] == timestamp) {
            ++ hit_bucket[id];
        } else {
            // timestamp - time_bucket[id] > 300; e.g., 301 and 1 are assigned to be the same bucket,
            // and we can remove 1
            time_bucket[id] = timestamp;
            hit_bucket[id] = 1;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int sum = 0;
        
        for (int i=0; i<300; ++i) {
            if (timestamp - time_bucket[i] < 300) {
                sum += hit_bucket[i]; 
            }
        }
        
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
