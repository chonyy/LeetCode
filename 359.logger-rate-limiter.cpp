/*
 * @lc app=leetcode id=359 lang=cpp
 *
 * [359] Logger Rate Limiter
 */

// @lc code=start
class Logger {
private:
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        // Never seen 
        if(m.count(message) == 0) {
            m[message] = timestamp + 10;
            return true;
        }
        else { //Seen
            if(timestamp < m[message])
                return false;
            else {
                m[message] = timestamp + 10;
                return true;
            }
        }
        // This will never be run
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
// @lc code=end

