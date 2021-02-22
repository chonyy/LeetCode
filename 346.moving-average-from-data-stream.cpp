/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 */

// @lc code=start
class MovingAverage {
    queue<int> q;
    int _size;
    int sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if(q.size() > _size) {
            sum -= q.front();
            q.pop();
        }
        return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end

