/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 */

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        int count = 0;
        int n = start.size();

        for(int i = 0; i < n ; i ++) {
            if(start[i] != 'X')
                count ++;
            if(end[i] != 'X')
                count --;
        }   
        if(count != 0)
            return false;

        int i = 0, j = 0;
        while(i < n && j < n) {
            while(start[i] == 'X')
                i ++;
            while(end[j] == 'X')
                j ++;

            char cs = start[i];
            char ce = end[j];

            if(cs != ce)
                return false;
            if(cs == 'R' && j < i)
                return false;
            if(cs == 'L' && j > i)
                return false;

            i ++;
            j ++;
        }

        return true;
    }
};
// @lc code=end
