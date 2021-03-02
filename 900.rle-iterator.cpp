/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 */

// @lc code=start
class RLEIterator {
public:
    vector<int> seq;
    int curIdx = 0;
    int len;
    RLEIterator(vector<int>& A) {
        seq = A;
        len = seq.size();
    }
    
    int next(int n) {
        while(curIdx < len && seq[curIdx] < n) {
            n -= seq[curIdx];
            curIdx += 2;
        }

        if(curIdx >= len)
            return -1;

        seq[curIdx] -= n;
        return seq[curIdx+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
// @lc code=end

