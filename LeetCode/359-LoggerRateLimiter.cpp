// refer to https://leetcode.com/problems/logger-rate-limiter/discuss/83273
class Logger {
public:
    unordered_map<string, int> done;
    
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (done.count(message) == 0) {
            done[message] = timestamp + 10;
            return true;
        }

        if (timestamp >= done[message]) {
            done[message] = timestamp + 10;
            return true;
        }
        else return false;            
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
