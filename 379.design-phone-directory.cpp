/*
 * @lc app=leetcode id=379 lang=cpp
 *
 * [379] Design Phone Directory
 */

// @lc code=start
class PhoneDirectory {
public:
    vector<int> next;
    int pos;
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        next = vector<int>(maxNumbers);
        for(int i = 0; i < maxNumbers; i ++) {
            next[i] = (i+1) % maxNumbers;
        }
        pos = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(next[pos] == -1)
            return -1;
        int ret = pos;
        pos = next[pos];
        next[ret] = -1;
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return next[number] != -1;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(next[number] != -1)
            return;

        next[number] = pos;
        pos = number;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
// @lc code=end

