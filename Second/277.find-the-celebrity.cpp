/*
 * @lc app=leetcode id=277 lang=cpp
 *
 * [277] Find the Celebrity
 */

// @lc code=start
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for(int i = 1; i < n; i ++) {
            if(knows(candidate, i)) {
                candidate = i;
            }
        }

        for(int i = 0; i < n; i ++) {
            if(i > candidate && !knows(i, candidate))
                return -1;
            if(i < candidate && (!knows(i, candidate) || knows(candidate, i)))
                return -1;
        }

        return candidate;
    }
};
// @lc code=end

