/*
 * @lc app=leetcode id=1348 lang=cpp
 *
 * [1348] Tweet Counts Per Frequency
 */

// @lc code=start
class TweetCounts {
private:
    // A map to store the occurence of the tweet
    // Observation: the times in the vector will be sorted 
    unordered_map<string, vector<int>> m;
    unordered_map<string, int> inter{{"minute", 60}, {"hour", 3600}, {"day", 86400}};
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        // Push the time to the tweetName
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> res;
        int interval = inter[freq];

        // Initialize the res with 0s
        for(int i = 0; i <= (endTime - startTime) / interval; i ++)
            res.push_back(0);

        // Count the frequency
        auto &times = m[tweetName];
        for(int time : times) {
            if(time >= startTime && time <= endTime) {
                int index = (time - startTime) / interval;
                res[index] ++;
            }
        }

        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
// @lc code=end

