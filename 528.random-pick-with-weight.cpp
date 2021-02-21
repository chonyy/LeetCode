/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
    vector<int> weights;
public:
    Solution(vector<int>& w) {
        for(int ww : w) {
            if(weights.empty()) {
                weights.push_back(ww);
            }
            else {
                weights.push_back(ww + weights.back());
            }
        }
    }
    
    int pickIndex() {
        int weightSum = weights.back();
        int toFind = rand() % weightSum;
        auto it = upper_bound(weights.begin(), weights.end(), toFind);
        return it - weights.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

